#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <SDL2/SDL.h>

SDL_Window *init_SDL(void);
SDL_Renderer *create_renderer(SDL_Window *window);
void draw_walls(SDL_Renderer *renderer, int **map, int map_width, int map_height, 
		                float player_x, float player_y, float player_angle);

#endif /* MAIN_H */

