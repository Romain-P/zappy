//
// Created by romain on 18/06/18.
//

#include "zappy.h"

static size_t const MAX_COMMANDS = 10;
static time_t exec_time;

int to_seconds(int tics) {
    return tics / server.freq;
}

static bool inserter(waiting_t *waiting) {
    return exec_time < waiting->exec_time;
}

bool delay(void *packet, handler_t handler, player_t *player, int tics) {
    if (player->waiting_commands >= MAX_COMMANDS)
        return false;
    ((network_packet_t *) packet)->delayed = true;
    exec_time = time(NULL) + to_seconds(tics) * 1000;
    player->waiting_commands++;
    waiting_t *waiting = malloc(sizeof(*waiting));
    waiting->player = player;
    waiting->exec_time = to_seconds(tics);
    waiting->command_handler = handler;
    waiting->packet = packet;
    list_insert(&server.waiting_commands, waiting, (predicate_t) &inserter);
    return true;
}

void check_delayed_tasks() {
    time_t current_time = time(NULL);

    for (iter_t *it = iter_begin(&server.waiting_commands); it;) {
        waiting_t *waiting = it->data;
        iter_next(it);

        if (current_time >= waiting->exec_time) {
            waiting->command_handler(waiting->player, waiting->packet);
            list_remove(&server.waiting_commands, waiting);
            waiting->player->waiting_commands--;
            free(waiting->packet);
            free(waiting);
        } else
            break;
    }
}