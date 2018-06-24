/*
** EPITECH PROJECT, 2018
** message
** File description:
** message.c
*/

#include <zappy_network.h>
#include <stdlib.h>
#include <stderr.h>
#include <util.h>

packet_message_t *deserialize_message(char **args) {
	packet_message_t *packet = malloc(sizeof(*packet));
	if (!packet)
		return (NULL);
	size_t len = strlen(args[0]);
	char tile_str[len];
	strcpy(packet->text, args[0]);
	tile_str[len - 2] = 0;
	parse_int(tile_str, (int64_t *) &packet->tile);
	strcpy(packet->text, args[1]);
	return (packet);
}
