/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Pex Command
*/

#include <zappy_network.h>
#include <stdlib.h>
#include <util.h>

packet_pex_t *deserialize_pex(char **args)
{
	packet_pex_t *packet = malloc(sizeof(*packet));

	if (!packet)
		return (NULL);
	parse_uint(args[0], &packet->player_number);
	return (packet);
}