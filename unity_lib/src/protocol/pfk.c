//
// Created by Clement.Gomis on 6/21/18.
//

#include <zappy_network.h>
#include <stdlib.h>
#include <util.h>

packet_pfk_t *deserialize_pfk(char **args)
{
    packet_pfk_t *packet = malloc(sizeof(*packet));
    if (!packet)
        return (NULL);
    parse_int(args[0], (int64_t *) &packet->player_number);
    return (packet);
}
