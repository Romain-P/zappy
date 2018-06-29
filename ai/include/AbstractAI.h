//
// Created by romain on 24/06/18.
//

#ifndef ZAPPY_ABSTRACTAI_H
#define ZAPPY_ABSTRACTAI_H

#include "Types.h"
#include <functional>
#include <tuple>

class AIPlayer;
class AIManager;

class AbstractAI {
public:
    explicit AbstractAI(AIPlayer &player, AIManager &manager) : _player(&player), _manager(&manager) {};

    virtual void onSuccess(AIAction action) = 0;
    virtual void onFailure(AIAction action) = 0;

protected:

    void takeObject(ObjectType type, size_t count = 1);
    void leaveObject(ObjectType type, size_t count = 1);
    void gotoTeamEmitter();
    void moveToTile(size_t tileId);

    AIPlayer *_player;
    AIManager *_manager;
};


#endif //ZAPPY_ABSTRACTAI_H
