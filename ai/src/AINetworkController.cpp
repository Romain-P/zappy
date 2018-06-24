//
// Created by romain on 22/06/18.
//

#include <iostream>
#include <cstring>
#include "AINetworkController.h"


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
        player.getNetworkState() = AIPlayer::AWAIT_REMAINING_PLAYERS;
        player.sendTeamName(manager.getTeam());
    }

    void onLookReply(session_t, packet_look_t *msg) {

    }

    void onBroadcast(session_t, packet_message_t *msg) {

    }

    void onConnectNumberReply(session_t, packet_connect_number_t *msg) {

    }

    void onInventoryReply(session_t, packet_inventory_t *msg) {

    }

    void onSuccess(AIPlayer &player, char **data) {

    }

    void onFailure(AIPlayer &player, char **data) {

    }

    void onCasting(AIPlayer &player, char **data) {

    }

    void onCastingEnd(AIPlayer &player, char **data) {
        player.getLevel() = static_cast<size_t>(atoi(data[2]));
    }

    void onUnwrapped(session_t id, char **packet) {
        static std::unordered_map<std::string, void (*)(AIPlayer &, char **)> const REPLIES {
                { "ok", &onSuccess },
                { "ko", &onFailure },
                { "Elevation", &onCasting },
                { "Current", &onCastingEnd }
        };

        AIPlayer &player = manager.getPlayer(id);

        switch (player.getNetworkState()) {
            case AIPlayer::AWAIT_REMAINING_PLAYERS:
                manager.getMaxPlayers() = static_cast<size_t>(atoi(packet[0]));
                player.getNetworkState() = AIPlayer::AWAIT_MAP_SIZE;
                break;
            case AIPlayer::AWAIT_MAP_SIZE:
                //unused dimensions, rip epitech, retarded project makers
                //ofc im #salty
                player.getNetworkState() = AIPlayer::READY;
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