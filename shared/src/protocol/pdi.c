/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PDI Command
*/

#include <zappy_network.h>
#include <stdlib.h>
#include <util.h>

packet_pdi_t *deserialize_pdi(char **args)
{
	packet_pdi_t *packet = malloc(sizeof(*packet));

	if (!packet)
		return (NULL);
	parse_uint(args[0], &packet->player_number);
	return (packet);
}