//
// Created by Clement.Gomis on 6/21/18.
//

#include <zappy_network.h>
#include <stdlib.h>
#include <util.h>
#include <linked_list.h>

packet_sst_t *deserialize_sst(char **args)
{
    packet_sst_t *packet = malloc(sizeof(*packet));
    if (!packet)
        return (NULL);
    parse_int(args[0], (int64_t *) &packet->time);
    return (packet);
}

void serialize_sst(packet_sst_t *msg, list_t *buffer)
{
    list_add(buffer, to_string((size_t) msg->time));
}