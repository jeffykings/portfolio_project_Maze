#include "main.h"

/**
 * apply_floor_ceiling_textures - Renders floor and ceiling textures
 */

void apply_floor_ceiling_textures(void)
{
	int y;
	for (y = 0; y < SCREEN_HEIGHT / 2; y++)
	{
		int p = y - SCREEN_HEIGHT / 2;
		double rowDistance = SCREEN_HEIGHT / (2.0 * y - SCREEN_HEIGHT);
		double floorX = posX + rowDistance * dirX;
		double floorY = posY + rowDistance * dirY;

		int cellX = (int)floorX;
		int cellY = (int)floorY;

		int tx = (int)(64 * (floorX - cellX)) & (64 - 1);
		int ty = (int)(64 * (floorY - cellY)) & (64 - 1);

		SDL_Rect floorSrc = { tx, ty, 1, 1 };
		SDL_Rect floorDest = { y, SCREEN_HEIGHT / 2 + p, 1, 1 };
		SDL_Rect ceilingDest = { y, SCREEN_HEIGHT / 2 - p, 1, 1 };

		SDL_RenderCopy(gRenderer, floorTexture, &floorSrc, &floorDest);
		SDL_RenderCopy(gRenderer, ceilingTexture, &floorSrc, &ceilingDest);
	}
}
