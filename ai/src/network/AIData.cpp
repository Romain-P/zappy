//
// Created by romain on 24/06/18.
//

#include <cstring>
#include "network/AIData.h"
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

namespace data {
    namespace {
        char const *types[] = {
                "player",
                "linemate",
                "deraumere",
                "sibur",
                "mendiane",
                "phiras",
                "thystame",
                "food",
                "undefined"
        };

        template<typename Out>
        void split(const std::string &s, char delim, Out result) {
            std::stringstream ss(s);
            std::string item;
            while (std::getline(ss, item, delim))
                *(result++) = item;
        }

        std::vector<std::string> split(const std::string &s, char delim, bool remove_empty = true) {
            std::vector<std::string> elems;
            split(s, delim, std::back_inserter(elems));

            if (remove_empty) {
                std::vector<std::string> cpy(elems);
                elems.clear();
                for (auto &s: cpy)
                    if (!s.empty())
                        elems.push_back(s);
            }
            return elems;
        }
    }

    ObjectType deserialize(std::string const &type) {
        for (size_t i = 0; i < UNDEFINED; ++i)
            if (!strcmp(types[i], type.c_str()))
                return static_cast<ObjectType>(i);
        printf("undefined type: %s", type.c_str());
        return UNDEFINED;
    }

    char const *serialize(ObjectType type) {
        return types[type];
    }

    objects_t deserializeInventory(std::string &&serialized) {
        static const objects_t base = {
                { LINEMATE, 0 },
                { DERAUMERE, 0 },
                { SIBUR, 0 },
                { MENDIANE, 0 },
                { PHIRAS, 0 },
                { THYSTAME, 0 },
                { FOOD, 0 }
        };

        objects_t list(base);

        serialized.erase(0, 1);
        serialized.erase(serialized.size() - 1, 1);

        auto items = split(serialized, DELIMITER_INVENTORY_ITEM);
        for (auto &item: items) {
            auto data = split(item, DELIMITER_INVENTORY_ITEM_COUNT);

            std::string &object = data[0];
            auto count = static_cast<size_t>(atoi(data[1].c_str()));

            list[deserialize(object)] += count;
        }

        return list;
    }

    cells_t deserializeCells(std::string &&serialized) {
        cells_t list;

        serialized.erase(0, 1);
        serialized.erase(serialized.size() - 1, 1);
        auto cells = split(serialized, DELIMITER_CELL, false);
        for (auto &cell: cells) {
            auto items = split(cell, DELIMITER_CELL_OBJECT);
            objects_t objects;

            for (auto &item: items) {
                ObjectType type = deserialize(item);

                if (objects.find(type) != objects.end())
                    objects[type] += 1;
                else
                    objects[type] = 1;
            }

            list.push_back(std::move(objects));
        }

        return list;
    }

    vision_t const &getVisionRange() {
        static vision_t vision;

        if (vision.empty()) {
            for (size_t i = 0; i < PLAYER_MAX_LEVEL; ++i) {
                if (i == 0) {
                    vision.push_back((VisionLine) {0, 0, 0});
                } else {
                    size_t min = vision.at(i - 1).max + 1;
                    size_t max = min + 2 * i;
                    size_t middle = min + (max - min) / 2;

                    vision.push_back((VisionLine) {min, max, middle});
                }
            }
        }
        return vision;
    }

    std::string concatenateUnwrapped(char **unwrapped) {
        std::string concatenated;

        for (size_t i = 0; unwrapped[i]; ++i) {
            if (i)
                concatenated += " ";
            concatenated += unwrapped[i];
        }

        return concatenated;
    }
}