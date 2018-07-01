/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** plv
*/

#include <zappy_network.h>
#include <stdlib.h>
#include <util.h>
#include <linked_list.h>

packet_plv_t *deserialize_plv(char **args)
{
	packet_plv_t *packet = malloc(sizeof(*packet));

	if (!packet)
		return (NULL);
	parse_uint(args[0], &packet->player_number);
	parse_uint(args[0], &packet->level);
	return (packet);
}

void serialize_plv(packet_plv_t *msg, list_t *buffer)
{
	list_add(buffer, to_string((size_t) msg->player_number));
}