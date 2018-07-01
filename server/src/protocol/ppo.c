/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PPO Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

void send_ppo(player_t *player)
{
	char *packet = malloc(sizeof(char) * (strlen("ppo") +
	20));
	iter_t *it;
	player_t *list;

	if (packet == NULL)
		exit(84);
	sprintf(packet, "ppo %d %zu %zu %zu",
	player->client->id, player->x, player->y,
	convert_orientation(player->orientation));
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		if (list->is_gui == 1)
			send_unwrapped(list->client, packet);
	}
	free(packet);
}

static void get_information_player(int nb, packet_ppo_t *packet)
{
	player_t *player;
	iter_t *it;

	for (it = iter_begin(&server.players); it; iter_next(it)) {
		player = it->data;
		if ((player->client)->id == nb) {
			packet->x = player->x;
			packet->y = player->y;
			packet->orientation = player->orientation;
			return;
		}
	}
}

packet_ppo_t *ppo_deserialize(char **args)
{
	packet_ppo_t *packet;

	if (str_array_length(args) != 1)
		return (NULL);
	packet = malloc(sizeof(*packet));
	if (packet == NULL)
		return (NULL);
	if (args[0][0] == '#')
		args[0]++;
	if (!parse_int(args[0], (int64_t *) &packet->player_number)) {
		free(packet);
		return (NULL);
	}
	return (packet);
}

bool ppo_handler(player_t *player, packet_ppo_t *packet)
{
	if (player->is_gui == 0)
		return (false);
	get_information_player(packet->player_number, packet);
	send_packet(player->client, &packet, 0);
	return (true);
}

void ppo_serialize(packet_ppo_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->player_number));
	list_add(buffer, to_string(packet->x));
	list_add(buffer, to_string(packet->y));
	list_add(buffer, to_string(packet->orientation));
}