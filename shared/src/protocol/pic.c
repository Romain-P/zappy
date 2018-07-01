/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** pic
*/

#include "protocol.h"
#include <stdlib.h>
#include <util.h>

packet_pic_t *deserialize_pic(char **args)
{
	packet_pic_t *packet = malloc(sizeof(*packet));
	size_t i;

	if (!packet)
		return (NULL);
	parse_uint(args[0], &packet->x);
	parse_uint(args[1], &packet->y);
	parse_uint(args[2], &packet->incantation_level);
	parse_uint(args[3], &packet->players_count);
	for (i = 0; i < packet->players_count; ++i)
		parse_uint(args[4 + i], &packet->players[i]);
	return (packet);
}