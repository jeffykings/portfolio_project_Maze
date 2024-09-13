#include "main.h"

/**
 * handle_collisions - Handles collisions of the player with the walls.
 *
 * @player_x: Pointer to the player's x-coordinate to be updated.
 * @player_y: Pointer to the player's y-coordinate to be updated.
 * @map: 2D array representing the map layout.
 * @map_width: Width of the map.
 * @map_height: Height of the map.
 * @move_x: The intended movement in the x direction.
 * @move_y: The intended movement in the y direction.
 */

void handle_collisions(float *player_x, float *player_y, int **map, int map_width, int map_height,
		float move_x, float move_y)
{
	float new_x = *player_x + move_x;
	float new_y = *player_y + move_y;

	/* Ensure the new position is within map bounds */
	if (new_x >= 0 && new_x < map_width && new_y >= 0 && new_y < map_height)
	{
		/* Check for collision with walls */
		if (map[(int)new_y][(int)new_x] == 0)
		{
			*player_x = new_x;
			*player_y = new_y;
		}
	}
}
