/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Packet Handler
*/

#include "protocol.h"
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
	{ "Forward",
		(serialize_t) &forward_serialize,
		(deserialize_t) &forward_deserialize,
		(handler_t) &forward_handler
	},
	{ "Take",
		(serialize_t) &take_serialize,
		(deserialize_t) &take_deserialize,
		(handler_t) &take_handler
	},
	{ "Set",
		(serialize_t) &set_serialize,
		(deserialize_t) &set_deserialize,
		(handler_t) &set_handler
	},
	{ "Eject",
		(serialize_t) &eject_serialize,
		(deserialize_t) &eject_deserialize,
		(handler_t) &eject_handler
	},
	{ "Fork",
		(serialize_t) &fork_serialize,
		(deserialize_t) &fork_deserialize,
		(handler_t) &fork_handler
	},
	{ "Connect_nbr",
		(serialize_t) &connectnbr_serialize,
		(deserialize_t) &connectnbr_deserialize,
		(handler_t) &connectnbr_handler
	},
	{ "Broadcast",
		(serialize_t) &broadcast_serialize,
		(deserialize_t) &broadcast_deserialize,
		(handler_t) &broadcast_handler
	},
	{ "Look",
		(serialize_t) &look_serialize,
		(deserialize_t) &look_deserialize,
		(handler_t) &look_handler
	},
	{ "Left",
		(serialize_t) &left_serialize,
		(deserialize_t) &left_deserialize,
		(handler_t) &left_handler
	},
	{ "Right",
		(serialize_t) &right_serialize,
		(deserialize_t) &right_deserialize,
		(handler_t) &right_handler
	},
	{ "Inventory",
		(serialize_t) &inventory_serialize,
		(deserialize_t) &inventory_deserialize,
		(handler_t) &inventory_handler
	},
	{ "Incantation",
		(serialize_t) &incantation_serialize,
		(deserialize_t) &incantation_deserialize,
		(handler_t) &incantation_handler
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

int get_packet_parse(char *packet, list_t *buffer, char const *named)
{
	int pos = strlen(packet);
	iter_t *it;
	char *arg;
	int len;

	packet = strdup(named);
	for (it = iter_begin(buffer); it; iter_next(it)) {
		arg = it->data;
		len = strlen(arg) + 1;
		packet = realloc(packet, len);
		strcpy(packet + pos, ZAPPY_PARAM_SEPARATOR);
		strcpy(packet + pos + 1, arg);
		pos += len;
	}
	return (pos);
}

void send_packet(network_client_t *client, void *msg)
{
	list_t buffer = list_init;
	message_t const *message = NULL;
	char const *named = ((network_packet_t *) msg)->cmd;
	char *packet = NULL;
	int pos;

	for (pos = 0; messages[pos].named; ++pos) {
		if (!strcmp(messages[pos].named, named)) {
			message = messages + pos;
			break;
		}
	}
	if (message == NULL)
		return;
	message->serialize(msg, &buffer);
	pos = get_packet_parse(packet, &buffer, named);
	list_clear(&buffer, &free);
	packet = realloc(packet, strlen(packet) + 1);
	packet[pos] = '\n';
	network_client_send(client, packet, strlen(packet));
	free(packet);
}

int check_command_packet(const message_t *message,
	char **split, char *cmd, network_client_t *client)
{
	void *data = NULL;
	network_packet_t *casted;
	player_t *player = find_player(client);

	if (!strcmp(message->named, cmd)) {
		if (player->state != VALID_PLAYER) {
			network_client_close(client);
			return (1);
		}
		if (message->deserialize)
			data = message->deserialize(split + 1);
		if (data) {
			casted = data;
			casted->cmd = cmd;
			casted->delayed = false;
		}
		if (message->handler(player, data) && data)
			free(data);
		return (1);
	}
	return (0);
}

bool loop_packet(char **split, player_t *player, network_client_t *client)
{
	int i = 0;
	const message_t *message;
	char *cmd;
	bool found_wrapped = false;
	int value;

	for (i = 0; messages[i].named; ++i) {
		message = messages + i;
		cmd = split[0];
		if (!strcmp(message->named, cmd))
			found_wrapped = true;
		value = check_command_packet(message, split, cmd, client);
		if (value == 1)
			break;
	}
	return (found_wrapped);
}

void parse_packet(network_client_t *client, char const *packet, size_t len)
{
	char **split = charset_split(packet, len, ZAPPY_PARAM_SEPARATOR);
	player_t *player = find_player(client);
	bool found_wrapped = false;

	found_wrapped = loop_packet(split, player, client);
	if (!found_wrapped)
		on_unwrapped(player, split);
	str_free_array(split);
}