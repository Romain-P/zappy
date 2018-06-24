/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Command TNA
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

packet_tna_t *tna_deserialize(char **args)
{
	packet_tna_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	return (packet);
}

bool tna_handler(player_t *player, packet_tna_t *packet)
{
	team_t *team;
	iter_t *it;

	for (it = iter_begin(&server.teams); it; iter_next(it)) {
		team = it->data;
		strcpy(packet->name, team->name);
		send_packet(player->client, &packet);
	}
	return (true);
}

void tna_serialize(packet_tna_t *packet, list_t *buffer)
{
	list_add(buffer, strdup(packet->name));
}