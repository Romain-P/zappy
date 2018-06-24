/*
** EPITECH PROJECT, 2018
** connect_number
** File description:
** connect_number.c
*/

#include <stdlib.h>
#include <linked_list.h>
#include <zappy_network.h>
#include <util.h>

packet_connect_number_t *deserialize_connect_number(char **args) {
	packet_connect_number_t *packet = malloc(sizeof(*packet));
	if (!packet)
		return (NULL);
	parse_int(args[0], (int64_t *) &packet->value);
	return (packet);
}

void serialize_connect_number(packet_connect_number_t *packet,
			list_t *buffer) {}
