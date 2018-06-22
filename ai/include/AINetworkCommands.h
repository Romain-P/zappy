//
// Created by romain on 22/06/18.
//

#ifndef ZAPPY_AICOMMANDS_H
#define ZAPPY_AICOMMANDS_H


#include <zappy_network.h>
#include <string>

namespace AINetworkCommands {
    void requestMoveForward(session_t client);
    void requestMoveLeft(session_t client);
    void requestMoveRight(session_t client);
    void requestFork(session_t client);
    void requestLook(session_t client);
    void requestInventory(session_t client);
    void requestBroadcast(session_t client, std::string text);
    void requestRemainingConnections(session_t client);
    void requestEject(session_t client);
    void requestTakeObject(session_t client, std::string object);
    void requestLeaveObject(session_t client, std::string object);
    void requestIncantation(session_t client);
};


#endif //ZAPPY_AICOMMANDS_H
