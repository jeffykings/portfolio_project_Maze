#include "main.h"

/**
 * main - Entry point of the program
 *
 * Return: 0 on success, -1 on failure
 */

int main(void)
{
	if (initialize_SDL() != 0)
		return (-1);

	while (1)
	{
		handle_events();
		const Uint8 *keystate = SDL_GetKeyboardState(NULL);
		update_player_position(keystate);
		render_walls();
	}
	close_SDL();

	return (0);
}
