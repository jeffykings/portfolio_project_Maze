#include "main.h"

/**
 * rotate_camera - Rotates the camera based on keyboard input
 * @keystate: The current state of the keyboard
 */

void rotate_camera(const Uint8 *keystate)
{
	double oldDirX, oldPlaneX;
	double rotSpeed = 0.05; /** Rotation speed **/

	if (keystate[SDL_SCANCODE_LEFT])
	{
		/** Rotate to the left **/
		oldDirX = dirX;
		dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
		dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
		oldPlaneX = planeX;
		planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
		planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
	}

	if (keystate[SDL_SCANCODE_RIGHT])
	{
		/** Rotate to the right **/
		oldDirX = dirX;
		dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
		dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
		oldPlaneX = planeX;
		planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
		planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
	}
}
