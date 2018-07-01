/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PBC
*/

#include <zappy_network.h>
#include <util.h>
#include <stdlib.h>
#include <string.h>

packet_pbc_t *deserialize_pbc(char **args)
{
	packet_pbc_t *packet = malloc(sizeof(*packet));

	if (!packet)
		return (NULL);
	parse_uint(args[0], &packet->player_number);
	strcpy(packet->message, args[1]);
	return (packet);
}
