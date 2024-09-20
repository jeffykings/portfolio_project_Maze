#include "main.h"

/**
 * handle_events - Basic event loop to keep the window open
 */

void handle_events()
{
	SDL_Event e;
	int quit = 0;

	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = 1;
			}
		}
		
		/** Clear screen **/
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(gRenderer);

		/** Render objects here **/

		/** Update screen **/
		SDL_RenderPresent(gRenderer);
	}
}
