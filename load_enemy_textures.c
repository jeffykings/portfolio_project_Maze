nclude "main.h"

/**
 * load_enemy_textures - Loads enemy textures from files.
 *
 * @renderer: Pointer to the SDL_Renderer.
 * @file_paths: Array of paths to enemy texture files.
 * @num_enemies: Number of enemy textures to load.
 *
 * Return: Array of loaded SDL_Textures, or NULL on failure.
 */

SDL_Texture **load_enemy_textures(SDL_Renderer *renderer, const char **file_paths, int num_enemies)
{
	SDL_Texture **textures = malloc(num_enemies * sizeof(SDL_Texture *));
	if (textures == NULL)
	{
		fprintf(stderr, "Failed to allocate memory for enemy textures\n");
		return NULL;
	}

	for (int i = 0; i < num_enemies; i++)
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
