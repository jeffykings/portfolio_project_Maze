#include "main.h"

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */

int main(void)
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

	/* Initialize SDL and create a window */
	window = init_SDL();

	if (window == NULL)
	{
		return (1);
	}

	/* Create the renderer */
	renderer = create_renderer(window);
	
	if (renderer == NULL)
	{
		SDL_DestroyWindow(window);
		SDL_Quit();
		return (1);
	}

	/* Main loop placeholder */
	SDL_Delay(3000);  /* Wait for 3 seconds to see the window */

	/* Cleanup and exit */
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return (0);
}
