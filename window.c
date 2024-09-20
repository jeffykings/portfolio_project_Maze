#include "main.h"

SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;

/**
 * initialize_SDL - Initializes SDL2 and creates a window
 * Return: 0 on success, -1 on failure
 */

int initialize_SDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		return (-1);
	}

	gWindow = SDL_CreateWindow("3D Maze Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (gWindow == NULL)
	{
		fprintf(stderr, "Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return (-1);
	}

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (gRenderer == NULL)
	{
		fprintf(stderr, "Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		return (-1);
	}
	
	return (0);
}

/**
 * close_SDL - Frees resources and closes SDL
 */

void close_SDL()
{
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	SDL_Quit();
}
