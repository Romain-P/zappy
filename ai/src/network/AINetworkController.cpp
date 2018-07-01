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
        if (manager.getPlayers().empty())
            exit(0);
    }

    void onWelcome(session_t id, packet_welcome_t *msg) {
        AIPlayer &player = manager.getPlayer(id);
        player.getNetworkState() = AINetworkClient::AWAIT_REMAINING_PLAYERS;
        send_unwrapped(id, &manager.getTeamName()[0]);
    }

    void onLookReply(session_t id, std::string &data) {
        AIPlayer &player = manager.getPlayer(id);
        cells_t cells = data::deserializeCells(std::move(data));
        player.getLooked() = cells_t(std::move(cells));
        player.getAI().onSuccess(LOOK);
    }

    void onBroadcast(session_t id, packet_message_t *msg) {
        AIPlayer &player = manager.getPlayer(id);
        if (!strcmp(msg->text, manager.getTeamName().c_str()) && !player.gotPendingTasks()) {
            player.getLastSoundSource() = static_cast<SoundSource>(msg->tile);

            player.getAI().onSuccess(BROADCAST);
        }
    }

    void onConnectNumberReply(session_t id, uint32_t value) {
        AIPlayer &player = manager.getPlayer(id);
        //manager.getFreePlaces() = value;
        //ignored
        //old implementation
        player.getAI().onSuccess(CONNECT_NUMBER);
    }

    void onInventoryReply(session_t id, std::string &data) {
        AIPlayer &player = manager.getPlayer(id);
        objects_t inventory = data::deserializeInventory(std::move(data));
        player.updateItems(std::move(inventory));
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

    void onActionReply(AIPlayer &player, session_t id, char **packet) {
        static std::unordered_map<std::string, void (*)(AIPlayer &, char **)> const REPLIES {
                { "ok", &onSuccess },
                { "ko", &onFailure },
                { "Elevation", &onCasting },
                { "Current", &onCastingSuccess }
        };

        if (REPLIES.find(packet[0]) != REPLIES.end())
            REPLIES.at(packet[0])(player, packet);
        else if (player.gotPendingTasks()) {
            AIAction action = player.popPending();
            std::string concat = data::concatenateUnwrapped(packet);

            switch (action) {
                case INVENTORY:
                    onInventoryReply(id, concat);
                    break;
                case CONNECT_NUMBER:
                    onConnectNumberReply(id, atoi(&concat[0]));
                    break;
                case LOOK:
                    onLookReply(id, concat);
                    break;
                default : break;
            }
        } else
            std::cerr << "unknown unwrapped command: key=" << packet[0] << std::endl;
    }

    void onUnwrapped(session_t id, char **packet) {
        AIPlayer &player = manager.getPlayer(id);

        switch (player.getNetworkState()) {
            case AINetworkClient::AWAIT_REMAINING_PLAYERS:
                {
                    size_t size = manager.getPlayers().size();

                    for (size_t i = 0; i < data::PLAYERS_FOR_WIN - size; ++i)
                        zappy_new_connection();
                }
                player.getNetworkState() = AIPlayer::AWAIT_MAP_SIZE;
                break;
            case AINetworkClient::AWAIT_MAP_SIZE:
                player.getNetworkState() = AINetworkClient::READY;
                player.readyToBroadcast() = true;
                player.getAI().onSuccess(NONE);
                break;
            default:
                onActionReply(player, id, packet);
                break;
        }
    }
}