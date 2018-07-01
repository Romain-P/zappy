/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** sbp
*/

#include <zappy_network.h>
#include <stdlib.h>

packet_sbp_t *deserialize_sbp(char **args)
{
	packet_sbp_t *packet = malloc(sizeof(*packet));

	if (!packet)
		return (NULL);
	return (packet);
}