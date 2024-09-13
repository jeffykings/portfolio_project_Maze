#include "main.h"

/**
 * draw_weapons - Draws weapon textures on the screen.
 * 
 * @renderer: Pointer to the SDL_Renderer.
 * @textures: Array of weapon textures.
 * @num_weapons: Number of weapon textures.
 * @current_weapon: Index of the currently equipped weapon.
 * @x: X coordinate for the weapon display.
 * @y: Y coordinate for the weapon display.
 */

void draw_weapons(SDL_Renderer *renderer, SDL_Texture **textures, int num_weapons, int current_weapon, int x, int y)
{
	if (current_weapon < 0 || current_weapon >= num_weapons)
	{
		fprintf(stderr, "Invalid weapon index: %d\n", current_weapon);
		return;
	}

	SDL_Rect dest;
	dest.x = x;
	dest.y = y;
	dest.w = 64;  /* Width of the weapon texture */
	dest.h = 64;  /* Height of the weapon texture */

	SDL_RenderCopy(renderer, textures[current_weapon], NULL, &dest);
}
