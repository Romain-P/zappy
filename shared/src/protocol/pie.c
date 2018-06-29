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
    parse_uint(args[2], &packet->result);
    return (packet);
}