//
// Created by romain on 27/05/18.
//

#include <string.h>
#include <protocol.h>
#include "zappy.h"
#include "util.h"

static message_t const messages[] = {
	{ "example",
		(serialize_t) &msg_example_serialize,
		(deserialize_t) &msg_example_deserialize,
		(handler_t) &msg_example_handler
	},
	{ "msz",
		(serialize_t) &msz_serialize,
		(deserialize_t) &msz_deserialize,
		(handler_t) &msz_handler
	},
	{ "bct",
		(serialize_t) &bct_tile_serialize,
		(deserialize_t) &bct_tile_deserialize,
		(handler_t) &bct_tile_handler
	},
	{ "mct",
		(serialize_t) &bct_all_serialize,
		(deserialize_t) &bct_all_deserialize,
		(handler_t) &bct_all_handler
	},
	{ "tna",
		(serialize_t) &tna_serialize,
		(deserialize_t) &tna_deserialize,
		(handler_t) &tna_handler
	},
	{ "ppo",
		(serialize_t) &ppo_serialize,
		(deserialize_t) &ppo_deserialize,
		(handler_t) &ppo_handler
	},
	{ "plv",
		(serialize_t) &plv_serialize,
		(deserialize_t) &plv_deserialize,
		(handler_t) &plv_handler
	},
	{ "pin",
		(serialize_t) &pin_serialize,
		(deserialize_t) &pin_deserialize,
		(handler_t) &pin_handler
	},
	{ "team",
		(serialize_t) &team_serialize,
		(deserialize_t) &team_deserialize,
		(handler_t) &team_handler
	},
	{ "forward",
		(serialize_t) &forward_serialize,
		(deserialize_t) &forward_deserialize,
		(handler_t) &forward_handler
	},
	{ "turn",
		(serialize_t) &turn_serialize,
		(deserialize_t) &turn_deserialize,
		(handler_t) &turn_handler
	},
	{ "inventory",
		(serialize_t) &inventory_serialize,
		(deserialize_t) &inventory_deserialize,
		(handler_t) &inventory_handler
	},
	{ "pnw",
		(serialize_t) &pnw_serialize,
		NULL,
		NULL
	},
	{ "pex",
		(serialize_t) &pex_serialize,
		NULL,
		NULL
	},
	{ "pbc",
		(serialize_t) &pbc_serialize,
		(deserialize_t) &pbc_deserialize,
		(handler_t) &pbc_handler
	},
	{ "pic",
		(serialize_t) &pic_serialize,
		(deserialize_t) &pic_deserialize,
		(handler_t) &pic_handler
	},
	{ "pie",
		(serialize_t) &pie_serialize,
		(deserialize_t) &pie_deserialize,
		(handler_t) &pie_handler
	},
	{ "pfk",
		(serialize_t) &pfk_serialize,
		(deserialize_t) &pfk_deserialize,
		(handler_t) &pfk_handler
	},
	{ "pdr",
		(serialize_t) &pdr_serialize,
		NULL,
		NULL
	},
	{ "pgt",
		(serialize_t) &pgt_serialize,
		NULL,
		NULL
	},
	{ "pdi",
		(serialize_t) &pdi_serialize,
		NULL,
		NULL
	},
	{ "enw",
		(serialize_t) &enw_serialize,
		NULL,
		NULL
	},
	{ "eht",
		(serialize_t) &eht_serialize,
		NULL,
		NULL
	},
	{ "ebo",
		(serialize_t) &ebo_serialize,
		NULL,
		NULL
	},
	{ "edi",
		(serialize_t) &edi_serialize,
		NULL,
		NULL
	},
	{ "sgt",
		(serialize_t) &sgt_serialize,
		(deserialize_t) &sgt_deserialize,
		(handler_t) &sgt_handler
	},
	{ "sst",
		(serialize_t) &sst_serialize,
		(deserialize_t) &sst_deserialize,
		(handler_t) &sst_handler
	},
	{ "seg",
		(serialize_t) &seg_serialize,
		NULL,
		NULL
	},
	{ "smg",
		(serialize_t) &smg_serialize,
		NULL,
		NULL
	},
	{ "suc",
		(serialize_t) &suc_serialize,
		NULL,
		NULL
	},
	{ "sbp",
		(serialize_t) &sbp_serialize,
		NULL,
		NULL
	},
	{ NULL }
};

void send_packet(network_client_t *client, void *msg)
{
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
	network_client_send(client, packet, strlen(packet));
	free(packet);
}

void send_unwrapped(network_client_t *client, char *unwrapped)
{
	size_t len = strlen(unwrapped);
	char cmd[len + 1];
	strcpy(cmd, unwrapped);
	cmd[len] = '\n';
	network_client_send(client, cmd, len + 1);
}

void parse_packet(network_client_t *client, char const *packet, size_t len)
{
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
			casted->delayed = false;
			}
			if (message->handler(find_player(client), data) && data)
			free(data);
			break;
		}
	}

	str_free_array(split);
}