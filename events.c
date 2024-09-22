#include "main.h"

/**
 * handle_events - Basic event loop to keep the window open
 */

void handle_events()
{
	SDL_Event e;
	bool quit = false;
	const Uint8 *keystate = SDL_GetKeyboardState(NULL);

	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
					case SDLK_ESCAPE:
						quit = true;
						break;
				}
			}
		}

		/**  Update player position based on keyboard state **/
		update_player_position(keystate);

		SDL_RenderClear(gRenderer);
		
		/*perorm Update screen **/
		perform_raycasting();

		/** Update the screen with the rendering**/
		SDL_RenderPresent(gRenderer);
	}
}
