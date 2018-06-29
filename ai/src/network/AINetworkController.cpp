//
// Created by romain on 22/06/18.
//

#include <iostream>
#include <cstring>
#include <network/AIData.h>
#include "network/AINetworkController.h"
#include "AIManager.h"


namespace AINetworkController {
    AIManager manager;

    void onConnect(session_t id) {
        manager.getPlayers()[id] = std::make_unique<AIPlayer>(id);
    }

    void onDisconnect(session_t id) {
        manager.getPlayers().erase(id);
    }

    void onWelcome(session_t id, packet_welcome_t *msg) {
        AIPlayer &player = manager.getPlayer(id);
        player.getNetworkState() = AINetworkClient::AWAIT_REMAINING_PLAYERS;
        send_unwrapped(id, &manager.getTeamName()[0]);
    }

    void onLookReply(session_t id, packet_look_t *msg) {
        AIPlayer &player = manager.getPlayer(id);
        cells_t cells = data::deserializeCells(msg->data);
        player.popPending();
        player.getLooked() = cells_t(std::move(cells));
        player.getAI().onSuccess(LOOK);
    }

    void onBroadcast(session_t id, packet_message_t *msg) {
        AIPlayer &player = manager.getPlayer(id);
        if (!strcmp(msg->text, manager.getTeamName().c_str()))
            player.getLastSoundSource() = static_cast<SoundSource>(msg->tile);
    }

    void onConnectNumberReply(session_t id, packet_connect_number_t *msg) {
        AIPlayer &player = manager.getPlayer(id);
        manager.getFreePlaces() = msg->value;
        player.popPending();

        for (size_t i = 0; i < manager.getFreePlaces(); ++i)
            zappy_new_connection();
        player.getAI().onSuccess(CONNECT_NUMBER);
    }

    void onInventoryReply(session_t id, packet_inventory_t *msg) {
        AIPlayer &player = manager.getPlayer(id);
        objects_t inventory = data::deserializeInventory(std::string(msg->result));
        player.updateItems(std::move(inventory));
        player.popPending();
        player.getAI().onSuccess(INVENTORY);
    }

    void onSuccess(AIPlayer &player, char **data) {
        AIAction popped = player.popPending();
        player.getAI().onSuccess(popped);
    }

    void onFailure(AIPlayer &player, char **data) {
        AIAction popped = player.popPending();

        if (popped == CAST && player.getState() == AIPlayer::CASTING)
            manager.onCastingFailed();
        else
            player.getAI().onFailure(popped);
    }

    void onCasting(AIPlayer &player, char **data) {
        player.getState() = AIPlayer::CASTING;
    }

    void onCastingSuccess(AIPlayer &player, char **data) {
        manager.getLevel() = static_cast<size_t>(atoi(data[2]));
        player.getState() = AIPlayer::WORKING;
        player.getAI().onSuccess(CAST);
    }

    void onUnwrapped(session_t id, char **packet) {
        static std::unordered_map<std::string, void (*)(AIPlayer &, char **)> const REPLIES {
                { "ok", &onSuccess },
                { "ko", &onFailure },
                { "Elevation", &onCasting },
                { "Current", &onCastingSuccess }
        };

        AIPlayer &player = manager.getPlayer(id);

        switch (player.getNetworkState()) {
            case AINetworkClient::AWAIT_REMAINING_PLAYERS:
                manager.getFreePlaces() = static_cast<size_t>(atoi(packet[0]));
                player.getNetworkState() = AIPlayer::AWAIT_MAP_SIZE;
                break;
            case AINetworkClient::AWAIT_MAP_SIZE:
                player.getNetworkState() = AINetworkClient::READY;
                player.getState() = AIPlayer::WORKING;
                break;
            default:
                if (REPLIES.find(packet[0]) != REPLIES.end())
                    REPLIES.at(packet[0])(player, packet);
                else
                    std::cerr << "unknown unwrapped command: key=" << packet[0] << std::endl;
                break;
        }
    }
}