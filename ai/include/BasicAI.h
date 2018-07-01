//
// Created by romain on 25/06/18.
//

#ifndef ZAPPY_BASICAI_H
#define ZAPPY_BASICAI_H

#include "AbstractAI.h"

class BasicAI : public AbstractAI {
public:

    explicit BasicAI(AIPlayer &player);

    void onSuccess(AIAction action) override;
    void onFailure(AIAction action) override;

    struct ItemTarget {
        ObjectType type;
        size_t count;
        size_t tileId;
    };

private:

    static constexpr size_t MIN_FOOD = 0;

    void defaultRotation();
    bool enoughResourcesForCast(AIAction action);
    bool mustFork();
    bool moveAndDropItem();
    size_t neededFood();
    ItemTarget findNearestInterestingCell(objects_t &needed, cells_t &cells);
};


#endif //ZAPPY_BASICAI_H
