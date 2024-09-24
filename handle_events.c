#include "main.h"

/**
 * handle_events - Processes SDL events for user input and window actions
 */

void handle_events(void)
{
	SDL_Event e;
	const Uint8 *keystate = SDL_GetKeyboardState(NULL);

	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			exit(0);
		}
		else if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP)
		{
			update_player_position(keystate);
			rotate_camera(keystate);
			move_camera(keystate);
		}
	}
}
