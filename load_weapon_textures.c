#include "main.h"

/**
 * load_weapon_textures - Loads weapon textures from files.
 * @renderer: Pointer to the SDL_Renderer.
 * @file_paths: Array of paths to weapon texture files.
 * @num_weapons: Number of weapon textures to load.
 *
 * Return: Array of loaded SDL_Textures, or NULL on failure.
 */

SDL_Texture **load_weapon_textures(SDL_Renderer *renderer, const char **file_paths, int num_weapons)
{
	SDL_Texture **textures = malloc(num_weapons * sizeof(SDL_Texture *));
	if (textures == NULL)
	{
		fprintf(stderr, "Failed to allocate memory for weapon textures\n");
		return NULL;
	}
	
	for (int i = 0; i < num_weapons; i++)
	{
		textures[i] = load_texture(renderer, file_paths[i]);
		if (textures[i] == NULL)
		{
			for (int j = 0; j < i; j++)
			{
				SDL_DestroyTexture(textures[j]);
			}

			free(textures);
			return NULL;
		}
	}

	return textures;
}
