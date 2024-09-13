#include "main.h"

/**
 * create_renderer - Creates the renderer for the SDL window.
 *
 * @window: The SDL_Window to associate with the renderer.
 *
 * Return: Pointer to the SDL_Renderer if successful, NULL otherwise.
 *  */

SDL_Renderer *create_renderer(SDL_Window *window)
{
	SDL_Renderer *renderer = NULL;

	/* Create a renderer for the window */
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		SDL_Log("Failed to create renderer: %s", SDL_GetError());
		return (NULL);
	}
	
	return (renderer);
}
