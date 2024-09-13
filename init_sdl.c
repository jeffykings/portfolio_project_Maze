#include "main.h"

/**
 * init_SDL - Initializes SDL and creates a window.
 *
 * Return: Pointer to the SDL_Window if successful, NULL otherwise.
 */

SDL_Window *init_SDL(void)
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;

       	/* Initialize SDL */
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
		return (NULL);
	}

	/* Create a window */
	window = SDL_CreateWindow("3D Maze Game", SDL_WINDOWPOS_CENTERED, 
			SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		SDL_Log("Failed to create window: %s", SDL_GetError());
		SDL_Quit();
		return (NULL);
	}

	/* Create a renderer */
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	if (renderer == NULL)
	{
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return (NULL);
	}

	/* Return window and renderer */
	return (window);
}
