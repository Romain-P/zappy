/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Broadcast
*/

#include "zappy.h"

int get_forward_broadcast(player_t *receiver)
{
	switch(receiver->orientation) {
		case 1:
			return forward;
		case 2:
			return left;
		case 3:
			return backward;
		case 4:
			return right;
	}
	return (none);
}

int get_backward_broadcast(player_t *receiver)
{
	switch(receiver->orientation) {
		case 1:
			return backward;
		case 2:
			return right;
		case 3:
			return forward;
		case 4:
			return left;
	}
	return (none);
}

int get_left_broadcast(player_t *receiver)
{
	switch(receiver->orientation) {
		case 1:
			return left;
		case 2:
			return backward;
		case 3:
			return right;
		case 4:
			return forward;
	}
	return (none);
}

int get_right_broadcast(player_t *receiver)
{
	switch(receiver->orientation) {
		case 1:
			return right;
		case 2:
			return forward;
		case 3:
			return left;
		case 4:
			return backward;
	}
	return (none);
}

int get_final_direction(tile_t d, player_t *p)
{
	switch (d) {
		case forward:
			return (get_forward_broadcast(p));
		case backward:
			return (get_backward_broadcast(p));
		case left:
			return (get_left_broadcast(p));
		case right:
			return (get_right_broadcast(p));
		case none:
			return (none);
	}
	return (none);
}