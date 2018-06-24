//
// Created by romain on 23/06/18.
//

#include "AIPlayer.h"
#include "zappy_network.h"

AIPlayer::State &AIPlayer::getState() {
    return _state;
}

size_t &AIPlayer::getLevel() {
    return _level;
}
