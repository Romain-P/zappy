//
// Created by romain on 22/06/18.
//

#ifndef ZAPPY_AICONTROLLER_H
#define ZAPPY_AICONTROLLER_H


#include "zappy_network.h"
#include <string>
#include <AIPlayer.h>

class AIManager;

namespace AINetworkController {

    extern AIManager manager;

    void onConnect(session_t id);
    void onDisconnect(session_t id);
    void onWelcome(session_t id, packet_welcome_t *);
    void onLookReply(session_t, std::string &data);
    void onBroadcast(session_t, packet_message_t *);
    void onConnectNumberReply(session_t, uint32_t value);
    void onInventoryReply(session_t, std::string &data);
    void onUnwrapped(session_t id, char **packet);
};


#endif //ZAPPY_AICONTROLLER_H
