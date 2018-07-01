/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** welcome
*/

#include <zappy_network.h>
#include <stdlib.h>

packet_welcome_t *deserialize_welcome(char **args)
{
	packet_welcome_t *packet = malloc(sizeof(*packet));

	if (!packet)
		return (NULL);
	return (packet);
}