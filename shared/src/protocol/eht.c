/*
** EPITECH PROJECT, 2018
** eht
** File description:
** eht.c
*/

#include <zappy_network.h>
#include <stdlib.h>
#include <util.h>

packet_eht_t *deserialize_eht(char **args)
{
	packet_eht_t *packet = malloc(sizeof(*packet));
	if (!packet)
		return (NULL);
	parse_int(args[0], (int64_t *) &packet->egg);
	return (packet);
}
