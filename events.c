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
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						quit = 1;
						break;
						/** Add more event handling here as needed **/
				}
			}
		}
		
		/*perorm Update screen **/
		perform_raycasting();

		/** Update the screen with the rendering**/
		SDL_RenderPresent(gRenderer);
	}
}
