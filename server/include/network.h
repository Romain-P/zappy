/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Network
*/

#ifndef MYIRC_NETWORK_H
#define MYIRC_NETWORK_H

	#include <sys/types.h>
	#include <stdbool.h>
	#include <stdint.h>
	#include <netinet/in.h>
	#include "linked_list.h"
	#include "network_epoll.h"

	#ifndef NETWORK_READ_SIZE
		#define NETWORK_READ_SIZE   (1024)
	#endif

	#define ERROR (-1)
	#define PACKET_HEADER \
	char const *cmd; \
	bool delayed

	typedef struct network_client_s network_client_t;
	typedef struct network_server_s network_server_t;
	typedef int session_t;
	typedef struct server_config_s server_config_t;
	typedef struct client_handler_s client_handler_t;
	typedef enum buffer_state_e buffer_state_t;
	typedef struct network_packet_s network_packet_t;

	enum buffer_state_e {
		FREED,
		INCOMPLETE,
		READY
	};

	struct __attribute__((__packed__)) network_packet_s {
		PACKET_HEADER;
	};

	struct network_client_s {
		session_t id;
		char *buffer;
		buffer_state_t bstate;
		size_t length;
		int status;
		network_server_t *server;
		bool closed;
	};

	struct client_handler_s {
		void (*on_connect)(network_client_t *);
		void (*on_disconnect)(network_client_t *);
		void (*on_received)(network_client_t *, char const *, size_t);
		void (*on_sent)(network_client_t *, char const *, size_t);
	};

	struct network_server_s {
		session_t id;
		session_t epoll_id;
		server_config_t *config;
		client_handler_t client_handler;
		list_t clients;
	};

	struct server_config_s {
		in_addr_t host;
		uint16_t port;
		char *packet_delimiter;
		size_t packet_max_size;
		void (*on_server_close)();
		void (*configure_handlers)(client_handler_t *);
		on_epoll_unblocked on_unblocked;
	};

	void network_server_start(network_server_t *, server_config_t *);
	void network_client_read(network_server_t *, network_client_t *, char *, size_t);
	void network_client_send(network_client_t *, char *, size_t);
	void network_client_close(network_client_t *);
	void network_client_free(void *);
	network_client_t *network_client_find(list_t *, session_t);

#endif //MYIRC_NETWORK_H
