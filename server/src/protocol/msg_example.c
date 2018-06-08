//
// Created by romain on 08/06/18.
//

#include <protocol.h>
#include <util.h>
#include <string.h>
#include <zappy.h>

void msg_example_handler(player_t *player, packet_example_t *msg) {
    msg->some;
    msg->shiet;
    //etc
}

packet_example_t *msg_example_deserialize(char **args) {
    if (str_array_length(args) != 3)
        return (NULL);
    packet_example_t *packet = malloc(sizeof(*packet));
    if (!parse_int(args[0], &packet->some) || !parse_int(args[2], &packet->shiet)) {
        free(packet);
        return (NULL);
    }
    strcpy(packet->str, args[1]);
    return (packet);
}

char *msg_example_serialize(packet_example_t *msg) {

}