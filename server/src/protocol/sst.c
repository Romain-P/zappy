/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** SST Command
*/

#include <protocol.h>
#include <util.h>
#include <zappy.h>
#include <stdlib.h>

packet_sst_t *sst_deserialize(char **args)
{
	packet_sst_t *packet;
	
	if (str_array_length(args) != 1)
		return (NULL);
	packet = malloc(sizeof(*packet));
	if (packet == NULL)
		return (NULL);
	if (!parse_int(args[0], &packet->time)) {
		free(packet);
		return (NULL);
	}
	return (packet);
}

void sst_handler(player_t *player, packet_sst_t *packet)
{
    packet->time = 0;
    send_packet(player->client, "sst", &packet);
}

void sst_serialize(packet_sst_t *packet, list_t *buffer)
{
    list_add(buffer, to_string(packet->time));
}