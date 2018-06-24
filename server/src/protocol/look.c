/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Look Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"
#include "look.h"

packet_look_t *look_deserialize(char **args)
{
	packet_look_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	packet->tile = 3;
	return (packet);
}

bool look_handler(player_t *player, packet_look_t *packet)
{
	int i = 0;
	char **tab = malloc(sizeof(char *) * get_count_tile(player->level));

	if (tab == NULL)
		exit(84);
	packet->level = player->level;
	tab[0] = strdup("player");
	packet->number = 1;
	while (i < player->level) {
		packet->x = 0;
		packet->y = 0;
		loop_tile(player, packet, i, tab);
		packet->tile += 2;
		i += 1;
	}
	tab[packet->number] = NULL;
	send_unwrapped(player->client, prepare_packet_look(tab));
	return (true);
}

void set_type(char *str, char *type, size_t nb)
{
	size_t i = 0;

	if (str[0] != '\0')
		strcat(str, " ");
	while (i < nb) {
		strcat(str, type);
		if ((i + 1) < nb)
			strcat(str, " ");
		i += 1;
	}
}

void increment_ressource(packet_look_t *packet, resource_type_t type)
{
	if (type == FOOD)
		packet->q0 += 1;
	if (type == LINEMATE)
		packet->q1 += 1;
	if (type == DERAUMERE)
		packet->q2 += 1;
	if (type == SIBUR)
		packet->q3 += 1;
	if (type == MENDIANE)
		packet->q4 += 1;
	if (type == PHIRAS)
		packet->q5 += 1;
	if (type == THYSTAME)
		packet->q6 += 1;
}

void look_serialize(packet_look_t *packet, list_t *buffer)
{
}