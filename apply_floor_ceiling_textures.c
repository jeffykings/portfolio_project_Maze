#include "main.h"

/**
 * apply_floor_ceiling_textures - Applies floor and ceiling textures to the scene
 */
void apply_floor_ceiling_textures(void)
{
    SDL_Rect floorDest, ceilingDest;
    SDL_Rect floorSrc = {0, 0, 64, 64}; // Assuming 64x64 texture
    SDL_Rect ceilingSrc = {0, 0, 64, 64};

    floorDest.x = 0;
    floorDest.y = 500; // Example height
    floorDest.w = 640;
    floorDest.h = 240;

    ceilingDest.x = 0;
    ceilingDest.y = 0;
    ceilingDest.w = 640;
    ceilingDest.h = 240;

    SDL_RenderCopy(gRenderer, floorTexture, &floorSrc, &floorDest);
    SDL_RenderCopy(gRenderer, ceilingTexture, &ceilingSrc, &ceilingDest);
}
