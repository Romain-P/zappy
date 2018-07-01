/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** eht
*/

#include <zappy_network.h>
#include <stdlib.h>
#include <util.h>

packet_eht_t *deserialize_eht(char **args)
{
	packet_eht_t *packet = malloc(sizeof(*packet));

	if (!packet)
		return (NULL);
	parse_uint(args[0], &packet->egg);
	return (packet);
}
