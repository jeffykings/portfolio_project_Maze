#include "main.h"

/**
 * main - Entry point of the program
 *
 * Return: 0 on success, -1 on failure
 */

int main(void)
{
	if (initialize_SDL() != 0)
		return (-1);

	handle_events();

	close_SDL();

	return (0);
}
