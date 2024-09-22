#include "main.h"

/**
 * pdate_player_position - Updates the player's position and direction based on input
 * @keystate: Array representing the state of all keys
 */

void update_player_position(const Uint8 *keystate)
{
	double newX, newY;

	if (keystate[SDL_SCANCODE_W])
	{
		newX = posX + dirX * MOVE_SPEED;
		newY = posY + dirY * MOVE_SPEED;
		if (!check_collision(newX, posY))
			posX = newX;
		if (!check_collision(posX, newY))
			posY = newY;
	}

	if (keystate[SDL_SCANCODE_S])
	{
		newX = posX - dirX * MOVE_SPEED;
		newY = posY - dirY * MOVE_SPEED;
		if (!check_collision(newX, posY))
			posX = newX;
		if (!check_collision(posX, newY))
			posY = newY;
	}

	if (keystate[SDL_SCANCODE_A])
	{
		double oldDirX = dirX;
		dirX = dirX * cos(-MOVE_SPEED) - dirY * sin(-MOVE_SPEED);
		dirY = oldDirX * sin(-MOVE_SPEED) + dirY * cos(-MOVE_SPEED);
		double oldPlaneX = planeX;
		planeX = planeX * cos(-MOVE_SPEED) - planeY * sin(-MOVE_SPEED);
		planeY = oldPlaneX * sin(-MOVE_SPEED) + planeY * cos(-MOVE_SPEED);
	}

	if (keystate[SDL_SCANCODE_D])
	{
		double oldDirX = dirX;
		dirX = dirX * cos(MOVE_SPEED) - dirY * sin(MOVE_SPEED);
		dirY = oldDirX * sin(MOVE_SPEED) + dirY * cos(MOVE_SPEED);
		double oldPlaneX = planeX;
		planeX = planeX * cos(MOVE_SPEED) - planeY * sin(MOVE_SPEED);
		planeY = oldPlaneX * sin(MOVE_SPEED) + planeY * cos(MOVE_SPEED);
	}
}

/**
 * check_collision - Checks for collisions and prevents movement through walls
 *
 * @newX: New X position to be checked
 * @newY: New Y position to be checked
 *
 * Return: 1 if there is a collision, 0 otherwise
 */

int check_collision(double newX, double newY)
{
	if (worldMap[(int)newX][(int)newY] == 1)
		return (1);
	return (0);
}
