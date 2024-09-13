#include "main.h"

/**
 * draw_textured_walls - Draws walls with textures on the window.
 *
 * @renderer: Pointer to the SDL_Renderer.
 * @textures: Array of textures for different wall orientations.
 * @map: 2D array representing the map layout.
 * @map_width: Width of the map.
 * @map_height: Height of the map.
 * @player_x: X coordinate of the player.
 * @player_y: Y coordinate of the player.
 * @player_angle: Angle of the player's view.
 */

void draw_textured_walls(SDL_Renderer *renderer, SDL_Texture **textures, int **map,
		int map_width, int map_height, float player_x, float player_y, float player_angle)
{
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

			/* Set texture based on the map value */
			SDL_Texture *texture = NULL;
			
			if (map[y][x] == 1) /* Wall */
			{
				texture = textures[0]; /* Use the texture for walls */
			}
			else /* Empty space */
			{
				continue; /* Skip empty spaces */
			}

			/* Render the texture */
			SDL_RenderCopy(renderer, texture, NULL, &tile);
		}
	}
}
