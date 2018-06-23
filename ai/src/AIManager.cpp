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
