//
// Created by romain on 27/05/18.
//

#include <string.h>
#include <protocol.h>
#include "zappy.h"
#include "util.h"

static message_t const messages[] = {
        { "example",
                (serialize_t ) &msg_example_serialize,
                (deserialize_t) &msg_example_deserialize,
                (handler_t) &msg_example_handler
        },
        { NULL, NULL }
};

void send_packet(network_client_t *client, char const *named, void *msg) {
    list_t buffer = list_init;
    message_t const *message = NULL;

    for (int i = 0; messages[i].named; ++i) {
        if (!strcmp(messages[i].named, named)) {
            message = messages + i;
            break;
        }
    }
    if (message == NULL) return;

    message->serialize(msg, &buffer);
    char *packet = strdup(named);
    size_t pos = strlen(packet);

    for (iter_t *it = iter_begin(&buffer); it; iter_next(it)) {
        char *arg = it->data;
        size_t len = strlen(arg) + 1;
        packet = realloc(packet, len);
        strcpy(packet, " ");
        strcpy(packet, arg);
        pos += len;
    }
    send(client->id, packet, strlen(packet), 0);
    free(packet);
}

void parse_packet(network_client_t *client, char const *packet, size_t len) {
    char **split = charset_split(packet, len, ZAPPY_PARAM_SEPARATOR);

    for (int i = 0; messages[i].named; ++i) {
        message_t const *message = messages + i;

        if (!strcmp(message->named, split[0])) {
            void *data = message->deserialize(split + 1);

            if (!data) return;

            message->handler(find_player(client), data);
            break;
        }
    }

    str_free_array(split);
}