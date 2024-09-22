#include "main.h"

/**
 * draw_map - Draws the mini-map on the screen
 */

void draw_map(void)
{
	/** Set mini-map size and scale **/
	int mapScale = 5;
	int mapX = 10;
	int mapY = 10;

	/** Loop through the world map to draw it on the screen **/
	for (int y = 0; y < 24; y++)
	{
		for (int x = 0; x < 24; x++)
		{
			/** Choose color based on map value **/
			if (worldMap[x][y] > 0)
			{
				SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255); /** White for walls **/
			}
			else
			{
				SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255); /** Black for empty space **/
			}

			/** Draw the map cell **/
			SDL_Rect cell = {mapX + x * mapScale, mapY + y * mapScale, mapScale, mapScale};
			SDL_RenderFillRect(gRenderer, &cell);
		}
	}

	/** Draw the player on the map **/
	SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255); /** Red for player **/
	SDL_Rect player = {mapX + (int)(posX * mapScale) - mapScale / 2, 
		mapY + (int)(posY * mapScale) - mapScale / 2, 
		mapScale, mapScale};
	SDL_RenderFillRect(gRenderer, &player);
}
