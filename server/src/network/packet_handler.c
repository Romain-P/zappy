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

void parse_packet(network_client_t *client, char const *packet, size_t len) {
    char **split = charset_split(packet, len, ZAPPY_PARAM_SEPARATOR);

    for (int i = 0; messages[i].named; ++i) {
        if (!strcmp(messages[i].named, split[0])) {
            message_t const *message = messages + i;
            void *data = message->deserialize(split + 1);

            if (!data) return;

            message->handler(find_player(client), data);
            break;
        }
    }

    str_free_array(split);
}