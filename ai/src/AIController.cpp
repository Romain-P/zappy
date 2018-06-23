//
// Created by romain on 22/06/18.
//

#include <AINetworkCommands.h>
#include "AIController.h"

using namespace AINetworkCommands;

namespace AIController {
    AIManager manager;

    void on_connect(session_t id) {

    }

    void on_disconnect(session_t id) {

    }

    void on_welcome(session_t id, packet_welcome_t *msg) {
       sendTeamName(id, manager.getTeam());
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

    }
}