#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <SDL2/SDL.h>
#include <math.h>
#include <stdlib.h>

SDL_Window *init_SDL(void);
SDL_Renderer *create_renderer(SDL_Window *window);
void draw_walls(SDL_Renderer *renderer, int **map, int map_width, int map_height, 
	       	float player_x, float player_y, float player_angle);
void draw_orientation(SDL_Renderer *renderer, int **map, int map_width, int map_height, 
		float player_x, float player_y, float player_angle);
void rotate_camera(float *player_angle, float rotation_speed, int rotate_left);
void move_camera(float *player_x, float *player_y, float player_angle,
		int move_forward, int move_backward, int move_left, int move_right,
		int **map, int map_width, int map_height);
void handle_collisions(float *player_x, float *player_y, int **map, int map_width, int map_height,
		                       float move_x, float move_y);
int parse_map_from_file(const char *filename, int ***map, int *map_width, int *map_height);

#endif /* MAIN_H */

