//
// Created by romain on 22/06/18.
//

#ifndef ZAPPY_AICONTROLLER_H
#define ZAPPY_AICONTROLLER_H


#include "zappy_network.h"
#include "AIManager.h"

namespace AIController {

    extern AIManager manager;

    void on_connect(session_t id);
    void on_disconnect(session_t id);
    void on_welcome(session_t id, packet_welcome_t *);
    void on_look_reply(session_t, packet_look_t *);
    void on_message_reply(session_t, packet_message_t *);
    void on_connect_nummber_reply(session_t, packet_connect_number_t *);
    void on_inventory_reply(session_t, packet_inventory_t *);
    void on_unwrapped(session_t id, char **packet);
};


#endif //ZAPPY_AICONTROLLER_H
