/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Look Header
*/

#ifndef LOOK_H_
	#define LOOK_H_

	#include "protocol.h"
	#include "zappy.h"
	#include <stdlib.h>

	char *get_content_tile(packet_look_t *);
	size_t count_player_on_tile(packet_look_t *);
	void count_ressource_on_tile(packet_look_t *);
	void get_type_in_tile(packet_look_t *, char *, size_t);
	void count_size_ressource(packet_look_t *, size_t *);
	void ajust_position(packet_look_t *);
	void increment_pos(packet_look_t *, player_t *);
	void get_start_coord(player_t *, packet_look_t *, size_t);
	void loop_tile(player_t *, packet_look_t *, size_t, char **);
	void increment_ressource(packet_look_t *, resource_type_t);
	void set_type(char *, char *, size_t, size_t *);
	size_t get_count_tile(size_t);
	char *prepare_packet_look(char **);
	char **get_result_look(player_t *, packet_look_t *);

#endif /* !LOOK_H_ */
