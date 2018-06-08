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
    //si tu veux envoyer un packet

    packet_example_t sample = {.some = 10, .shiet = 12, .str = "lol"};
    send_packet(player->client, "example", &sample);
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

void msg_example_serialize(packet_example_t *msg, list_t *buffer) {
    list_add(buffer, to_string((msg->some)));
    list_add(buffer, strdup(msg->str));
    list_add(buffer, to_string(msg->shiet));
}