/*
** EPITECH PROJECT, 2018
** pgt
** File description:
** pgt.c
*/

#include <zappy_network.h>
#include <stdlib.h>
#include <util.h>

packet_pgt_t *deserialize_pgt(char **args)
{
	packet_pgt_t *packet = malloc(sizeof(*packet));
	if (!packet)
		return (NULL);
	parse_int(args[0], (int64_t *) &packet->player_number);
	parse_int(args[1], (int64_t *) &packet->ressource);
	return (packet);
}
