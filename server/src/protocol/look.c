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
	char **tab;

	if (!packet->delayed) {
		delay(packet,
		(handler_t) &look_handler, player, 7);
	} else {
		tab = get_result_look(player, packet);
		send_unwrapped(player->client, prepare_packet_look(tab));
	}
	return (false);
}

void set_type(char *str, char *type, size_t nb, size_t *tmp)
{
	size_t i = 0;

	if (*tmp == 1)
		strcat(str, " ");
	while (i < nb) {
		strcat(str, type);
		if ((i + 1) < nb)
			strcat(str, " ");
		i += 1;
	}
	*tmp =1;
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