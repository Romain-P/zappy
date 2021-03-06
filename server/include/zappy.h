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
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "network.h"

	typedef struct command_s message_t;
	typedef struct zappy_instance_s zappy_instance_t;
	typedef struct player_s player_t;
	typedef struct team_s team_t;
	typedef struct map_s map_t;
	typedef struct resource_s resource_t;
	typedef struct inventory_s inventory_t;
	typedef struct egg_s egg_t;
	typedef struct waiting_s waiting_t;
	typedef struct spawn_s spawn_t;
	typedef struct level_s level_t;
	typedef enum resource_type_e resource_type_t;
	typedef enum protocol_state_e protocol_state_t;
	typedef enum dir_e dir_t;
	typedef enum tile_e tile_t;

	extern zappy_instance_t server;

	enum protocol_state_e {
		AWAIT_TEAM_NAME,
		VALID_PLAYER
	};

	struct level_s {
		size_t level;
		size_t q1;
		size_t q2;
		size_t q3;
		size_t q4;
		size_t q5;
		size_t q6;
	};

	struct incantation_s {
		size_t level;
		size_t nb;
	};

	struct team_s {
		char *name;
		int player;
		list_t spawn;
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
		team_t *team;
		inventory_t inventory;
		list_t eggs;
		size_t waiting_commands;
		bool initialized;
		size_t is_gui;
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
		bool layed;
	};

	struct spawn_s {
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
		list_t pending_players;
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
		size_t next_index;
	};

	typedef bool (*handler_t)(player_t *, void *);
	typedef void (*serialize_t)(void *, list_t *);
	typedef void *(*deserialize_t)(char **);

	struct waiting_s {
		player_t *player;
		double start_time;
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

	enum tile_e {
		none = 0,
		forward = 1,
		right = 7,
		backward = 5,
		left = 3
	};

	enum dir_e {
		dirtop = 1,
		dirright = 2,
		dirdown = 3,
		dirleft = 4
	};

	void configure_client_handler(client_handler_t *);
	void parse_packet(network_client_t *, char const *, size_t);
	void send_packet(network_client_t *, void *, int);
	void send_unwrapped(network_client_t *, char *);
	player_t *find_player(network_client_t *);
	double to_seconds(double);
	bool delay(void *, handler_t, player_t *, int);
	void check_delayed_tasks();

#endif
