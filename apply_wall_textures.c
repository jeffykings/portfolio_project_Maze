#include "main.h"

/**
 * apply_wall_textures - Renders wall textures based on raycasting results
 * @x: The x-coordinate on the screen
 * @wallHeight: The height of the wall slice to draw
 * @textureX: The x-coordinate on the texture
 * @wallType: The type of wall (for different textures)
 */

void apply_wall_textures(int x, int wallHeight, int textureX, int wallType)
{
	SDL_Rect srcRect, destRect;

	srcRect.x = textureX;
	srcRect.y = 0;
	srcRect.w = 1;
	srcRect.h = 64; /** Assuming texture height is 64 **/

	destRect.x = x;
	destRect.y = (SCREEN_HEIGHT - wallHeight) / 2;
	destRect.w = 1;
	destRect.h = wallHeight;

	SDL_Texture *currentTexture = wallTexture; /** Assuming one wall texture **/

	SDL_RenderCopy(gRenderer, currentTexture, &srcRect, &destRect);
}
