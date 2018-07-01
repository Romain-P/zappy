/*
** EPITECH PROJECT, 2018
** Zappy
** File description:
** Util Header
*/

#ifndef MYIRC_UTIL_H
	#define MYIRC_UTIL_H

	#include <stdbool.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdio.h>
	#include <sys/types.h>
	#include "network_epoll.h"

	#define not_split(x) (!(x) || !(*(x)) || !(x)[1])

	char **charset_split(char const *, size_t, char const *);
	size_t str_array_length(char **);
	bool charset_ends_with(char const *, size_t, char const *);
	void str_free_array(char **);
	bool parse_int(char const *, int64_t *);
	char *to_string(int);
	int read_content(int, epoll_t, epoll_config_t, void *);
	bool parse_uint(char const *, uint32_t *);

#endif
