#include "main.h"

/**
 * load_texture - Loads a texture from a file
 * @file: The file path of the texture
 *
 * Return: The loaded SDL_Texture, or NULL on failure
 */

SDL_Texture *load_texture(const char *file)
{
	SDL_Texture *texture = NULL;
	SDL_Surface *loadedSurface = SDL_LoadBMP(file);

	if (loadedSurface == NULL)
	{
		fprintf(stderr, "Unable to load image %s! SDL Error: %s\n", file, SDL_GetError());
	}
	else
	{
		texture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (texture == NULL)
		{
			fprintf(stderr, "Unable to create texture from %s! SDL Error: %s\n", file, SDL_GetError());
		}

		SDL_FreeSurface(loadedSurface);
	}

	return texture;
}

/**
 * load_textures - Loads all necessary textures
 *
 * Return: 0 on success, -1 on failure
 */

int load_textures(void)
{
	wallTexture = load_texture("wall.bmp");
	if (!wallTexture)
		return (-1);

	floorTexture = load_texture("floor.bmp");
	if (!floorTexture)
		return (-1);

	ceilingTexture = load_texture("ceiling.bmp");
	if (!ceilingTexture)
		return (-1);

	return (0);
}
