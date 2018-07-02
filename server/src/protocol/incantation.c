/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Incantation COMMAND
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"
#include "level.h"

packet_incantation_t *incantation_deserialize(char **args)
{
	packet_incantation_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	packet->player = malloc(sizeof(int) * 50);
	return (packet);
}

static void send_to_all_tile(char *message, player_t *player, bool success)
{
	player_t *list;
	iter_t *it;

	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		if (list->x == player->x && list->y == player->y) {
			send_unwrapped(list->client, message);
			if (success) {
				list->level++;
				send_plv(list);
			}
		}
	}
}

static char *send_current_level(player_t *player)
{
	char *level = malloc(sizeof(char) * strlen("Current level: ") + 10);

	if (level == NULL)
		exit(84);
	sprintf(level, "Current level: %zu", player->level + 1);
	return (level);
}

bool incantation_handler(player_t *player, packet_incantation_t *packet)
{
	size_t condition = check_condition_incantation(player, packet);

	if (condition == 1) {
		send_unwrapped(player->client, "ko");
		return (false);
	}
	if (!packet->delayed) {
		send_to_all_tile("Elevation underway", player, false);
		delay(packet,
		(handler_t) &incantation_handler, player, 300);
	} else {
		delete_ressource(player);
        send_pie(player, packet);
		send_to_all_tile(send_current_level(player), player, true);
	}
	return (false);
}

void incantation_serialize(packet_incantation_t *packet, list_t *buffer)
{
}