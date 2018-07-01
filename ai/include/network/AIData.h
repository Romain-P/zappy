//
// Created by romain on 24/06/18.
//

#ifndef ZAPPY_MAPTYPE_H
#define ZAPPY_MAPTYPE_H


#include <string>
#include <unordered_map>
#include <vector>
#include "Types.h"

namespace data {

    constexpr char DELIMITER_INVENTORY_ITEM = ',';
    constexpr char DELIMITER_INVENTORY_ITEM_COUNT = ' ';
    constexpr char DELIMITER_CELL = ',';
    constexpr char DELIMITER_CELL_OBJECT = ' ';
    constexpr size_t PLAYER_MAX_LEVEL = 8;
    constexpr size_t PLAYERS_FOR_WIN = 6;

    objects_t deserializeInventory(std::string &&serialized);
    cells_t deserializeCells(std::string &&serialized);

    char const *serialize(ObjectType type);
    ObjectType deserialize(std::string const &type);

    vision_t const &getVisionRange();
    std::string concatenateUnwrapped(char **unwrapped);
}

#endif //ZAPPY_MAPTYPE_H
