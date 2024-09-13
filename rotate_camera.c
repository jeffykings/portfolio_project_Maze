#include "main.h"

/**
 * rotate_camera - Rotates the camera view direction.
 *
 * @player_angle: Pointer to the player's angle to be updated.
 * @rotation_speed: The speed at which the camera rotates.
 * @rotate_left: Boolean flag to rotate left or right.
 */

void rotate_camera(float *player_angle, float rotation_speed, int rotate_left)
{
	if (rotate_left)
	{
		*player_angle -= rotation_speed;
	}
	else
	{
		*player_angle += rotation_speed;
	}

       	/* Ensure the angle stays within [0, 2*PI) */
	if (*player_angle < 0)
	{
		*player_angle += 2 * M_PI;
	}
	else if (*player_angle >= 2 * M_PI)
	{
		*player_angle -= 2 * M_PI;
        }
}
