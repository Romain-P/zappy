/*
** EPITECH PROJECT, 2018
** pie
** File description:
** pie.c
*/

#include <zappy_network.h>
#include <stdlib.h>
#include <util.h>

packet_pie_t *deserialize_pie(char **args)
{
	packet_pie_t *packet = malloc(sizeof(*packet));
	if (!packet)
		return (NULL);
	parse_int(args[0], (int64_t *) &packet->x);
	parse_int(args[1], (int64_t *) &packet->y);
	parse_int(args[2], (int64_t *) &packet->result);
	return (packet);
}
