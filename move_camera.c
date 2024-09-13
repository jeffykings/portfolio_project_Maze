#include "main.h"

/**
 * move_camera - Moves the camera position based on user input.
 *
 * @player_x: Pointer to the player's x-coordinate to be updated.
 * @player_y: Pointer to the player's y-coordinate to be updated.
 * @player_angle: Angle of the player's view direction.
 * @move_forward: Boolean flag to move the player forward.
 * @move_backward: Boolean flag to move the player backward.
 * @move_left: Boolean flag to move the player left.
 * @move_right: Boolean flag to move the player right.
 * @map: 2D array representing the map layout.
 * @map_width: Width of the map.
 * @map_height: Height of the map.
 */

void move_camera(float *player_x, float *player_y, float player_angle,
	       	int move_forward, int move_backward, int move_left, int move_right,
		int **map, int map_width, int map_height)
{
	float move_speed = 0.1;
	float new_x = *player_x;
	float new_y = *player_y;

	/* Compute the direction vectors */
	float dir_x = cos(player_angle) * move_speed;
	float dir_y = sin(player_angle) * move_speed;

	/* Compute new position based on input */
	if (move_forward)
	{
		new_x += dir_x;
		new_y += dir_y;
	}
	if (move_backward)
	{
		new_x -= dir_x;
		new_y -= dir_y;
	}
	if (move_left)
	{
	new_x -= dir_y;
	new_y += dir_x;
	}
	if (move_right)
	{
	new_x += dir_y;
	new_y -= dir_x;
	}

	/* Check for collisions and update position if no collision */
	if (new_x >= 0 && new_x < map_width && new_y >= 0 && new_y < map_height &&
			map[(int)new_y][(int)new_x] == 0)
	{
		*player_x = new_x;
		*player_y = new_y;
	}
}
