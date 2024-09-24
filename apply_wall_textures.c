
#include "main.h"

/**
 * apply_wall_textures - Applies wall textures based on wall type
 * @x: The x-coordinate to render the wall
 * @wallHeight: The height of the wall
 * @textureX: The X coordinate on the texture
 * @wallType: The type of the wall (for different textures)
 */
void apply_wall_textures(int x, int wallHeight, int textureX, int wallType)
{
    SDL_Rect wallRect = {x, 480 - wallHeight, 1, wallHeight}; // Example calculation

    SDL_Rect textureRect = {textureX, 0, 1, 64}; // Assuming 64 height texture

    SDL_RenderCopy(gRenderer, wallTexture, &textureRect, &wallRect);
}
