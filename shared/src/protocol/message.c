/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Message
*/

#include <zappy_network.h>
#include <stdlib.h>
#include <stderr.h>
#include <util.h>

packet_message_t *deserialize_message(char **args)
{
	packet_message_t *packet = malloc(sizeof(*packet));
	size_t len = strlen(args[0]);
	char tile_str[len];

	if (!packet)
		return (NULL);
	strcpy(tile_str, args[0]);
	tile_str[len - 1] = 0;
	parse_uint(tile_str, &packet->tile);
	strcpy(packet->text, args[1]);
	return (packet);
}