#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define MOVE_SPEED 0.1

extern SDL_Window *gWindow;
extern SDL_Renderer *gRenderer;
extern int worldMap[24][24]; /** World map **/

extern double posX, posY; /** Player position **/
extern double dirX, dirY; /** Player direction **/
extern double planeX, planeY; /** Camera plane **/

/* Function prototypes */
int initialize_SDL(void);
void close_SDL(void);
void perform_raycasting(void);
void handle_events(void);
void update_player_position(const Uint8 *keystate);
void draw_grid(void);
int check_collision(double newX, double newY);
void render_walls(void);
void draw_map(void);
void clear_screen(void);
void rotate_camera(const Uint8 *keystate);
void move_camera(const Uint8 *keystate);
int parse_map(const char *filename);
SDL_Texture *load_texture(const char *file);
int load_textures(void);
void render_floor_ceiling(void);
void draw_scene(void);
int handle_collisions(double newX, double newY);
void apply_wall_textures(int x, int wallHeight, int textureX, int wallType);
void apply_floor_ceiling_textures(void);

#endif /* MAIN_H */
