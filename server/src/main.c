/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Main
*/

#include "linked_list.h"
#include "stderr.h"
#include "network.h"
#include "zappy.h"
#include "arguments.h"
#include "util.h"

zappy_instance_t server = {
	.players = list_init,
	.pending = list_init,
	.teams = list_init,
	.pending = list_init,
	.next_index = 1
};

//free anything we want (players already
//freed by network see @on_disconnect)
static void on_server_close(void)
{
}

int main(int ac, char **av)
{
	server_config_t config;
	network_server_t servers;

	get_arguments(ac, av);
	config.host = INADDR_ANY;
	config.port = (server.port);
	config.packet_delimiter = ZAPPY_ARG_DELIMITER;
	config.packet_max_size = ZAPPY_BUFFER_SIZE;
	config.configure_handlers = &configure_client_handler;
	config.on_server_close = &on_server_close;
	config.on_unblocked = &check_delayed_tasks;
	network_server_start(&servers, &config);
	return (0);
}