#include "main.h"

SDL_Window *gWindow = NULL;
SDL_Renderer *gRenderer = NULL;
SDL_Texture *wallTexture = NULL;
SDL_Texture *floorTexture = NULL;
SDL_Texture *ceilingTexture = NULL;

double posX = 22.0, posY = 12.0; /** Player position **/
double dirX = -1.0, dirY = 0.0;  /** Player direction vector **/
double planeX = 0.0, planeY = 0.66; /** Camera plane **/

/**
 * main - Entry point of the program
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, -1 on failure
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <map_file>\n", argv[0]);
		return (-1);
	}

	if (initialize_SDL() != 0)
		return (-1);

	if (parse_map(argv[1]) != 0)
		return (-1);

	  if (load_textures() != 0)
		  return (-1);

	while (1)
	{
		handle_events();
		const Uint8 *keystate = SDL_GetKeyboardState(NULL);
		move_camera(keystate); /** Move the camera based on input **/
		rotate_camera(keystate); /** Rotate the camera based on input **/
		update_player_position(keystate);

		clear_screen();

		render_walls();
		draw_map();
		SDL_RenderPresent(gRenderer);
	}
	close_SDL();

	return (0);
}
