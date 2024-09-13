#include "main.h"

/**
 * load_texture - Loads a texture from a file.
 *
 * @renderer: Pointer to the SDL_Renderer.
 * @file_path: Path to the texture file.
 * Return: Pointer to the loaded SDL_Texture, or NULL on failure.
 */

SDL_Texture *load_texture(SDL_Renderer *renderer, const char *file_path)
{
	SDL_Texture *texture = NULL;

	/* Load the texture from file */
	texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP(file_path));

	if (!texture)
	{
		/* Log the error */
		fprintf(stderr, "Failed to load texture: %s\n", SDL_GetError());
	}
	
	return texture;
}
