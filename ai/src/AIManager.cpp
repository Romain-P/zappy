//
// Created by romain on 22/06/18.
//

#include "AIManager.h"

AIPlayer &AIManager::getPlayer(session_t id) {
    return *_players.at(id);
}

players_t &AIManager::getPlayers() {
    return _players;
}

std::string &AIManager::getTeam() {
    return _team;
}

size_t &AIManager::getMaxPlayers() {
    return _maxplayers;
}

bool AIManager::everyoneReadyToCast() {
    bool ready = true;

    for (auto &keyset: _players) {
        auto &player = keyset.second;
        if (player->getState() != AIPlayer::READY_TO_CAST) {
            ready = false;
            break;
        }
    }

    return ready;
}
