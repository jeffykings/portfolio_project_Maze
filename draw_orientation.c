#include "main.h"

/**
 * draw_orientation - Draws walls with different colors based on their orientation.
 *
 * @renderer: Pointer to the SDL_Renderer used for drawing.
 * @map: 2D array representing the map layout.
 * @map_width: Width of the map.
 * @map_height: Height of the map.
 * @player_x: X-coordinate of the player position.
 * @player_y: Y-coordinate of the player position.
 * @player_angle: Angle of the player's view direction.
 */

void draw_orientation(SDL_Renderer *renderer, int **map, int map_width, int map_height,
		                      float player_x, float player_y, float player_angle)
{
	int x, y;
	float wall_height;
	SDL_Rect wall_rect;
	SDL_Color wall_color;

	/* Iterate over columns of the screen */
	for (x = 0; x < 800; x++)
	{
		/* Compute ray angle and distance to the wall */
		float ray_angle = player_angle + (x - 400) * 0.005;
		float ray_x = player_x;
		float ray_y = player_y;
		float step_x = cos(ray_angle);
		float step_y = sin(ray_angle);

		/* Cast the ray */
		while (map[(int)ray_y][(int)ray_x] == 0)
		{
		ray_x += step_x;
		ray_y += step_y;
		}
		
		/* Determine wall orientation */
		int wall_orientation;
		
		if (fabsf(fmod(ray_angle, M_PI)) < 0.1 || fabsf(fmod(ray_angle, -M_PI)) < 0.1)
		{
			wall_orientation = 0; /* North-South */
		}
		else
		{
		wall_orientation = 1; /* East-West */
		}

		/* Set wall color based on orientation */
		if (wall_orientation == 0)
		{
		wall_color = (SDL_Color){255, 0, 0, 255}; /* Red for North-South */
		}
		else
		{
		wall_color = (SDL_Color){0, 0, 255, 255}; /* Blue for East-West */
		}
		
		/* Compute wall height */
		float distance_to_wall = sqrt(pow(ray_x - player_x, 2) + pow(ray_y - player_y, 2));
		wall_height = 600 / distance_to_wall;
		
		/* Draw the wall */
		wall_rect.x = x;
		wall_rect.y = (600 - wall_height) / 2;
		wall_rect.w = 1;
		wall_rect.h = wall_height;
		SDL_SetRenderDrawColor(renderer, wall_color.r, wall_color.g, wall_color.b, wall_color.a);
		SDL_RenderFillRect(renderer, &wall_rect);
	}
       
	/* Present the renderer */
	SDL_RenderPresent(renderer);
}
