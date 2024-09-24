#include "main.h"

/**
 * render_floor_ceiling - Renders the floor and ceiling using textures
 */

void render_floor_ceiling(void)
{
	int y;
	for (y = 0; y < SCREEN_HEIGHT; y++)
	{
		double rayDirX0 = dirX - planeX;
		double rayDirY0 = dirY - planeY;
		double rayDirX1 = dirX + planeX;
		double rayDirY1 = dirY + planeY;

		int p = y - SCREEN_HEIGHT / 2;
		double posZ = 0.5 * SCREEN_HEIGHT;

		double rowDistance = posZ / p;

		double floorStepX = rowDistance * (rayDirX1 - rayDirX0) / SCREEN_WIDTH;
		double floorStepY = rowDistance * (rayDirY1 - rayDirY0) / SCREEN_WIDTH;

		double floorX = posX + rowDistance * rayDirX0;
		double floorY = posY + rowDistance * rayDirY0;

		int x;
		for (x = 0; x < SCREEN_WIDTH; x++)
		{
			int cellX = (int)floorX;
			int cellY = (int)floorY;

			int tx = (int)(64 * (floorX - cellX)) & (64 - 1);
			int ty = (int)(64 * (floorY - cellY)) & (64 - 1);

			floorX += floorStepX;
			floorY += floorStepY;

			SDL_Rect floorRect = {x, y + SCREEN_HEIGHT / 2, 1, 1};
			SDL_Rect ceilingRect = {x, SCREEN_HEIGHT / 2 - y - 1, 1, 1};

			SDL_RenderCopy(gRenderer, floorTexture, NULL, &floorRect);
			SDL_RenderCopy(gRenderer, ceilingTexture, NULL, &ceilingRect);
		}
	}
}
