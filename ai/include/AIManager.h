//
// Created by romain on 22/06/18.
//

#ifndef ZAPPY_AIMANAGER_H
#define ZAPPY_AIMANAGER_H


#include <unordered_map>
#include <memory>
#include <bits/unordered_map.h>
#include "zappy_network.h"
#include "AIPlayer.h"
#include "GameMap.h"

using players_t = std::unordered_map<session_t, std::unique_ptr<AIPlayer>>;

class AIManager {
public:
    void generateMap(size_t width, size_t height);

    std::string &getTeam();
    AIPlayer &getPlayer(session_t id);
    players_t &getPlayers();
    size_t &getMaxPlayers();
private:

    std::unique_ptr<GameMap> _map;
    players_t _players;
    std::string _team;
    size_t _maxplayers;
};


#endif //ZAPPY_AIMANAGER_H
