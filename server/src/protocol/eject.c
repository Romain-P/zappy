/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Eject Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

static void move_player_eject(player_t *player, int x, int y)
{
	if (player->orientation == 1)
		y--;
	if (player->orientation == 2)
		x++;
	if (player->orientation == 3)
		y++;
	if (player->orientation == 4)
		x--;
	if (x == ((server.map).width))
		x = 0;
	if (y == ((server.map).height))
		y = 0;
	if (y == -1)
		y = ((server.map).height) - 1;
	if (x == -1)
		x = ((server.map).width) - 1;
	player->x = (size_t) x;
	player->y = (size_t) y;
}

packet_eject_t *eject_deserialize(char **args)
{
	packet_eject_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	return (packet);
}

static void eject_player_case(player_t *player)
{
	player_t *list;
	iter_t *it;
	char str[11];

	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		if (list->x == player->x && list->y == player->y &&
		(list->client)->id != (player->client)->id) {
			move_player_eject(
			player, (int) player->y, (int) player->y);
			sprintf(str, "Eject: %d", 0);
			send_unwrapped(list->client, str);
		}
	}
}

bool eject_handler(player_t *player, packet_eject_t *packet)
{
	if (!packet->delayed) {
		delay(packet,
		(handler_t) &eject_handler, player, 7);
	} else {
		eject_player_case(player);
		send_unwrapped(player->client, "ok");
	}
	return (false);
}

void eject_serialize(packet_eject_t *packet, list_t *buffer)
{
}