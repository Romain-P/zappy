//
// Created by romain on 23/06/18.
//

#include "AIPlayer.h"
#include "zappy_network.h"

AIPlayer::State &AIPlayer::getState() {
    return _state;
}

void AIPlayer::addItem(ObjectType type, size_t count) {
    _inventory[type] += count;
}

void AIPlayer::updateItems(objects_t &&items) {
    _inventory = objects_t(items);
}

objects_t const &AIPlayer::getObjects() const {
    return _inventory;
}

AbstractAI &AIPlayer::getAI() {
    return *_ai;
}

void AIPlayer::delItem(ObjectType type, size_t count) {
    _inventory[type] -= count;
}

cells_t &AIPlayer::getLooked() {
    return _looked;
}

SoundSource &AIPlayer::getLastSoundSource() {
    return _lastSource;
}
