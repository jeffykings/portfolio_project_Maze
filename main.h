#ifndef MAIN_H
#define MAIN_H

#include <SDL2/SDL.h>
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

extern SDL_Window *gWindow;
extern SDL_Renderer *gRenderer;

/* Function prototypes */
int initialize_SDL(void);
void close_SDL(void);
void perform_raycasting(void);
void handle_events(void);

#endif /* MAIN_H */
