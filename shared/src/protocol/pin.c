/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** pin
*/

#include <zappy_network.h>
#include <stdlib.h>
#include <util.h>
#include <linked_list.h>

packet_pin_t *deserialize_pin(char **args)
{
	packet_pin_t *packet = malloc(sizeof(*packet));

	if (!packet)
		return (NULL);
	parse_uint(args[0], &packet->player_number);
	parse_uint(args[1], &packet->x);
	parse_uint(args[2], &packet->y);
	parse_uint(args[3], &packet->q0);
	parse_uint(args[4], &packet->q1);
	parse_uint(args[5], &packet->q2);
	parse_uint(args[6], &packet->q3);
	parse_uint(args[7], &packet->q4);
	parse_uint(args[8], &packet->q5);
	parse_uint(args[9], &packet->q6);
	return (packet);
}

void serialize_pin(packet_pin_t *msg, list_t *buffer)
{
	list_add(buffer, to_string((size_t) msg->player_number));
}