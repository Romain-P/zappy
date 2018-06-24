/*
** EPITECH PROJECT, 2018
** pex
** File description:
** pex.c
*/

#include <zappy_network.h>
#include <stdlib.h>
#include <util.h>

packet_pex_t *deserialize_pex(char **args)
{
	packet_pex_t *packet = malloc(sizeof(*packet));
	if (!packet)
		return (NULL);
	parse_int(args[0], (int64_t *) &packet->player_number);
	return (packet);
}
