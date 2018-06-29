//
// Created by romain on 24/06/18.
//

#include <network/AIData.h>
#include "AbstractAI.h"
#include "AIPlayer.h"
#include "AIManager.h"

void AbstractAI::takeObject(ObjectType type, size_t count) {
    for (size_t i = 0; i < count; ++i)
        _player->request(TAKE, data::serialize(type));
}

void AbstractAI::leaveObject(ObjectType type, size_t count) {
    for (size_t i = 0; i < count; ++i)
        _player->request(LEAVE, data::serialize(type));
}

void AbstractAI::gotoTeamEmitter() {
    switch(_player->getLastSoundSource()) {
        case DIR_TOP_LEFT:
            _player->request(MOVE_FORWARD);
            _player->request(MOVE_LEFT);
            _player->request(MOVE_FORWARD);
            break;
        case DIR_TOP_RIGHT:
            _player->request(MOVE_FORWARD);
            _player->request(MOVE_RIGHT);
        case DIR_TOP:
            _player->request(MOVE_FORWARD);
            break;
        case DIR_RIGHT:
            _player->request(MOVE_RIGHT);
            _player->request(MOVE_FORWARD);
            break;
        case DIR_LEFT:
            _player->request(MOVE_LEFT);
            _player->request(MOVE_FORWARD);
            break;
        case DIR_BOTTOM_LEFT:
            _player->request(MOVE_LEFT);
            _player->request(MOVE_FORWARD);
            _player->request(MOVE_LEFT);
            _player->request(MOVE_FORWARD);
            break;
        case DIR_BOTTOM_RIGHT:
            _player->request(MOVE_RIGHT);
            _player->request(MOVE_FORWARD);
            _player->request(MOVE_RIGHT);
            _player->request(MOVE_FORWARD);
            break;
        case DIR_BOTTOM:
            _player->request(MOVE_RIGHT);
            _player->request(MOVE_RIGHT);
            _player->request(MOVE_FORWARD);
            break;
        default:
            break;
    }
}

void AbstractAI::moveToTile(size_t tileId) {
    vision_t const &vision = data::getVisionRange();

    size_t forward = 0;
    ssize_t right = 0;

    for (size_t line = 0; line < vision.size(); ++line) {
        VisionLine current = vision.at(line);

        if (tileId >= current.min && tileId <= current.max) {
            forward += line;
            right += tileId - current.middle;
        }
    }

    for (size_t i = 0; i < forward; ++i)
        _player->request(MOVE_FORWARD);
    if (right > 0)
        _player->request(MOVE_RIGHT);
    else if (right < 0)
        _player->request(MOVE_LEFT);
    for (size_t i = 0; i < std::abs(right); ++i)
        _player->request(MOVE_FORWARD);
}