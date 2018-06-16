/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Command Team
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"
#include <string.h>

packet_team_t *team_deserialize(char **args)
{
	packet_team_t *packet;

	if (str_array_length(args) != 1)
		return (NULL);
	packet = malloc(sizeof(*packet));
	if (packet == NULL)
		return (NULL);
	strcpy(packet->team, args[0]);
	return (packet);
}

void team_handler(player_t *player, packet_team_t *packet)
{
	if (check_free_team(packet->team) == 1)
		packet->status = 1;
	else
		packet->status = 0;
	send_packet(player->client, "team", &packet);
}

void team_serialize(packet_team_t *packet, list_t *buffer)
{
    list_add(buffer, to_string(packet->status));
}

static int check_free_team(char *name)
{
	team_t *team;
	iter_t *it;

	for (it = iter_begin(&server.teams); it; iter_next(it)) {
		team = it->data;
		if (!strcmp(team->name, name) && team->player > 0) {
			team->player--;
			return (1);
		}
	}
	return (0);
}