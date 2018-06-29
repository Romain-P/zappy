//
// Created by romain on 27/05/18.
//

#include <string.h>
#include <lib.h>
#include <printf.h>
#include <stderr.h>
#include <pthread.h>
#include "protocol.h"
#include "util.h"
#include "zappy_network.h"

static message_t const messages[] = {
        { "WELCOME",
                NULL,
                (deserialize_t) deserialize_welcome,
                (handler_t *) &zappy_instance.gui_handlers.on_welcome
        },
        { "message",
                NULL,
                (deserialize_t) deserialize_message,
                (handler_t *) &zappy_instance.ai_handlers.on_message_reply
        },
        { "Look",
                (serialize_t) serialize_look,
                (deserialize_t) deserialize_look,
                (handler_t *) &zappy_instance.ai_handlers.on_look_reply
        },
        { "Connect_nbr",
                (serialize_t) serialize_connect_number,
                (deserialize_t) deserialize_connect_number,
                (handler_t *) &zappy_instance.ai_handlers.on_connect_nummber_reply
        },
        { "Inventory",
                (serialize_t) serialize_inventory,
                (deserialize_t) deserialize_inventory,
                (handler_t *) &zappy_instance.ai_handlers.on_inventory_reply
        },
        { "Broadcast",
                (serialize_t) serialize_broadcast,
                NULL,
                NULL
        },
        { "msz",
                (serialize_t) &serialize_msz,
                (deserialize_t) &deserialize_msz,
                (handler_t *) &zappy_instance.gui_handlers.on_map_size_reply
        },
        { "bct",
                (serialize_t) &serialize_bct,
                (deserialize_t) &deserialize_bct,
                (handler_t *) &zappy_instance.gui_handlers.on_tile_content_reply
        },
        { "mct",
                NULL,
                NULL,
                NULL
        },
        { "tna",
                (serialize_t) &serialize_tna,
                (deserialize_t) &deserialize_tna,
                (handler_t *) &zappy_instance.gui_handlers.on_team_name_reply
        },
        { "ppo",
                (serialize_t) &serialize_ppo,
                (deserialize_t) &deserialize_ppo,
                (handler_t *) &zappy_instance.gui_handlers.on_player_position_update
        },
        { "plv",
                (serialize_t) &serialize_plv,
                (deserialize_t) &deserialize_plv,
                (handler_t *) &zappy_instance.gui_handlers.on_player_level_update
        },
        { "pin",
                (serialize_t) &serialize_pin,
                (deserialize_t) &deserialize_pin,
                (handler_t *) &zappy_instance.gui_handlers.on_player_inventory_update
        },
        { "pnw",
                NULL,
                (deserialize_t) &deserialize_pnw,
                (handler_t *) &zappy_instance.gui_handlers.on_player_connected
        },
        { "pex",
                NULL,
                (deserialize_t) &deserialize_pex,
                (handler_t *) &zappy_instance.gui_handlers.on_player_expulsed
        },
        { "pbc",
                NULL,
                (deserialize_t) &deserialize_pbc,
                (handler_t *) &zappy_instance.gui_handlers.on_broadcast
        },
        { "pic",
                NULL,
                (deserialize_t) &deserialize_pic,
                (handler_t *) &zappy_instance.gui_handlers.on_player_cast_start
        },
        { "pie",
                NULL,
                (deserialize_t) &deserialize_pie,
                (handler_t *) &zappy_instance.gui_handlers.on_player_cast_end
        },
        { "pfk",
                NULL,
                (deserialize_t) &deserialize_pfk,
                (handler_t *) &zappy_instance.gui_handlers.on_player_lay_self
        },
        { "pdr",
                NULL,
                (deserialize_t) &deserialize_pdr,
                (handler_t *) &zappy_instance.gui_handlers.on_player_drop
        },
        { "pgt",
                NULL,
                (deserialize_t) &deserialize_pgt,
                (handler_t *) &zappy_instance.gui_handlers.on_player_collect
        },
        { "pdi",
                NULL,
                (deserialize_t) &deserialize_pdi,
                (handler_t *) &zappy_instance.gui_handlers.on_player_death
        },
        { "enw",
                NULL,
                (deserialize_t) &deserialize_enw,
                (handler_t *) &zappy_instance.gui_handlers.on_player_lay
        },
        { "eht",
                NULL,
                (deserialize_t) &deserialize_eht,
                (handler_t *) &zappy_instance.gui_handlers.on_egg_hatching
        },
        { "ebo",
                NULL,
                (deserialize_t) &deserialize_ebo,
                NULL,
        },
        { "edi",
                NULL,
                (deserialize_t) &deserialize_edi,
                (handler_t *) &zappy_instance.gui_handlers.on_egg_hatching_death
        },
        { "sgt",
                (serialize_t) &serialize_sgt,
                (deserialize_t) &deserialize_sgt,
                (handler_t *) &zappy_instance.gui_handlers.on_timeunit_reply
        },
        { "sst",
                (serialize_t) &serialize_sst,
                (deserialize_t) &deserialize_sst,
                (handler_t *) &zappy_instance.gui_handlers.on_timeunit_modif_reply
        },
        { "seg",
                NULL,
                (deserialize_t) &deserialize_seg,
                (handler_t *) &zappy_instance.gui_handlers.on_game_end
        },
        { "smg",
                NULL,
                (deserialize_t) &deserialize_smg,
                NULL
        },
        { "suc",
                NULL,
                (deserialize_t) &deserialize_suc,
                (handler_t *) &zappy_instance.gui_handlers.on_unknown_command
        },
        { "sbp",
                NULL,
                (deserialize_t) &deserialize_sbp,
                (handler_t *) &zappy_instance.gui_handlers.on_command_param_wrong
        },
        { "smg",
                NULL,
                NULL,
                (handler_t *) &zappy_instance.gui_handlers.on_server_broadcast
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
        strcpy(packet + pos, ZAPPY_PARAM_SEPARATOR);
        strcpy(packet + pos + 1, arg);
        pos += len;
    }
    packet = realloc(packet, strlen(packet) + 1);
    packet[pos] = '\n';
    network_client_t *client = network_client_find(&zappy_instance.net.clients, id);
    network_client_send(client, packet, strlen(packet));
    free(packet);
}

EXPORT void send_unwrapped(session_t id, char *unwrapped) {
    size_t len = strlen(unwrapped);
    char cmd[len + 1];
    strcpy(cmd, unwrapped);
    cmd[len] = '\n';
    pthread_mutex_lock(&zappy_instance.locker);
    network_client_t *client = network_client_find(&zappy_instance.net.clients, id);
    pthread_mutex_unlock(&zappy_instance.locker);
    network_client_send(client, cmd, len + 1);
}

void parse_packet(network_client_t *client, char const *packet, size_t len) {
    char **split = charset_split(packet, len, ZAPPY_PARAM_SEPARATOR);
    bool found_wrapped = false;

    for (int i = 0; messages[i].named; ++i) {
        message_t const *message = messages + i;

        char const *cmd = split[0];
        if (!strcmp(message->named, cmd)) {
            void *data = NULL;
            found_wrapped = true;
            if (message->deserialize)
                data = message->deserialize(split + 1);
            if (data) {
                network_packet_t *casted = data;
                strcpy(casted->cmd, cmd);
            }
            handler_t handler = *message->handler;

            if (handler) {
                if (!zappy_instance.thread_sync) {
                    handler(client->id, data);
                } else {
                    zappy_sync_push(client->id, handler, data);
                }
            }
            if (data && !zappy_instance.thread_sync) {
                free(data);
            }
            break;
        }
    }
    if (!found_wrapped && zappy_instance.ai_handlers.on_unwrapped)
        zappy_instance.ai_handlers.on_unwrapped(client->id, split);
    str_free_array(split);
}