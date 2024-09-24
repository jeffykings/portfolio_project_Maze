#include "main.h"

SDL_Texture *wallTexture = NULL;
SDL_Texture *floorTexture = NULL;
SDL_Texture *ceilingTexture = NULL;

/**
 * load_textures - Loads textures for walls, floor, and ceiling
 */
void load_textures(void)
{
    wallTexture = load_texture("wall.bmp");
    if (!wallTexture)
        SDL_Log("Failed to load wall texture");

    floorTexture = load_texture("floor.bmp");
    if (!floorTexture)
        SDL_Log("Failed to load floor texture");

    ceilingTexture = load_texture("ceiling.bmp");
    if (!ceilingTexture)
        SDL_Log("Failed to load ceiling texture");
}

/**
 * load_texture - Loads an individual texture from a file
 * @path: The path to the image file
 * Return: A pointer to the loaded texture or NULL on error
 */
SDL_Texture* load_texture(const char* path)
{
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = SDL_LoadBMP(path);
    if (loadedSurface == NULL)
    {
        SDL_Log("Unable to load image %s! SDL Error: %s\n", path, SDL_GetError());
        return NULL;
    }

    newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
    SDL_FreeSurface(loadedSurface);

    if (newTexture == NULL)
        SDL_Log("Unable to create texture from %s! SDL Error: %s\n", path, SDL_GetError());

    return newTexture;
}
