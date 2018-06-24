/*
** EPITECH PROJECT, 2018
** sgt
** File description:
** sgt.c
*/

#include <zappy_network.h>
#include <stdlib.h>
#include <util.h>
#include <linked_list.h>

packet_sgt_t *deserialize_sgt(char **args)
{
	packet_sgt_t *packet = malloc(sizeof(*packet));
	if (!packet)
		return (NULL);
	parse_int(args[0], (int64_t *) &packet->time);
	return (packet);
}

void serialize_sgt(packet_sgt_t *packet, list_t *buffer) {}
