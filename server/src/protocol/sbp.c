/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** SBP Command
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void sbp_handler(player_t *player, packet_sbp_t *packet)
{
	send_packet(player->client, "sbp", &packet);
}

void sbp_serialize(packet_sbp_t *packet, list_t *buffer)
{
	(void) packet;
	(void) buffer;
}