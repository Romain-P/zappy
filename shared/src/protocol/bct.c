/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** BCT
*/

#include <zappy_network.h>
#include <linked_list.h>
#include <stdlib.h>
#include <util.h>

packet_bct_tile_t *deserialize_bct(char **args)
{
	packet_bct_tile_t *packet = malloc(sizeof(*packet));

	if (!packet)
		return (NULL);
	parse_uint(args[0], &packet->x);
	parse_uint(args[1], &packet->y);
	parse_uint(args[2], &packet->q0);
	parse_uint(args[3], &packet->q1);
	parse_uint(args[4], &packet->q2);
	parse_uint(args[5], &packet->q3);
	parse_uint(args[6], &packet->q4);
	parse_uint(args[7], &packet->q5);
	parse_uint(args[8], &packet->q6);
	return (packet);
}

void serialize_bct(packet_bct_tile_t *msg, list_t *buffer)
{
	list_add(buffer, to_string((size_t) msg->x));
	list_add(buffer, to_string((size_t) msg->y));
}