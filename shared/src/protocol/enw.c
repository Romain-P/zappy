/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** enw
*/

#include <zappy_network.h>
#include <stdlib.h>
#include <util.h>

packet_enw_t *deserialize_enw(char **args)
{
	packet_enw_t *packet = malloc(sizeof(*packet));

	if (!packet)
		return (NULL);
	parse_uint(args[0], &packet->egg);
	parse_uint(args[1], &packet->player_number);
	parse_uint(args[2], &packet->x);
	parse_uint(args[3], &packet->y);
	return (packet);
}
