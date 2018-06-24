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
        AWAIT_FOR_CAST,

    };


private:
    State _state;
};


#endif //ZAPPY_AIPLAYER_H
