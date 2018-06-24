/*
** EPITECH PROJECT, 2018
** pdi
** File description:
** pdi.c
*/

#include <zappy_network.h>
#include <stdlib.h>
#include <util.h>

packet_pdi_t *deserialize_pdi(char **args)
{
	packet_pdi_t *packet = malloc(sizeof(*packet));
	if (!packet)
		return (NULL);
	parse_int(args[0], (int64_t *) &packet->player_number);
	return (packet);
}
