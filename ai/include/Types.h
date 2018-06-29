//
// Created by romain on 24/06/18.
//

#ifndef ZAPPY_OBJECTTYPES_H
#define ZAPPY_OBJECTTYPES_H

#include <vector>
#include <unordered_map>
#include <ctime>
#include <chrono>

enum ObjectType {
    PLAYER = 0,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    FOOD,
    UNDEFINED
};

enum AIAction {
    MOVE_FORWARD = 0,
    MOVE_LEFT,
    MOVE_RIGHT,
    FORK,
    LOOK,
    INVENTORY,
    BROADCAST,
    CONNECT_NUMBER,
    EJECT,
    TAKE,
    LEAVE,
    CAST
};

enum SoundSource {
    ON_CELL = 0,
    DIR_TOP,
    DIR_TOP_LEFT,
    DIR_LEFT,
    DIR_BOTTOM_LEFT,
    DIR_BOTTOM,
    DIR_BOTTOM_RIGHT,
    DIR_RIGHT,
    DIR_TOP_RIGHT
};

struct VisionLine {
    size_t min;
    size_t max;
    size_t middle;
};

using count_t = size_t;
using objects_t = std::unordered_map<ObjectType, count_t>;
using cells_t = std::vector<objects_t>;
using vision_t = std::vector<VisionLine>;

#endif //ZAPPY_OBJECTTYPES_H
