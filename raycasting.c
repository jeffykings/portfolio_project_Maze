#include "main.h"

#define MAP_WIDTH 24
#define MAP_HEIGHT 24
#define TEXTURE_WIDTH 64
#define TEXTURE_HEIGHT 64

double posX = 22.0, posY = 12.0; /** Player's starting position **/
double dirX = -1.0, dirY = 0.0; /** Initial direction vector **/
double planeX = 0.0, planeY = 0.66; /** he 2D raycaster version of camera plane **/

int worldMap[MAP_WIDTH][MAP_HEIGHT] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

/**
 * perform_raycasting - Performs raycasting to render the walls
 */

void perform_raycasting(void)
{
	for (int x = 0; x < SCREEN_WIDTH; x++)
	{
		float cameraX = 2 * x / (float)SCREEN_WIDTH - 1; /** Camera x-coordinate in camera space **/
		float rayDirX = dirX + planeX * cameraX;
		float rayDirY = dirY + planeY * cameraX;

		int mapX = (int)posX;
		int mapY = (int)posY;

		float sideDistX;
		float sideDistY;

		float deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
		float deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
		float perpWallDist;

		int stepX;
		int stepY;

		int hit = 0;
		int side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (worldMap[mapX][mapY] > 0) hit = 1;
		}

		if (side == 0) perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
		
		else perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;


		int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);


		int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;

		if (drawStart < 0) drawStart = 0;
		
		int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
		
		if (drawEnd >= SCREEN_HEIGHT) drawEnd = SCREEN_HEIGHT - 1;


		if (side == 0)
			SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255);
		else
			SDL_SetRenderDrawColor(gRenderer, 0, 0, 225, 255);

		 printf("Ray %d: posX=%.2f, posY=%.2f, rayDirX=%.2f, rayDirY=%.2f, mapX=%d, mapY=%d, drawStart=%d, drawEnd=%d\n", x, posX, posY, rayDirX, rayDirY, mapX, mapY, drawStart, drawEnd);

		SDL_RenderDrawLine(gRenderer, x, drawStart, x, drawEnd);
	}
	draw_grid();
}

void draw_grid()
{
	SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
	
	/** Draw vertical lines **/
	for (int x = 0; x < SCREEN_WIDTH; x += 64)
	{
		SDL_RenderDrawLine(gRenderer, x, 0, x, SCREEN_HEIGHT);
	}
	
	/** Draw horizontal lines **/
	for (int y = 0; y < SCREEN_HEIGHT; y += 64)
	{
		SDL_RenderDrawLine(gRenderer, 0, y, SCREEN_WIDTH, y);
	}
	
	SDL_RenderPresent(gRenderer);
}

/**
 * render_walls - Draws the walls based on raycasting results
 */

void render_walls(void)
{
	for (int x = 0; x < SCREEN_WIDTH; x++)
	{
	       	/** Perform raycasting calculations for this x-coordinate **/
	       	/** Calculate ray position and direction **/
		double cameraX = 2 * x / (double)SCREEN_WIDTH - 1;
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;

		/** Which box of the map we're in **/
		int mapX = (int)posX;
		int mapY = (int)posY;

		/** Length of ray from current position to next x or y-side **/
		double sideDistX;
		double sideDistY;

		/** Length of ray from one x or y-side to next x or y-side **/
		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;

		/** What direction to step in x or y-direction (either +1 or -1) **/
		int stepX;
		int stepY;

		int hit = 0; /** Was there a wall hit? **/
		int side;   /** Was a NS or a EW wall hit? **/

		/** Calculate step and initial sideDist **/
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}

		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		 }

		/** Perform DDA **/
		while (hit == 0)
		{
			/** Jump to next map square, either in x-direction, or in y-direction **/
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
		else
		{
			sideDistY += deltaDistY;
			mapY += stepY;
			side = 1;
		}
		
		/** Check if ray has hit a wall **/
		if (worldMap[mapX][mapY] > 0) hit = 1;
		}

		/** Calculate distance projected on camera direction (Euclidean distance will give fisheye effect!) **/
		if (side == 0) perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;

		else perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

		/** Calculate height of line to draw on screen **/
		int lineHeight = (int)(SCREEN_HEIGHT / perpWallDist);

		/** Calculate lowest and highest pixel to fill in current stripe **/
		int drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
		if (drawStart < 0) drawStart = 0;
		
		int drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
		if (drawEnd >= SCREEN_HEIGHT) drawEnd = SCREEN_HEIGHT - 1;

		/** Choose wall color **/
		SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, 255); /** Red **/
		if (side == 1) { SDL_SetRenderDrawColor(gRenderer, 128, 0, 0, 255); } /** Dark red for y-side **/

		/** Draw the vertical line representing the wall slice **/
		SDL_RenderDrawLine(gRenderer, x, drawStart, x, drawEnd);
	}
	SDL_RenderPresent(gRenderer);
}
