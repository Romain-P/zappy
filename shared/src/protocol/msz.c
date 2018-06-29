//
// Created by Clement.Gomis on 6/20/18.
//

#include <zappy_network.h>
#include <linked_list.h>
#include <stdlib.h>
#include <util.h>

packet_msz_t *deserialize_msz(char **args) {
    packet_msz_t *packet = malloc(sizeof(*packet));
    if (!packet)
        return (NULL);
    parse_uint(args[0], &packet->x);
    parse_uint(args[1], &packet->y);
    return (packet);
}

void serialize_msz(packet_msz_t *msg, list_t *buffer) {
    list_add(buffer, to_string((size_t) msg->x));
    list_add(buffer, to_string((size_t) msg->y));
}
