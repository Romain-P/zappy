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

using players_t = std::unordered_map<session_t, std::unique_ptr<AIPlayer>>;

class AIManager {
public:

    std::string &getTeam();
    AIPlayer &getPlayer(session_t id);
    players_t &getPlayers();
private:

    players_t _players;
    std::string _team;
};


#endif //ZAPPY_AIMANAGER_H
