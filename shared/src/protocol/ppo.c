/*
** EPITECH PROJECT, 2018
** ppo
** File description:
** ppo.c
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
	parse_int(args[0], (int64_t *) &packet->player_number);
	parse_int(args[1], (int64_t *) &packet->x);
	parse_int(args[2], (int64_t *) &packet->y);
	parse_int(args[3], (int64_t *) &packet->orientation);
	return (packet);
}

void serialize_ppo(packet_ppo_t *msg, list_t *buffer)
{
	list_add(buffer, to_string((size_t) msg->player_number));
}
