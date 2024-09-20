#include "main.h"

/**
 * main - Entry point of the program
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success, -1 on failure
 */

int main(void)
{
	if (initialize_SDL() != 0)
		return (-1);
	
	perform_raycasting();

	handle_events();

	close_SDL();

	return (0);
}
