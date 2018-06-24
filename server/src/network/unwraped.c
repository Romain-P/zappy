/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Send Unwrapped
*/

#include "protocol.h"
#include "zappy.h"
#include "util.h"

void send_unwrapped(network_client_t *client, char *unwrapped)
{
	size_t len = strlen(unwrapped);
	char cmd[len + 1];

	strcpy(cmd, unwrapped);
	cmd[len] = '\n';
	network_client_send(client, cmd, len + 1);
}