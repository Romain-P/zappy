//
// Created by Clement.Gomis on 6/21/18.
//

#include <zappy_network.h>
#include <stdlib.h>
#include <util.h>
#include <linked_list.h>

packet_pin_t *deserialize_pin(char **args)
{
    packet_pin_t *packet = malloc(sizeof(*packet));
    if (!packet)
        return (NULL);
    parse_int(args[0], (int64_t *) &packet->player_number);
    parse_int(args[1], (int64_t *) &packet->x);
    parse_int(args[2], (int64_t *) &packet->y);
    parse_int(args[3], (int64_t *) &packet->q0);
    parse_int(args[4], (int64_t *) &packet->q1);
    parse_int(args[5], (int64_t *) &packet->q2);
    parse_int(args[6], (int64_t *) &packet->q3);
    parse_int(args[7], (int64_t *) &packet->q4);
    parse_int(args[8], (int64_t *) &packet->q5);
    parse_int(args[9], (int64_t *) &packet->q6);
    return (packet);
}

void serialize_pin(packet_pin_t *msg, list_t *buffer)
{
    list_add(buffer, to_string((size_t) msg->player_number));
}