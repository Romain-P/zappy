//
// Created by romain on 21/06/18.
//

#include "protocol.h"
#include <stdlib.h>
#include <util.h>

packet_pic_t *deserialize_pic(char **args) {
    packet_pic_t *packet = malloc(sizeof(*packet));
    if (!packet)
        return (NULL);
    parse_int(args[0], (int64_t *) &packet->x);
    parse_int(args[1], (int64_t *) &packet->y);
    parse_int(args[2], (int64_t *) &packet->incantation_level);
    parse_int(args[3], (int64_t *) &packet->players_count);
    for (size_t i = 0; i < packet->players_count; ++i)
        parse_int(args[4 + i], (int64_t *) &packet->players[i]);
    return (packet);
}