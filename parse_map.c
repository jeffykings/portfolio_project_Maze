#include "main.h"

/**
 * parse_map - Parses the map from a file and populates the worldMap array
 * @filename: The name of the file containing the map
 *
 * Return: 0 on success, -1 on failure
 */

int parse_map(const char *filename)
{
	FILE *file;
	int x, y;
	char line[25];

	file = fopen(filename, "r");
	if (!file)
	{
		fprintf(stderr, "Error: Could not open map file %s\n", filename);
		return (-1);
	}

	for (y = 0; y < 24; y++)
	{
		if (fgets(line, sizeof(line), file))
		{
			for (x = 0; x < 24; x++)
			{
				if (line[x] >= '0' && line[x] <= '9')
					worldMap[y][x] = line[x] - '0';
				else
					worldMap[y][x] = 0;
			}
		}
	}
	fclose(file);
	return (0);
}
