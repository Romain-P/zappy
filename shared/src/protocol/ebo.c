/*
** EPITECH PROJECT, 2018
** ebo
** File description:
** ebo.c
*/

#include <zappy_network.h>
#include <stdlib.h>
#include <util.h>

packet_ebo_t *deserialize_ebo(char **args)
{
	packet_ebo_t *packet = malloc(sizeof(*packet));
	if (!packet)
		return (NULL);
	parse_int(args[0], (int64_t *) &packet->egg);
	return (packet);
}
