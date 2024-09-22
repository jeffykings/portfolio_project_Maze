#include "main.h"

/**
 * clear_screen - Clears the screen to a specified color
 */

void clear_screen(void)
{
	/** Clear screen to black **/
	SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, 255);
	SDL_RenderClear(gRenderer);
}
