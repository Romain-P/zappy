/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Connect number
*/

#include <stdlib.h>
#include <linked_list.h>
#include <zappy_network.h>
#include <util.h>

packet_connect_number_t *deserialize_connect_number(char **args)
{
	packet_connect_number_t *packet = malloc(sizeof(*packet));

	if (!packet)
		return (NULL);
	parse_uint(args[0], &packet->value);
	return (packet);
}

void serialize_connect_number(packet_connect_number_t *packet, list_t *buffer)
{
}