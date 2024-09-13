#include "main.h"

/**
 * draw_map - Draws the map on the window.
 *
 * @renderer: Pointer to the SDL_Renderer.
 * @map: 2D array representing the map layout.
 * @map_width: Width of the map.
 * @map_height: Height of the map.
 * @show_map: Boolean flag to determine if the map should be drawn.
 */

void draw_map(SDL_Renderer *renderer, int **map, int map_width, int map_height, int show_map)
{
	/* Return immediately if map should not be shown */
	if (!show_map)
		return;
	
	int tile_size = 20; /* Size of each tile */
	SDL_Rect tile; /* Rectangle representing a tile */

	/* Loop through each cell of the map */
	for (int y = 0; y < map_height; y++)
	{
		for (int x = 0; x < map_width; x++)
		{
			tile.x = x * tile_size; /* X position of the tile */
			tile.y = y * tile_size; /* Y position of the tile */
			tile.w = tile_size; /* Width of the tile */
			tile.h = tile_size; /* Height of the tile */
			
			/* Set color based on the map value */
			if (map[y][x] == 1) /* Wall */
			{
				SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); /* Red for walls */
			}
			else /* Empty space */
			{
				SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); /* Green for empty space */
			}

			SDL_RenderFillRect(renderer, &tile); /* Draw the tile */
		}
	}
}
