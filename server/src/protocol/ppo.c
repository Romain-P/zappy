/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** PPO Command
*/

#include <protocol.h>
#include <util.h>
#include <zappy.h>
#include <stdlib.h>

packet_ppo_t *ppo_deserialize(char **args)
{
	packet_ppo_t *packet;

	if (str_array_length(args) != 1)
		return (NULL);
	packet = malloc(sizeof(*packet));
	if (packet == NULL)
		return (NULL);
	if (args[0][0] == '#')
		args[0]++;
	if (!parse_int(args[0], &packet->player_number)) {
		free(packet);
		return (NULL);
	}
	return (packet);
}

void ppo_handler(player_t *player, packet_ppo_t *packet)
{
	packet->x = 50;
	packet->y = 50;
	packet->orientation = 1;
	send_packet(player->client, "ppo", &packet);
}

void ppo_serialize(packet_ppo_t *packet, list_t *buffer)
{
	list_add(buffer, to_string(packet->player_number));
	list_add(buffer, to_string(packet->x));
	list_add(buffer, to_string(packet->y));
	list_add(buffer, to_string(packet->orientation));
}