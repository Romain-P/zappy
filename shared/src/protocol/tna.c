/*
** EPITECH PROJECT, 2018
** tna
** File description:
** tna.c
*/

#include <zappy_network.h>
#include <stdlib.h>
#include <string.h>
#include <linked_list.h>

packet_tna_t *deserialize_tna(char **args) {
	packet_tna_t *packet = malloc(sizeof(*packet));
	if (!packet)
		return (NULL);
	strcpy(packet->name, args[0]);
	return (packet);
}

void serialize_tna(packet_tna_t *packet, list_t *buffer) {}
