#include "main.h"

/**
 * parse_map_from_file - Parses a map from a file into a 2D array.
 *
 * @filename: Path to the map file.
 * @map: Pointer to the 2D array where the map will be stored.
 * @map_width: Pointer to store the width of the map.
 * @map_height: Pointer to store the height of the map.
 *
 * Return: 0 on success, -1 on failure.
 */

int parse_map_from_file(const char *filename, int ***map, int *map_width, int *map_height)
{
	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return (-1);
	}
	
	char buffer[256];
	int width = 0, height = 0;
	int **temp_map = NULL;

	/* Read the map dimensions from the file */
	if (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		sscanf(buffer, "%d %d", &width, &height);
	}

	*map_width = width;
	*map_height = height;

	/* Allocate memory for the map */
	temp_map = malloc(height * sizeof(int *));

	for (int i = 0; i < height; i++)
	{
		temp_map[i] = malloc(width * sizeof(int));
	}
	
	/* Read the map data from the file */
	for (int y = 0; y < height; y++)
	{
		if (fgets(buffer, sizeof(buffer), file) != NULL)
											        {
													            for (int x = 0; x < width; x++)
															                {
																		                temp_map[y][x] = buffer[x] - '0';
																				            }
														            }
										    }

						        fclose(file);

							    *map = temp_map;
							        return (0);
}

