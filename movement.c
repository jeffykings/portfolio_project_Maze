#include "main.h"

#define ROT_SPEED 0.03

/**
 * update_player_position - Updates the player's position and direction based on input
 * @keystate: Array representing the state of all keys
 */

void update_player_position(const Uint8 *keystate)
{
	/** Move forward **/
	
	if (keystate[SDL_SCANCODE_W])
	{
		if (worldMap[(int)(posX + dirX * MOVE_SPEED)][(int)posY] == 0) posX += dirX * MOVE_SPEED;
		if (worldMap[(int)posX][(int)(posY + dirY * MOVE_SPEED)] == 0) posY += dirY * MOVE_SPEED;
	}
	
	/** Move backward **/
	if (keystate[SDL_SCANCODE_S])
	{
		if (worldMap[(int)(posX - dirX * MOVE_SPEED)][(int)posY] == 0) posX -= dirX * MOVE_SPEED;
		if (worldMap[(int)posX][(int)(posY - dirY * MOVE_SPEED)] == 0) posY -= dirY * MOVE_SPEED;
	}

	/** Rotate to the right **/
	if (keystate[SDL_SCANCODE_D])
	{
		double oldDirX = dirX;
		dirX = dirX * cos(-ROT_SPEED) - dirY * cos(-ROT_SPEED);
		dirY = oldDirX * sin(-ROT_SPEED) + dirY * cos(-ROT_SPEED);
		double oldPlaneX = planeX;
		planeX = planeX * cos(-ROT_SPEED) - planeY * sin(-ROT_SPEED);
		planeY = oldPlaneX * sin(-ROT_SPEED) + planeY * cos(-ROT_SPEED);
	}

	/** Rotate to the left **/
	
	if (keystate[SDL_SCANCODE_A])
	{
		double oldDirX = dirX;
		dirX = dirX * cos(ROT_SPEED) - dirY * sin(ROT_SPEED);
		dirY = oldDirX * sin(ROT_SPEED) + dirY * cos(ROT_SPEED);
		double oldPlaneX = planeX;
		planeX = planeX * cos(ROT_SPEED) - planeY * sin(ROT_SPEED);
		planeY = oldPlaneX * sin(ROT_SPEED) + planeY * cos(ROT_SPEED);
	}
}
