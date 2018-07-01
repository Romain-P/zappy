//
// Created by romain on 22/06/18.
//

#include <chrono>
#include <network/AIData.h>
#include "AIManager.h"

objects_t const AIManager::levels[] = {
        objects_t({{LINEMATE, 1}, {DERAUMERE, 0}, {SIBUR, 0}, {MENDIANE, 0}, {PHIRAS, 0}, {THYSTAME, 0}}),
        objects_t({{LINEMATE, 1}, {DERAUMERE, 1}, {SIBUR, 1}, {MENDIANE, 0}, {PHIRAS, 0}, {THYSTAME, 0}}),
        objects_t({{LINEMATE, 2}, {DERAUMERE, 0}, {SIBUR, 1}, {MENDIANE, 0}, {PHIRAS, 2}, {THYSTAME, 0}}),
        objects_t({{LINEMATE, 1}, {DERAUMERE, 1}, {SIBUR, 2}, {MENDIANE, 0}, {PHIRAS, 1}, {THYSTAME, 0}}),
        objects_t({{LINEMATE, 1}, {DERAUMERE, 2}, {SIBUR, 1}, {MENDIANE, 3}, {PHIRAS, 0}, {THYSTAME, 0}}),
        objects_t({{LINEMATE, 1}, {DERAUMERE, 2}, {SIBUR, 3}, {MENDIANE, 0}, {PHIRAS, 1}, {THYSTAME, 0}}),
        objects_t({{LINEMATE, 2}, {DERAUMERE, 2}, {SIBUR, 2}, {MENDIANE, 2}, {PHIRAS, 2}, {THYSTAME, 1}}),
};

AIPlayer &AIManager::getPlayer(session_t id) {
    return *_players.at(id);
}

players_t &AIManager::getPlayers() {
    return _players;
}

std::string &AIManager::getTeamName() {
    return _teamName;
}

size_t &AIManager::getFreePlaces() {
    return _freePlaces;
}

bool AIManager::everyoneAreReadyToCast() const {
    bool ready = true;

    for (auto &keyset: _players) {
        auto &player = keyset.second;
        if (player->getState() != AIPlayer::CASTER_READY &&
                player->getState() != AIPlayer::READY_TO_LEAVE_ITEMS &&
                player->getState() != AIPlayer::READY_TO_CAST) {
            ready = false;
            break;
        }
    }

    return ready;
}

bool AIManager::noneReadyToCast() const {
    bool noneCasting = true;

    for (auto &keyset: _players) {
        auto &player = keyset.second;
        if (player->getState() == AIPlayer::READY_TO_CAST) {
            noneCasting = false;
            break;
        }
    }

    return noneCasting;
}

void AIManager::onCastingFailed() {
    for (auto &keyset: _players) {
        auto &p = keyset.second;

        p->getState() = AIPlayer::WORKING;
        p->getAI().onFailure(CAST);
    }
}

objects_t AIManager::neededObjects(size_t custom) {
    size_t level = !custom ? _level : custom;
    objects_t needed(levels[level - 1]);
    objects_t cleared;

    if (true)
        return cleared;
    for (auto &pair: _players) {
        auto &player = pair.second;

        for (auto &keyset: player->getObjects()) {
            ObjectType type = keyset.first;
            size_t count = keyset.second;

            if (type == FOOD) continue;

            size_t &neededCount = needed.at(type);
            if (neededCount > 0)
                neededCount -= count > neededCount ? neededCount : count;
            if (neededCount > 0)
                cleared[type] = neededCount;
            else if (cleared.find(type) != cleared.end())
                cleared.erase(type);
        }
    }
    if (!teamIsFull() && cleared.empty() && level < data::PLAYER_MAX_LEVEL)
        return neededObjects(level + 1);
    return cleared;
}

size_t &AIManager::getLevel() {
    return _level;
}

bool AIManager::mustFork() {
    if (_forks < data::PLAYERS_FOR_WIN) {
        _forks++;
        return true;
    }
    return false;
}

void AIManager::alertReadyForCast(AIPlayer &caster) {
    for (auto &keyset: _players) {
        auto &player = keyset.second;
        player->abortTasks();
        player->getState() = AIPlayer::MOVING_TO_CASTER;
    }
    caster.getState() = AIPlayer::CASTER_READY;
    _currentElevation = objects_t(levels[_level - 1]);
}

void AIManager::leaveItemsForCast(AIPlayer &player) {
    for (auto &keyset: _currentElevation) {
        ObjectType needed = keyset.first;
        size_t count = keyset.second;
        size_t playerCount = player.getObjects().at(needed);

        if (playerCount > count)
            playerCount = count;

        if (playerCount > 0) {
            std::string serialized = data::serialize(needed);

            for (size_t i = 0; i < playerCount; ++i)
                player.request(LEAVE, serialized);
            player.delItem(needed, playerCount);
        }
    }
}

bool AIManager::teamIsFull() const {
    for (auto &keyset: _players) {
        auto &player = keyset.second;
        if (player->getNetworkState() != AIPlayer::READY)
            return false;
    }
    return true;
}

void AIManager::broadcastSync() {
    bool rdy = true;
    AIPlayer *caster = nullptr;

    for (auto &keyset: _players) {
        auto &p = keyset.second;

        if (p->getNetworkState() == AIPlayer::READY && p->getState() != AIPlayer::CASTER_READY
            && !p->readyToBroadcast()) {
            rdy = false;
        }
        if (p->getState() == AIPlayer::CASTER_READY)
            caster = p.get();
    }
    if (rdy && caster) {
        caster->request(BROADCAST, _teamName);
        for (auto &keyset: _players) {
            keyset.second->readyToBroadcast() = false;
        }
    }
}
