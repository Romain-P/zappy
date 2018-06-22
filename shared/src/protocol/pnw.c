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
    parse_int(args[0], (int64_t *) &packet->player_number);
    parse_int(args[1], (int64_t *) &packet->x);
    parse_int(args[2], (int64_t *) &packet->y);
    parse_int(args[3], (int64_t *) &packet->orientation);
    parse_int(args[4], (int64_t *) &packet->level);
    strcpy(packet->name_team, args[5]);
    return (packet);
}
