#include "AppleGenerator.h"

int appleX;
int appleY;

int random_number(int offset, int limit) { return ((rand()) % limit) + offset; }

void apple_create(char** wall_map, int* xys, int count)
{
	appleX = random_number(2, CELL_WIDTH - 4);
	appleY = random_number(5, CELL_HEIGHT - 4);
	
	while (wall_map[appleY][appleX] || apple_in_snake(appleX, appleY, xys, count))
	{
		appleX = random_number(2, CELL_WIDTH - 4);
		appleY = random_number(2, CELL_HEIGHT - 4);
	}
	draw_image(IMG_APPLE, appleX, appleY);
	
	free(xys);
}
int apple_is_eaten(int x, int y)
{
	return x == appleX & y == appleY;
}
int apple_in_snake(int x, int y, int* xys, int count)
{
	for(int i = 0; i < count * 2; i+=2)
	{
		if(x == xys[i] && y == xys[i+1])
			return 1;
	}
	return 0;
}