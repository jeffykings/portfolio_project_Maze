#include "main.h"

/**
 * draw_enemies - Draws enemy textures on the screen.
 * renderer: Pointer to the SDL_Renderer.
 * @textures: Array of enemy textures.
 * @enemy_positions: Array of enemy positions.
 * @num_enemies: Number of enemies.
 */

void draw_enemies(SDL_Renderer *renderer, SDL_Texture **textures, SDL_Rect *enemy_positions, int num_enemies)
{
	for (int i = 0; i < num_enemies; i++)
	{
		SDL_RenderCopy(renderer, textures[i], NULL, &enemy_positions[i]);
	}
}
