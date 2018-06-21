//
// Created by Clement.Gomis on 6/20/18.
//

#include <zappy_network.h>
#include <linked_list.h>
#include <stdlib.h>
#include <util.h>

packet_bct_tile_t *deserialize_bct(char **args)
{
    packet_bct_tile_t *packet = malloc(sizeof(*packet));
    if (!packet)
        return (NULL);
    parse_int(args[0], (int64_t *) &packet->x);
    parse_int(args[1], (int64_t *) &packet->y);
    parse_int(args[2], (int64_t *) &packet->q0);
    parse_int(args[3], (int64_t *) &packet->q1);
    parse_int(args[4], (int64_t *) &packet->q2);
    parse_int(args[5], (int64_t *) &packet->q3);
    parse_int(args[6], (int64_t *) &packet->q4);
    parse_int(args[7], (int64_t *) &packet->q5);
    parse_int(args[8], (int64_t *) &packet->q6);
    return (packet);
}

void serialize_bct(packet_bct_tile_t *msg, list_t *buffer)
{
    list_add(buffer, to_string((size_t) msg->x));
    list_add(buffer, to_string((size_t) msg->y));
}