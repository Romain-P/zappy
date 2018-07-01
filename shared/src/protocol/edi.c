/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Edi
*/

#include <zappy_network.h>
#include <stdlib.h>
#include <util.h>

packet_edi_t *deserialize_edi(char **args)
{
	packet_edi_t *packet = malloc(sizeof(*packet));

	if (!packet)
		return (NULL);
	parse_uint(args[0], &packet->egg);
	return (packet);
}