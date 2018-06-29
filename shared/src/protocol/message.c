//
// Created by romain on 22/06/18.
//

#include <zappy_network.h>
#include <stdlib.h>
#include <stderr.h>
#include <util.h>

packet_message_t *deserialize_message(char **args) {
    packet_message_t *packet = malloc(sizeof(*packet));
    if (!packet)
        return (NULL);
    size_t len = strlen(args[0]);
    char tile_str[len];
    strcpy(packet->text, args[0]);
    tile_str[len - 2] = 0;
    parse_uint(tile_str, &packet->tile);
    strcpy(packet->text, args[1]);
    return (packet);
}