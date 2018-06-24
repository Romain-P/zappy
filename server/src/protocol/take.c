/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** TAKE COMMAND
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

size_t get_id_ressource(char *str)
{
	if (!strcasecmp(str, "food"))
		return (0);
	if (!strcasecmp(str, "linemate"))
		return (1);
	if (!strcasecmp(str, "deraumere"))
		return (2);
	if (!strcasecmp(str, "sibur"))
		return (3);
	if (!strcasecmp(str, "mendiane"))
		return (4);
	if (!strcasecmp(str, "phiras"))
		return (5);
	if (!strcasecmp(str, "thystame"))
		return (6);
	return (7);
}

static size_t check_ressource_validity(player_t *player, size_t id)
{
	resource_t *list;
	iter_t *it;

	for (it = iter_begin(&(server.map).ressources); it; iter_next(it)) {
		list = it->data;
		if (list->x == player->x && list->y == player->y &&
		list->type == (int) id) {
			list_remove(&(server.map).ressources, list);
			free(list);
			increment_inventory(player, id);
			return (1);
		}
	}
	return (0);
}

packet_take_t *take_deserialize(char **args)
{
	packet_take_t *packet;

	if (str_array_length(args) != 1)
		return (NULL);
	packet = malloc(sizeof(*packet));
	if (packet == NULL)
		return (NULL);
	strcpy(packet->node, args[0]);
	return (packet);
}

bool take_handler(player_t *player, packet_take_t *packet)
{
	if (!packet->delayed) {
		delay(packet,
		(handler_t) &take_handler, player, 7);
	} else {
		if (check_ressource_validity(player,
		get_id_ressource(packet->node)))
			send_unwrapped(player->client, "ok");
		else
			send_unwrapped(player->client, "ko");
	}
	return (false);
}

void take_serialize(packet_take_t *packet, list_t *buffer)
{
}