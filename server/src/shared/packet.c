/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Packet Utils
*/

#include "network.h"
#include "util.h"
#include "network_epoll.h"

void destroy_packet(network_client_t *client,
	char **split, size_t len, bool data_remaining)
{
	if (data_remaining) {
		if (client->bstate != FREED)
			free(client->buffer);
		client->length = strlen(split[len - 1]);
		client->buffer = malloc(sizeof(char) * (client->length));
		if (client->buffer == NULL)
			exit(84);
		strncpy(client->buffer, split[len - 1], client->length);
	} else if (client->bstate != FREED) {
		free(client->buffer);
		client->bstate = FREED;
	}
	str_free_array(split);
}

int read_receive_packet(network_client_t *client, bool data_remaining,
	char **split, network_server_t *server)
{
	char *packet;
	size_t i;
	int data;
	size_t len = str_array_length(split);
	size_t max_size = server->config->packet_max_size;

	for (i = 0; i < len - data_remaining; ++i) {
		packet = split[i];
		data = check_too_much_data(client, server, max_size, packet);
		if (data == 1)
			return (1);
	}
	return (0);
}

void network_client_read(network_server_t *server,
	network_client_t *client,
	char *buffer,
	size_t length)
{
	size_t max_size = server->config->packet_max_size;
	char const *delimiter = server->config->packet_delimiter;
	char **split;
	size_t len;
	bool data_remaining;

	initialize_buffer(client, length, buffer);
	split = charset_split(client->buffer, client->length, delimiter);
	len = str_array_length(split);
	data_remaining = !charset_ends_with(buffer, length, delimiter);
	if (data_remaining && not_split(split)
		&& too_much_data(client, client->length, max_size))
		destroy_packet(client, split, len, data_remaining);
	else
		read_receive_packet(client, data_remaining, split, server);
	destroy_packet(client, split, len, data_remaining);
}

void initialize_buffer(network_client_t *client, size_t length, char *buffer)
{
	if (client->bstate == FREED) {
		client->buffer = malloc(sizeof(char) * length);
		client->length = 0;
		client->bstate = INCOMPLETE;
	}
	else if (client->bstate == INCOMPLETE) {
		client->buffer =
		realloc(
		client->buffer, sizeof(char) * (client->length + length));
	}
	strncpy(client->buffer + client->length, buffer, length);
	client->length += length;
}

int check_too_much_data(network_client_t *client,
	network_server_t *server, size_t max_size, char *packet)
{
	size_t packet_length = strlen(packet);

	if (!too_much_data(client, packet_length, max_size)) {
		server->client_handler.on_received(client,
		packet, packet_length);
		if (client->closed)
			return (1);
	}
	return (0);
}