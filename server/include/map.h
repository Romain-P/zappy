/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Map Management
*/

#ifndef MAP_H_
	#define MAP_H_

	#include <stdlib.h>

	void set_width_map(size_t);
	void set_height_map(size_t);
	void set_max_ressource_map(void);
	static void set_ressource_in_map(size_t, size_t, size_t);
	void generate_ressource(void);

#endif /* !MAP_H_ */
