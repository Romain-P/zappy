//
// Created by romain on 23/06/18.
//

#ifndef ZAPPY_AIPLAYER_H
#define ZAPPY_AIPLAYER_H


#include <string>
#include "zappy_network.h"
#include "AINetworkClient.h"

class AIPlayer: public AINetworkClient {
public:
    explicit AIPlayer(session_t id) : AINetworkClient(id) {}

    enum State {
        READY_TO_CAST,
        WORKING
    };

    State &getState();
    size_t &getLevel();

private:
    State _state = WORKING;
    size_t _level = 1;
};


#endif //ZAPPY_AIPLAYER_H
