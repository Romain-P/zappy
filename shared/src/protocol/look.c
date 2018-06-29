//
// Created by romain on 22/06/18.
//


#include <zappy_network.h>
#include <linked_list.h>
#include <stdlib.h>
#include <string.h>

packet_look_t *deserialize_look(char **args) {
    packet_look_t *packet = malloc(sizeof(*packet));
    if (!packet)
        return (NULL);
    strcpy(packet->data, args[0]);
    return (packet);
}

void serialize_look(packet_look_t *packet, list_t *buffer) {}