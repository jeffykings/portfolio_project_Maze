#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

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

#endif /* MAIN_H */
