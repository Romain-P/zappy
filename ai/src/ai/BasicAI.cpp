//
// Created by romain on 25/06/18.
//

#include <network/AINetworkController.h>
#include "AIManager.h"
#include "BasicAI.h"

BasicAI::BasicAI(AIPlayer &player) : AbstractAI(player, AINetworkController::manager) {}

void BasicAI::onSuccess(AIAction action) {
    if (mustFork()) return;
    if (enoughResourcesForCast()) return;

    switch (action) {
        case LOOK:
            if (moveAndDropItem()) break;
            _player->request(MOVE_FORWARD);
            _player->request(LOOK);
            break;
        case TAKE:
        case LEAVE:
            _player->request(INVENTORY);
            _actionsBeforeCheckFood = 0;
            break;
        case MOVE_FORWARD:
        case MOVE_RIGHT:
        case MOVE_LEFT:
            updateInventory();
        default:
            defaultRotation();
            break;
    }

    if (_manager->askRemainingConnections())
        _player->request(CONNECT_NUMBER);
}

void BasicAI::onFailure(AIAction action) {
    if (enoughResourcesForCast()) return;

    switch (action) {
        default:
            defaultRotation();
            break;
    }
}

void BasicAI::defaultRotation() {
    _player->request(LOOK);
}

bool BasicAI::moveAndDropItem() {
    objects_t needed;

    if (neededFood() > 0)
        needed[FOOD] = neededFood();
    else
        needed = _manager->neededObjects();

    ItemTarget target = findNearestInterestingCell(needed, _player->getLooked());
    if (target.type == UNDEFINED)
        return false;

    moveToTile(target.tileId);
    takeObject(target.type, target.count);
    return true;
}

BasicAI::ItemTarget BasicAI::findNearestInterestingCell(objects_t &needed, cells_t &cells) {
    BasicAI::ItemTarget target = {UNDEFINED, 0, 0};
    size_t tiles = cells.size();

    for (size_t tileId = 0; tileId < tiles; ++tileId) {
        objects_t &items = cells.at(tileId);

        for (auto &keyset: needed) {
            ObjectType type = keyset.first;
            size_t neededCount = keyset.second;

            if (items.find(type) != items.end()) {
                target.type = type;
                target.count = items.at(type);
                if (target.count > neededCount)
                    target.count = neededCount;
                target.tileId = tileId;
                return target;
            }
        }
    }
    return target;
}

bool BasicAI::mustFork() {
    if (_manager->mustFork()) {
        _player->request(FORK);
        _player->request(MOVE_FORWARD);
        return true;
    }
    return false;
}

size_t BasicAI::neededFood() {
    return MIN_FOOD - _player->getObjects().at(FOOD);
}

void BasicAI::updateInventory() {
    if (_actionsBeforeCheckFood < ACTIONS_COUNT_BEFORE_INVENTORY)
        _actionsBeforeCheckFood++;
    else {
        _player->request(INVENTORY);
        _actionsBeforeCheckFood = ACTIONS_COUNT_BEFORE_INVENTORY;
    }
}

bool BasicAI::enoughResourcesForCast() {
    if (!_manager->neededObjects().empty() || _player->getState() != AIPlayer::WORKING) return false;

    if (_player->getState() == AIPlayer::CASTING)
        return true;

    if (_player->getState() == AIPlayer::WORKING)
        _manager->alertReadyForCast(*_player);
    if (_player->getState() == AIPlayer::CASTER_READY) {
        if (!_manager->everyoneAreReadyToCast())
            _player->request(BROADCAST, _manager->getTeamName());
        else {
            _manager->leaveItemsForCast(*_player);
            _player->request(CAST);
        }
    }
    else if (_player->getLastSoundSource() != ON_CELL)
        gotoTeamEmitter();
    else if (_player->getState() != AIPlayer::READY_TO_LEAVE_ITEMS && _player->getState() != AIPlayer::READY_TO_CAST)
        _player->getState() = AIPlayer::READY_TO_LEAVE_ITEMS;
    else if (_manager->everyoneAreReadyToCast() && _player->getState() == AIPlayer::READY_TO_LEAVE_ITEMS) {
        _manager->leaveItemsForCast(*_player);
        _player->getState() = AIPlayer::READY_TO_CAST;
    }
    return true;
}