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

void AIManager::generateMap(size_t width, size_t height) {
    _map = std::make_unique<GameMap>(width, height);
}