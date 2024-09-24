#include "main.h"

/**
 * handle_events - Basic event loop to keep the window open
 */

void handle_events()
{
	SDL_Event e;
	const Uint8 *keystate = SDL_GetKeyboardState(NULL);
	
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			close_SDL();
			exit(0);
		}
		if (e.type == SDL_KEYDOWN)
		{
			if (keystate[SDL_SCANCODE_ESCAPE])
			{
				close_SDL();
				exit(0);
			}
		}
	}
}
