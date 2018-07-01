/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Ebo
*/

#include <zappy_network.h>
#include <stdlib.h>
#include <util.h>

packet_ebo_t *deserialize_ebo(char **args)
{
	packet_ebo_t *packet = malloc(sizeof(*packet));

	if (!packet)
		return (NULL);
	parse_uint(args[0], &packet->egg);
	return (packet);
}