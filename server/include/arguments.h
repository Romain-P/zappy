/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Arguments
*/

#ifndef ARGUMENTS_H_
	#define ARGUMENTS_H_

	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include <unistd.h>

	void get_arguments(int, char**);
	static void print_usage(void);
	static int set_argument(int);
	static void initialize_options(void);

#endif /* !ARGUMENTS_H_ */
