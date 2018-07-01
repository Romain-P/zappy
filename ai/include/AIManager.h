//
// Created by romain on 22/06/18.
//

#ifndef ZAPPY_AIMANAGER_H
#define ZAPPY_AIMANAGER_H


#include <unordered_map>
#include <memory>
#include "zappy_network.h"
#include "AIPlayer.h"

using players_t = std::unordered_map<session_t, std::unique_ptr<AIPlayer>>;

class AIManager {
public:

    bool mustFork();
    bool everyoneAreReadyToCast() const;
    bool noneReadyToCast() const;
    bool teamIsFull() const;
    void onCastingFailed();
    void alertReadyForCast(AIPlayer &player);
    void leaveItemsForCast(AIPlayer &player);
    void broadcastSync();

    objects_t neededObjects(size_t custom = 0);

    std::string &getTeamName();
    AIPlayer &getPlayer(session_t id);
    players_t &getPlayers();
    size_t &getFreePlaces();
    size_t &getLevel();

private:
    static const objects_t levels[];

    players_t _players;
    std::string _teamName;
    size_t _freePlaces = 0;
    size_t _level = 1;
    size_t _forks = 0;
    bool _ask = true;
    objects_t _currentElevation;
    ssize_t _broadcast;
};


#endif //ZAPPY_AIMANAGER_H
