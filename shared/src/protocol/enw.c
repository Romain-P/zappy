//
// Created by Clement.Gomis on 6/21/18.
//

#include <zappy_network.h>
#include <stdlib.h>
#include <util.h>

packet_enw_t *deserialize_enw(char **args)
{
    packet_enw_t *packet = malloc(sizeof(*packet));
    if (!packet)
        return (NULL);
    parse_int(args[0], (int64_t *) &packet->egg);
    parse_int(args[1], (int64_t *) &packet->player_number);
    parse_int(args[2], (int64_t *) &packet->x);
    parse_int(args[3], (int64_t *) &packet->y);
    return (packet);
}
