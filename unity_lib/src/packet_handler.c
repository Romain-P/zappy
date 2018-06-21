//
// Created by romain on 27/05/18.
//

#include <string.h>
#include <lib.h>
#include "protocol.h"
#include "util.h"

static message_t const messages[] = {
        { "msz",
                (serialize_t) &serialize_msz,
                (deserialize_t) &deserialize_msz,
                (handler_t *) &zappy_instance.handlers.on_map_size_reply
        },
        { "bct",
                (serialize_t) &serialize_bct,
                (deserialize_t) &deserialize_bct,
                (handler_t *) &zappy_instance.handlers.on_tile_content_reply
        },
        { "mct",
                NULL,
                NULL,
                NULL
        },
        { "tna",
                (serialize_t) &serialize_tna,
                (deserialize_t) &deserialize_tna,
                (handler_t *) &zappy_instance.handlers.on_team_name_reply
        },
        { "ppo",
                (serialize_t) &serialize_ppo,
                (deserialize_t) &deserialize_ppo,
                (handler_t *) &zappy_instance.handlers.on_player_position_update
        },
        { "plv",
                (serialize_t) &serialize_plv,
                (deserialize_t) &deserialize_plv,
                (handler_t *) &zappy_instance.handlers.on_player_level_update
        },
        { "pin",
                (serialize_t) &serialize_pin,
                (deserialize_t) &deserialize_pin,
                (handler_t *) &zappy_instance.handlers.on_player_inventory_update
        },
        { "team",
                (serialize_t) &team_serialize,
                (deserialize_t) &team_deserialize,
                NULL
        },
        { "forward",
                (serialize_t) &forward_serialize,
                (deserialize_t) &forward_deserialize,
                NULL
        },
        { "turn",
                (serialize_t) &turn_serialize,
                (deserialize_t) &turn_deserialize,
                NULL
        },
        { "inventory",
                (serialize_t) &inventory_serialize,
                (deserialize_t) &inventory_deserialize,
                NULL
        },
        { "pnw",
                NULL,
                (deserialize_t) &deserialize_pnw,
                (handler_t *) &zappy_instance.handlers.on_player_connected
        },
        { "pex",
                NULL,
                (deserialize_t) &deserialize_pex,
                (handler_t *) &zappy_instance.handlers.on_player_expulsed
        },
        { "pbc",
                NULL,
                (deserialize_t) &deserialize_pbc,
                (handler_t *) &zappy_instance.handlers.on_broadcast
        },
        { "pic",
                (serialize_t) &pic_serialize,
                NULL,
                (handler_t *) &zappy_instance.handlers.on_player_cast_start
        },
        { "pie",
                NULL,
                (deserialize_t) &deserialize_pie,
                (handler_t *) &zappy_instance.handlers.on_player_cast_end
        },
        { "pfk",
                NULL,
                (deserialize_t) &deserialize_pfk,
                (handler_t *) &zappy_instance.handlers.on_player_lay_self
        },
        { "pdr",
                NULL,
                (deserialize_t) &deserialize_pdr,
                (handler_t *) &zappy_instance.handlers.on_player_drop
        },
        { "pgt",
                NULL,
                (deserialize_t) &deserialize_pgt,
                (handler_t *) &zappy_instance.handlers.on_player_collect
        },
        { "pdi",
                NULL,
                (deserialize_t) &deserialize_pdi,
                (handler_t *) &zappy_instance.handlers.on_player_death
        },
        { "enw",
                NULL,
                (deserialize_t) &deserialize_enw,
                (handler_t *) &zappy_instance.handlers.on_player_lay
        },
        { "eht",
                NULL,
                (deserialize_t) &deserialize_eht,
                (handler_t *) &zappy_instance.handlers.on_egg_hatching
        },
        { "ebo",
                NULL,
                (deserialize_t) &deserialize_ebo,
                NULL,
        },
        { "edi",
                NULL,
                (deserialize_t) &deserialize_edi,
                (handler_t *) &zappy_instance.handlers.on_egg_hatching_death
        },
        { "sgt",
                (serialize_t) &serialize_sgt,
                (deserialize_t) &deserialize_sgt,
                (handler_t *) &zappy_instance.handlers.on_timeunit_reply
        },
        { "sst",
                (serialize_t) &serialize_sst,
                (deserialize_t) &deserialize_sst,
                (handler_t *) &zappy_instance.handlers.on_timeunit_modif_reply
        },
        { "seg",
                NULL,
                (deserialize_t) &deserialize_seg,
                (handler_t *) &zappy_instance.handlers.on_game_end
        },
        { "smg",
                NULL,
                (deserialize_t) &deserialize_smg,
                NULL
        },
        { "suc",
                NULL,
                (deserialize_t) &deserialize_suc,
                (handler_t *) &zappy_instance.handlers.on_unknown_command
        },
        { "sbp",
                NULL,
                (deserialize_t) &deserialize_sbp,
                (handler_t *) &zappy_instance.handlers.on_command_param_wrong
        },
        { "smg",
                NULL,
                NULL,
                (handler_t *) &zappy_instance.handlers.on_server_broadcast
        },
        { NULL, NULL, NULL, NULL }
};

void send_packet(session_t id, void *msg) {
    list_t buffer = list_init;
    message_t const *message = NULL;
    char const *named = ((network_packet_t *) msg)->cmd;

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
        strcpy(packet + pos, ZAPPY_ARG_DELIMITER);
        strcpy(packet + pos + 1, arg);
        pos += len;
    }
    packet = realloc(packet, strlen(packet) + 1);
    packet[pos] = '\n';
    network_client_t *client = network_client_find(&zappy_instance.instance.clients, id);
    network_client_send(client, packet, strlen(packet));
    free(packet);
}

void send_unwrapped(session_t id, char *unwrapped) {
    size_t len = strlen(unwrapped);
    char cmd[len + 1];
    strcpy(cmd, unwrapped);
    cmd[len] = '\n';
    network_client_t *client = network_client_find(&zappy_instance.instance.clients, id);
    network_client_send(client, cmd, len + 1);
}

void parse_packet(network_client_t *client, char const *packet, size_t len) {
    char **split = charset_split(packet, len, ZAPPY_PARAM_SEPARATOR);

    for (int i = 0; messages[i].named; ++i) {
        message_t const *message = messages + i;

        char const *cmd = split[0];
        if (!strcmp(message->named, cmd)) {
            void *data = NULL;

            if (message->deserialize)
                data = message->deserialize(split + 1);

            if (data) {
                network_packet_t *casted = data;
                casted->cmd = cmd;
            }
            if ((*message->handler)(client->id, data) && data)
                free(data);
            break;
        }
    }

    str_free_array(split);
}