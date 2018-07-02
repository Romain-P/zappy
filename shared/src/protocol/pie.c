//
// Created by Clement.Gomis on 6/21/18.
//

#include <zappy_network.h>
#include <stdlib.h>
#include <util.h>

packet_pie_t *deserialize_pie(char **args)
{
    packet_pie_t *packet = malloc(sizeof(*packet));
    if (!packet)
        return (NULL);
    parse_uint(args[0], &packet->x);
    parse_uint(args[1], &packet->y);
    parse_uint(args[2], &packet->incantation_level);
    parse_uint(args[3], &packet->players_count);
    for (size_t i = 0; i < packet->players_count; ++i)
        parse_uint(args[4 + i], &packet->players[i]);
    return (packet);
}