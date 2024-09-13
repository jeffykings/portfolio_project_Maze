#include "main.h"

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */

int main(void)
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Event event;
	int running = 1;
	float player_x = 5.0, player_y = 5.0;
	float player_angle = 0.0;
	float rotation_speed = 0.05;
	int move_forward = 0, move_backward = 0, move_left = 0, move_right = 0;
	int **map = NULL;
	int map_width, map_height;
	int show_map = 1; /* Flag to toggle map rendering */

	/* Textures array */
	SDL_Texture *wall_textures[1]; /* Only one texture for walls in this example */
	const char *weapon_paths[] = {"weapon1.bmp", "weapon2.bmp"};
	SDL_Texture **weapon_textures;
	int num_weapons = 2;
	int current_weapon = 0;
	
	/* Enemy textures */
	const char *enemy_paths[] = {"enemy1.bmp", "enemy2.bmp"};
	SDL_Texture **enemy_textures;
	int num_enemies = 2;
	SDL_Rect enemy_positions[2] = {
		{50, 50, 32, 32},
		{100, 100, 32, 32}
	};

	/* Rain variables */
	int is_raining = 0;
	int num_drops = 100;
	SDL_Rect rain_drops[100];
	for (int i = 0; i < num_drops; i++)
	{
		rain_drops[i].x = rand() % 640;
		rain_drops[i].y = rand() % 480;
		rain_drops[i].w = 2;
		rain_drops[i].h = 10;
	}

	/* Initialize SDL and create a window */
	window = init_SDL();
	if (window == NULL)
	{
		return (1);
	}

	/* Create the renderer */
	renderer = create_renderer(window);
	if (renderer == NULL)
	{
		SDL_DestroyWindow(window);
		SDL_Quit();
		return (1);
	}

       	/* Load textures */
	wall_textures[0] = load_texture(renderer, "wall_texture.bmp");
	if (wall_textures[0] == NULL)
	{
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return (1);
	}

	/* Load weapon textures */
	weapon_textures = load_weapon_textures(renderer, weapon_paths, num_weapons);
	if (weapon_textures == NULL)
	{
		SDL_DestroyTexture(wall_textures[0]);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return (1);
	}

	/* Load enemy textures */
	enemy_textures = load_enemy_textures(renderer, enemy_paths, num_enemies);
	if (enemy_textures == NULL)
	{
		for (int i = 0; i < num_weapons; i++)
		{
			SDL_DestroyTexture(weapon_textures[i]);
		}
		free(weapon_textures);
		SDL_DestroyTexture(wall_textures[0]);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return (1);
	}

	/* Parse map from file */
	if (parse_map_from_file("map.txt", &map, &map_width, &map_height) != 0)
	{
	       	for (int i = 0; i < num_weapons; i++)
	       	{
			SDL_DestroyTexture(weapon_textures[i]);
		}
		free(weapon_textures);
		
		for (int i = 0; i < num_enemies; i++)
		{
			SDL_DestroyTexture(enemy_textures[i]);
		}
		free(enemy_textures);
		SDL_DestroyTexture(wall_textures[0]);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return (1);
	}

	/* Main loop */
	while (running)
	{
	       	while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = 0;
			}
			else if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
					case SDLK_LEFT:
						rotate_camera(&player_angle, rotation_speed, 1);
						break;
					case SDLK_RIGHT:
						rotate_camera(&player_angle, rotation_speed, 0);
						break;
					case SDLK_w:
						move_forward = 1;
						break;
					case SDLK_s:
						move_backward = 1;
						break;
					case SDLK_a:
						move_left = 1;
						break;
					case SDLK_d:
						move_right = 1;
						break;
					case SDLK_m: /* Toggle map visibility */
						show_map = !show_map;
						break;
					case SDLK_1: /* Switch to weapon 1 */
						current_weapon = 0;
						break;
					case SDLK_2: /* Switch to weapon 2 */
						current_weapon = 1;
						break;
					case SDLK_r: /* Toggle rain effect */
						toggle_rain(&is_raining);
						break;
				}
			}
			else if (event.type == SDL_KEYUP)
			{
				switch (event.key.keysym.sym)
				{
					case SDLK_w:
						move_forward = 0;
						break;
					case SDLK_s:
						move_backward = 0;
						break;
					case SDLK_a:
						move_left = 0;
						break;
					case SDLK_d:
						move_right = 0;
						break;
				}
			}
		}
		
		/* Move the player */
		float move_x = 0.0, move_y = 0.0;
		float move_speed = 0.1;
		if (move_forward)
		{
			move_x += cos(player_angle) * move_speed;
			move_y += sin(player_angle) * move_speed;
		}
		if (move_backward)
		{
			move_x -= cos(player_angle) * move_speed;
			move_y -= sin(player_angle) * move_speed;
		}
		if (move_left)
		{
			move_x += cos(player_angle + M_PI_2) * move_speed;
			move_y += sin(player_angle + M_PI_2) * move_speed;
		}
		if (move_right)
		{
			move_x -= cos(player_angle + M_PI_2) * move_speed;
			move_y -= sin(player_angle + M_PI_2) * move_speed;
		}
		
		/* Handle collisions */
		handle_collisions(&player_x, &player_y, map, map_width, map_height, move_x, move_y);

		/* Clear screen */
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		/* Draw walls with texture */
		draw_textured_walls(renderer, wall_textures, map, map_width, map_height, player_x, player_y, player_angle);

		/* Draw enemies */
		draw_enemies(renderer, enemy_textures, enemy_positions, num_enemies);

		/* Draw weapons */
		draw_weapons(renderer, weapon_textures, num_weapons, current_weapon, 10, 10);

		/* Draw rain */
		draw_rain(renderer, is_raining, rain_drops, num_drops);

		/* Draw map if enabled */
		if (show_map)
		{
			draw_map(renderer, map, map_width, map_height, show_map);
		}

		SDL_RenderPresent(renderer);
		
		SDL_Delay(16);  /* Roughly 60 FPS */
       	}

	/* Cleanup */
	for (int i = 0; i < num_weapons; i++)
	{
		SDL_DestroyTexture(weapon_textures[i]);
	}
	
	free(weapon_textures);
	for (int i = 0; i < num_enemies; i++)
	{
		SDL_DestroyTexture(enemy_textures[i]);
	}
	free(enemy_textures);
	SDL_DestroyTexture(wall_textures[0]);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return (0);
}
