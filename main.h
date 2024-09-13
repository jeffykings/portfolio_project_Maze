#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <SDL2/SDL.h>

SDL_Window *init_SDL(void);
SDL_Renderer *create_renderer(SDL_Window *window);

#endif /* MAIN_H */

