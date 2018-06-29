/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Ressource Tile
*/

#include "look.h"

char *get_content_tile(packet_look_t *packet)
{
	size_t nb = count_player_on_tile(packet);
	size_t len = 0;
	char *str;

	if (nb > 0)
		len = strlen(" player ");
	count_ressource_on_tile(packet);
	count_size_ressource(packet, &len);
	str = malloc(sizeof(char) * (len + 64));
	if (str == NULL)
		exit(84);
	str[0] = '\0';
	set_player_count_look(nb, str);
	get_type_in_tile(packet, str, nb);
	return (str);
}

size_t count_player_on_tile(packet_look_t *packet)
{
	player_t *list;
	iter_t *it;
	size_t count = 0;

	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		if (list->x == packet->x && list->y == packet->y)
			count++;
	}
	return (count);
}

void count_ressource_on_tile(packet_look_t *packet)
{
	resource_t *list;
	iter_t *it;

	packet->q0 = 0;
	packet->q1 = 0;
	packet->q2 = 0;
	packet->q3 = 0;
	packet->q4 = 0;
	packet->q5 = 0;
	packet->q6 = 0;
	for (it = iter_begin(&(server.map).ressources); it; iter_next(it)) {
		list = it->data;
		if (list->x == packet->x && list->y == packet->y) {
			increment_ressource(packet, list->type);
		}
	}
}

void get_type_in_tile(packet_look_t *packet, char *str, size_t nb)
{
	size_t tmp = 0;

	if (nb != 0 && (packet->q0 >= 1 || packet->q1 >= 1 ||
	packet->q2 >= 1 || packet->q3 >= 1 || packet->q4 >= 1 ||
	packet->q5 >= 1 || packet->q6 >= 1))
		strcat(str, " ");
	if (packet->q0 > 0)
		set_type(str, "food", packet->q0, &tmp);
	if (packet->q1 > 0)
		set_type(str, "linemate", packet->q1, &tmp);
	if (packet->q2 > 0)
		set_type(str, "deraumere", packet->q2, &tmp);
	if (packet->q3 > 0)
		set_type(str, "sibur", packet->q3, &tmp);
	if (packet->q4 > 0)
		set_type(str, "mendiane", packet->q4, &tmp);
	if (packet->q5 > 0)
		set_type(str, "phiras", packet->q5, &tmp);
	if (packet->q6 > 0)
		set_type(str, "linemate", packet->q6, &tmp);
}

void count_size_ressource(packet_look_t *packet, size_t *len)
{
	if (packet->q0 != 0)
		*len += strlen(" food") * packet->q0;
	if (packet->q1 != 0)
		*len += strlen(" linemate") * packet->q1;
	if (packet->q2 != 0)
		*len += strlen(" deraumere") * packet->q2;
	if (packet->q3 != 0)
		*len += strlen(" sibur") * packet->q3;
	if (packet->q4 != 0)
		*len += strlen(" mendiane") * packet->q4;
	if (packet->q5 != 0)
		*len += strlen(" phiras") * packet->q5;
	if (packet->q6 != 0)
		*len += strlen(" thystame") * packet->q6;
}