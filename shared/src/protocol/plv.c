/*
** EPITECH PROJECT, 2018
** plv
** File description:
** plv.c
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
	parse_int(args[0], (int64_t *) &packet->player_number);
	parse_int(args[0], (int64_t *) &packet->level);
	return (packet);
}

void serialize_plv(packet_plv_t *msg, list_t *buffer)
{
	list_add(buffer, to_string((size_t) msg->player_number));
}
