/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Server Header
*/

#ifndef ZAPPY_H_
	#define ZAPPY_H_

	#define ZAPPY_BUFFER_SIZE (2048)
	#define ZAPPY_ARG_DELIMITER ("\n")
	#define ZAPPY_PARAM_SEPARATOR (" ")

	#include <time.h>
	#include "network.h"
	#include "team.h"

	typedef struct command_s message_t;
	typedef struct zappy_instance_s zappy_instance_t;
	typedef struct player_s player_t;
	typedef struct team_s team_t;
	typedef struct map_s map_t;
	typedef struct resource_s resource_t;
	typedef struct inventory_s inventory_t;
	typedef struct egg_s egg_t;
	typedef struct waiting_s waiting_t;
	typedef enum resource_type_e resource_type_t;
	typedef enum protocol_state_e protocol_state_t;

	extern zappy_instance_t server;

	enum protocol_state_e {
		AWAIT_TEAM_NAME,
		VALID_PLAYER
	};

	struct team_s {
		char *name;
		int player;
	};

	struct inventory_s {
		size_t q0;
		size_t q1;
		size_t q2;
		size_t q3;
		size_t q4;
		size_t q5;
		size_t q6;
	};

	struct player_s {
		network_client_t *client;
		protocol_state_t state;
		size_t x;
		size_t y;
		size_t orientation;
		size_t level;
		team_t team;
		inventory_t inventory;
		list_t eggs;
		size_t waiting_commands;
	};

	struct map_s {
		size_t width;
		size_t height;
		size_t max;
		size_t nb_ressource;
		size_t nb_eggs;
		list_t ressources;
		list_t eggs;
	};

	struct egg_s {
		size_t id;
		size_t x;
		size_t y;
	};

	enum resource_type_e {
		FOOD = 0,
		LINEMATE = 1,
		DERAUMERE = 2,
		SIBUR = 3,
		MENDIANE = 4,
		PHIRAS = 5,
		THYSTAME = 6
	};

	struct resource_s {
		size_t x;
		size_t y;
		resource_type_t type;
	};

	struct zappy_instance_s {
		list_t players;
		int port;
		size_t width;
		size_t height;
		char *name;
		int nb_clients;
		int freq;
		list_t teams;
		map_t map;
		size_t number_egg;
		list_t pending;
	};

	typedef bool (*handler_t)(player_t *, void *);
	typedef void (*serialize_t)(void *, list_t *);
	typedef void *(*deserialize_t)(char **);

	struct waiting_s {
		player_t *player;
		time_t start_time;
		int tics;
		handler_t command_handler;
		void *packet;
	};

	struct command_s {
		char const *named;
		serialize_t serialize;
		deserialize_t deserialize;
		handler_t handler;
	};

	void configure_client_handler(client_handler_t *);
	void parse_packet(network_client_t *, char const *, size_t);
	void send_packet(network_client_t *, void *);
	void send_unwrapped(network_client_t *, char *);
	player_t *find_player(network_client_t *);
	int to_seconds(int);
	bool delay(void *, handler_t, player_t *, int);
	void check_delayed_tasks();

#endif
