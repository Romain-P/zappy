/*
** EPITECH PROJECT, 2018
** seg
** File description:
** seg.c
*/

#include <zappy_network.h>
#include <stdlib.h>
#include <string.h>

packet_seg_t *deserialize_seg(char **args)
{
	packet_seg_t *packet = malloc(sizeof(*packet));
	if (!packet)
		return (NULL);
	strcpy(packet->team, args[0]);
	return (packet);
}
