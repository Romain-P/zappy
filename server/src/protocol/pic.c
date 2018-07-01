/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PIC Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

void send_pic(player_t *player, size_t count, int *tab)
{
	char *packet = malloc(sizeof(char) * (strlen("pic") +
	200));
	iter_t *it;
	size_t i = 0;
	player_t *list;

	if (packet == NULL)
		exit(84);
	sprintf(packet, "pic %zu %zu %zu %zu",
	player->x, player->y, player->level + 1, count);
	while (i < count)
		sprintf(packet + strlen(packet),
		" %d", tab[i++]);
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		if (list->is_gui)
			send_unwrapped(list->client, packet);
	}
	free(packet);
}

void show_inventory(player_t *player)
{
	packet_pin_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		exit(84);
	packet->player_number = player->client->id;
	packet->cmd = strdup("pin");
	pin_handler(player, packet);
	free(packet);
}

packet_pic_t *pic_deserialize(char **args)
{
	packet_pic_t *packet = malloc(sizeof(*packet));

	if (packet == NULL)
		return (NULL);
	return (packet);
}

bool pic_handler(player_t *player, packet_pic_t *packet)
{
	player_t *list;
	iter_t *it;

	packet->x = 0;
	packet->y = 0;
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		if (list->is_gui)
			send_packet(list->client, &packet, 0);
	}
	return (true);
}

void pic_serialize(packet_pic_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->x));
	list_add(buffer, to_string(packet->y));
	list_add(buffer, to_string(packet->incantation_level));
	list_add(buffer, to_string(packet->player_nb1));
	list_add(buffer, to_string(packet->player_nb2));
}