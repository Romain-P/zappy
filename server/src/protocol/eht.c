/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** EHT Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

void send_eht(player_t *player, egg_t *egg)
{
	char *packet = malloc(sizeof(char) * (strlen("eht") +
	20));
	iter_t *it;
	player_t *list;

	if (packet == NULL)
		exit(84);
	sprintf(packet, "eht %zo", egg->id);
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		send_unwrapped(list->client, packet);
	}
}

void eht_serialize(packet_eht_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->egg));
}