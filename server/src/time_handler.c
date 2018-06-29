/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Time Handler
*/

#include <unistd.h>
#include <stderr.h>
#include "zappy.h"

static size_t const MAX_COMMANDS = 10;
static time_t exec_time;

int to_seconds(int tics)
{
	return (tics / server.freq);
}

static bool inserter(waiting_t *waiting)
{
	printf("valid: %d\n", exec_time < waiting->start_time + to_seconds(waiting->tics));
	return
	(exec_time < waiting->start_time + to_seconds(waiting->tics));
}

bool delay(void *packet, handler_t handler, player_t *player, int tics)
{
	waiting_t *waiting;

	if (player->waiting_commands >= MAX_COMMANDS)
		return (false);
	((network_packet_t *) packet)->delayed = true;
	exec_time = time(NULL) + to_seconds(tics);
	player->waiting_commands++;
	waiting = malloc(sizeof(*waiting));
	if (waiting == NULL)
		exit(84);
	waiting->player = player;
	waiting->start_time = time(NULL);
	waiting->command_handler = handler;
	waiting->packet = packet;
	waiting->tics = tics;
	list_insert(&server.pending, waiting, (predicate_t) &inserter);
	return (true);
}

void check_delayed_tasks(void)
{
	time_t current_time = time(NULL);
	iter_t *it;
	waiting_t *waiting;

	for (it = iter_begin(&server.pending); it;) {
		waiting = it->data;
		iter_next(it);
		if (current_time >=
		waiting->start_time + to_seconds(waiting->tics)) {
			waiting->command_handler(waiting->player,
			waiting->packet);
			list_remove(&server.pending, waiting);
			waiting->player->waiting_commands--;
			free(waiting->packet);
			free(waiting);
		} else
			break;
	}
}