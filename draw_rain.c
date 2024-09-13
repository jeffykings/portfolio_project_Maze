#include "main.h"

/**
 * draw_rain - Draws the rain effect on the screen.
 *
 * @renderer: Pointer to the SDL_Renderer.
 * @is_raining: The rain state variable.
 * @rain_drops: Array of SDL_Rect representing rain drops.
 * @num_drops: Number of rain drops.
 */

void draw_rain(SDL_Renderer *renderer, int is_raining, SDL_Rect *rain_drops, int num_drops)
{
	if (!is_raining)
		return;
	
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	
	for (int i = 0; i < num_drops; i++)
	{
		SDL_RenderFillRect(renderer, &rain_drops[i]);
		rain_drops[i].y += rain_drops[i].h;
		
		if (rain_drops[i].y > 480)
		{
			rain_drops[i].y = -rain_drops[i].h;
		}
	}
}
