/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Command WELCOME
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

static void send_players(player_t *player)
{
	iter_t *it;
	player_t *each;

	for (it = iter_begin(&server.players); it; iter_next(it)) {
		each = it->data;
		if (player != each)
			send_pnw(each);
	}
}

packet_welcome_t *welcome_deserialize(char **args)
{
	packet_welcome_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	return (packet);
}

bool welcome_handler(player_t *player, packet_welcome_t *packet)
{
	packet_sst_t freq_msg = { .cmd = "sst", .time = server.freq };

	player->is_gui = 1;
	send_msz(player);
	send_tna(player);
	send_players(player);
	send_bct(player);
	send_packet(player->client, &freq_msg, 0);
	return (true);
}

void welcome_serialize(packet_welcome_t *packet, list_t *buffer)
{
}