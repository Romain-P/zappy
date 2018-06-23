//
// Created by romain on 22/06/18.
//

#include <iostream>
#include "AIController.h"


namespace AIController {
    AIManager manager;

    void on_connect(session_t id) {
        manager.getPlayers()[id] = std::make_unique<AIPlayer>(id);
    }

    void on_disconnect(session_t id) {
        manager.getPlayers().erase(id);
    }

    void on_welcome(session_t id, packet_welcome_t *msg) {
        AIPlayer &player = manager.getPlayer(id);
        player.getState() = AIPlayer::AWAIT_REMAINING_PLAYERS;
        player.sendTeamName(manager.getTeam());
    }

    void on_look_reply(session_t, packet_look_t *msg) {

    }

    void on_message_reply(session_t, packet_message_t *msg) {

    }

    void on_connect_nummber_reply(session_t, packet_connect_number_t *msg) {

    }

    void on_inventory_reply(session_t, packet_inventory_t *msg) {

    }

    void on_unwrapped(session_t id, char **packet) {
        AIPlayer &player = manager.getPlayer(id);
        switch (player.getState()) {
            case AIPlayer::AWAIT_REMAINING_PLAYERS:
                manager.getMaxPlayers() = static_cast<size_t>(atoi(packet[0]));
                break;
            case AIPlayer::AWAIT_MAP_SIZE:
                auto width = static_cast<size_t>(atoi(packet[0]));
                auto height = static_cast<size_t>(atoi(packet[1]));

                manager.generateMap(width, height);
                break;
            default:
                std::cerr << "Received non-handled unwrapped packet: key=" << packet[0] << std::endl;
                break;
        }
    }
}