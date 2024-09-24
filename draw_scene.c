#include "main.h"

/**
 * draw_scene - Draws the entire scene including walls, floor, ceiling
 */

void draw_scene(void)
{
	clear_screen();
	render_floor_ceiling();
	render_walls();
	draw_map();
	SDL_RenderPresent(gRenderer);
}
