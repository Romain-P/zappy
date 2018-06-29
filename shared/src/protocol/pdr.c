//
// Created by Clement.Gomis on 6/21/18.
//

#include <zappy_network.h>
#include <stdlib.h>
#include <util.h>

packet_pdr_t *deserialize_pdr(char **args)
{
    packet_pdr_t *packet = malloc(sizeof(*packet));
    if (!packet)
        return (NULL);
    parse_uint(args[0], &packet->player_number);
    parse_uint(args[1], &packet->ressource);
    return (packet);
}
