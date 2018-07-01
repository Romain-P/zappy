/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** ppo
*/

#include <zappy_network.h>
#include <stdlib.h>
#include <util.h>
#include <linked_list.h>

packet_ppo_t *deserialize_ppo(char **args)
{
	packet_ppo_t *packet = malloc(sizeof(*packet));

	if (!packet)
		return (NULL);
	parse_uint(args[0], &packet->player_number);
	parse_uint(args[1], &packet->x);
	parse_uint(args[2], &packet->y);
	parse_uint(args[3], &packet->orientation);
	return (packet);
}

void serialize_ppo(packet_ppo_t *msg, list_t *buffer)
{
	list_add(buffer, to_string((size_t) msg->player_number));
}