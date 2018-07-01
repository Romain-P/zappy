/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Broadcast Command - Angle
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

int get_sound(player_t *emitter, player_t *receiver)
{
	tile_t d;

	if (emitter->y > receiver->y)
		d = backward;
	if (emitter->y < receiver->y)
		d = forward;
	else if (emitter->y == receiver->y) {
		if (emitter->x > receiver->x)
			d = right;
		else if (emitter->x < receiver->x)
			d = left;
		else
			d = none;
	}
	return (get_final_direction(d, receiver));
}

void loop_broadcast_player(player_t *player, char *text)
{
	player_t *list;
	iter_t *it;
	char packet[1024];

	send_pbc(player, text);
	for (it = iter_begin(&server.players); it; iter_next(it)) {
		list = it->data;
		if (list->client->id != player->client->id && !list->is_gui) {
			sprintf(packet, "message %d, %s",
			get_sound(player, list), text);
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
