#include "main.h"

/**
 * move_camera - Moves the camera based on keyboard input
 * @keystate: The current state of the keyboard
 */

void move_camera(const Uint8 *keystate)
{
	double moveSpeed = 0.05; /** Move speed **/
	double newX, newY;

	if (keystate[SDL_SCANCODE_W])
	{
		newX = posX + dirX * moveSpeed;
		newY = posY + dirY * moveSpeed;
		if (!check_collision(newX, newY)) /** Check collision **/
		{
			posX = newX;
			posY = newY;
		}
	}
	if (keystate[SDL_SCANCODE_S])
	{
		newX = posX - dirX * moveSpeed;
		newY = posY - dirY * moveSpeed;
		if (!check_collision(newX, newY)) /** Check collision **/
		{
			posX = newX;
			posY = newY;
		}
	}
	if (keystate[SDL_SCANCODE_A])
	{
		newX = posX - planeX * moveSpeed;
		newY = posY - planeY * moveSpeed;
		if (!check_collision(newX, newY)) /** Check collision **/
		{
			posX = newX;
			posY = newY;
		}
	}
	if (keystate[SDL_SCANCODE_D])
	{
		newX = posX + planeX * moveSpeed;
		newY = posY + planeY * moveSpeed;
		if (!check_collision(newX, newY)) /** Check collision **/
		{
			posX = newX;
			posY = newY;
		}
	}
}
