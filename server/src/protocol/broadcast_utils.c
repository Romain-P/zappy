/*
** EPITECH PROJECT, 2018
** ZAPPY
** File description:
** Broadcast Utils
*/

#include "protocol.h"
#include "util.h"
#include "zappy.h"

int get_good_orientation(int orientation_src, size_t orientation_dest, int orientation)
{
	if (orientation_dest == 0)
		return (orientation_src);
	if (orientation_dest == 1) {
		if (8 <= orientation_src + 4)
			return (orientation_src + 4);
		else
			return ((orientation_src + 4) % 8);
	}
	if (orientation_dest == 3) {
		if (8 <= orientation_src + 2)
			return (orientation_src + 2);
		else
			return ((orientation_src + 2) % 8);
	}
	if (orientation_dest == 2) {
		if (8 <= orientation_src + 4) {
			return (orientation_src + 4);
		}
		else {
			return ((orientation_src + 4) % 8);
		}
	}
	return (-1);
}

int get_broadcast_orientation(int x, int y, size_t orientation)
{
	if (y == x && x == 0)
		return (0);
	if (x == 0 && y >= 0)
		return (get_good_orientation(1, orientation, 0));
	if (x == 0 && y < 0)
		return (get_good_orientation(5, orientation, 0));
	if (y == 0 && x >= 0)
		return (get_good_orientation(7, orientation, 0));
	if (y == 0 && x < 0)
		return (get_good_orientation(3, orientation, 0));
	return (-1);
}

int get_valid_broadcast_direction(int orientation)
{
	if (orientation >= 9)
		return (orientation - 8);
	return (orientation);
}

int get_direction_by_angle(double angle, size_t orien)
{
	if (angle >= (-M_PI_4 - (M_PI / 8)) &&
	angle <= (-M_PI_4 + (M_PI / 8)))
		return (get_good_orientation(6, orien, 0));
	if (angle >= (-M_PI_2 - (M_PI / 8)) &&
	angle <= (-M_PI_2 + (M_PI / 8)))
		return (get_good_orientation(5, orien, 0));
	if (angle >= (-M_PI_4 * 3 - (M_PI / 8)) &&
	angle <= (-M_PI_4 * 3 + (M_PI / 8)))
		return (get_good_orientation(4, orien, 0));
	if (angle >= (M_PI_4 * 3 - (M_PI / 8)) &&
	angle <= (M_PI_4 * 3 + (M_PI / 8)))
		return (get_good_orientation(2, orien, 0));
	if (angle >= (M_PI_2 - (M_PI / 8)) &&
	angle <= (M_PI_2 + (M_PI / 8)))
		return (get_good_orientation(1, orien, 0));
	if (angle >= (M_PI_4 - (M_PI / 8)) &&
	angle <= (M_PI_4 + (M_PI / 8)))
		return (get_good_orientation(8, orien, 0));
	if (angle >= (0 - (M_PI / 8)) && angle <= (0 + (M_PI / 8)))
		return (get_good_orientation(7, orien, 0));
	return (get_good_orientation(3, orien, 0));
}

int get_sound_player(player_t *p1, player_t *p2)
{
	player_t *pl1;
	player_t *pl2;
	int x;
	int y;
	int valid;

	pl1 = correct_orientation_player(p1);
	pl2 = correct_orientation_player(p2);
	x = (int) pl1->x - (int) pl2->x;
	y = (int) pl1->y - (int)pl2->y;
	loop_segment(&x, &y, (int) (server.map).width, (int) (server.map).height);
	valid =
	get_valid_broadcast_direction(
		get_broadcast_orientation(x, y, pl2->orientation));
	if (valid != -1)
		return (valid);
	valid = get_direction_by_angle(atan2(y, x), pl2->orientation);
	valid = get_valid_broadcast_direction(valid);
	if (valid == -1)
		valid = 0;
	return (valid);
}