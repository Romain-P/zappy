/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Broadcast Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

player_t  *correct_orientation_player(player_t *player)
{
	player_t *p1 = malloc(sizeof(player_t));

	if (p1 == NULL)
		exit(84);
	p1->x = player->x;
	p1->y = player->y;
	if (player->orientation == 1)
		p1->orientation = 0;
	if (player->orientation == 3)
		p1->orientation = 1;
	if (player->orientation == 2)
		p1->orientation = 3;
	if (player->orientation == 4)
		p1->orientation = 2;
	return (p1);
}

void loop_broadcast_player(player_t *player, char *text)
{
	player_t *list;
	iter_t *it;
	char packet[1024];

	send_pbc(player, text);
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		if (list->client->id != player->client->id && !player->is_gui) {
			sprintf(packet, "message %d, %s",
			get_sound_player(player, list), text);
			send_unwrapped(list->client, packet);
		}
	}
}

packet_broadcast_t *broadcast_deserialize(char **args)
{
	packet_broadcast_t *packet = malloc(sizeof(*packet));
	char *text;
	size_t len = 0;
	size_t i = 0;

	if (str_array_length(args) != 1) {
		return (NULL);
	}
	if (packet == NULL)
		return (NULL);
	while (args[i] != NULL)
		len += strlen(args[i++]);
	text = malloc(sizeof(char) * (len + 10));
	if (text == NULL)
		exit(84);
	text[0] = '\0';
	i = 0;
	while (args[i] != NULL)
		strcat(text, args[i++]);
	strcpy(packet->text, text);
	return (packet);
}

bool broadcast_handler(player_t *player, packet_broadcast_t *packet)
{
	if (!packet->delayed) {
		delay(packet,
		(handler_t) &broadcast_handler, player, 7);
	} else {
		loop_broadcast_player(player, packet->text);
		send_unwrapped(player->client, "ok");
	}
	return (false);
}

void broadcast_serialize(packet_broadcast_t *packet, list_t *buffer)
{
	list_add(buffer, strdup(packet->text));
}
