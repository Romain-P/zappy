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

    static constexpr size_t MIN_FOOD = 10;
    static constexpr size_t ACTIONS_COUNT_BEFORE_INVENTORY = 10;

    size_t _actionsBeforeCheckFood = 0;

    void defaultRotation();
    bool enoughResourcesForCast();
    bool mustFork();
    bool moveAndDropItem();
    size_t neededFood();
    void updateInventory();
    ItemTarget findNearestInterestingCell(objects_t &needed, cells_t &cells);
};


#endif //ZAPPY_BASICAI_H
