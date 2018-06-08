//
// Created by romain on 08/06/18.
//

#ifndef ZAPPY_PROTOCOL_H
#define ZAPPY_PROTOCOL_H

#include "zappy.h"

typedef struct packet_example_s packet_example_t;
struct packet_example_s {
    int64_t some;
    char str[100];
    int64_t shiet;
};

void msg_example_handler(player_t *player, packet_example_t *msg);
packet_example_t *msg_example_deserialize(char **args);
char *msg_example_serialize(packet_example_t *msg);

#endif //ZAPPY_PROTOCOL_H
