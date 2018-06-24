/*
** EPITECH PROJECT, 2018
** smg
** File description:
** smg.c
*/

#include <zappy_network.h>
#include <stdlib.h>
#include <string.h>

packet_smg_t *deserialize_smg(char **args)
{
	packet_smg_t *packet = malloc(sizeof(*packet));
	if (!packet)
		return (NULL);
	strcpy(packet->message, args[0]);
	return (packet);
}
