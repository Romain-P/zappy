//
// Created by Clement.Gomis on 6/20/18.
//

#include <zappy_network.h>
#include <stdlib.h>
#include <util.h>
#include <string.h>

packet_pnw_t *deserialize_pnw(char **args)
{
    packet_pnw_t *packet = malloc(sizeof(*packet));
    if (!packet)
        return (NULL);
    parse_uint(args[0], &packet->player_number);
    parse_uint(args[1], &packet->x);
    parse_uint(args[2], &packet->y);
    parse_uint(args[3], &packet->orientation);
    parse_uint(args[4], &packet->level);
    strcpy(packet->name_team, args[5]);
    return (packet);
}
