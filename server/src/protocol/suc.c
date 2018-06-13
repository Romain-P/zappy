/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** SUC Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void suc_handler(player_t *player, packet_suc_t *packet)
{
	send_packet(player->client, "suc", &packet);
}

void suc_serialize(packet_suc_t *packet, list_t *buffer)
{
	(void) packet;
	(void) buffer;
}