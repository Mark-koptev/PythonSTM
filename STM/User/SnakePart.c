#include "SnakePart.h"

Snake* snake_create(int x, int y, int previous_image){
	Snake* s = NEW;
	s->x = x;
	s->y = y;
	s->IMG_PREV = previous_image;
	
	Snake* s1 = NEW;
	s1->x = s->x;
	s1->y = s->y+ 1;
	s1->IMG_PREV = previous_image;
	s->next = s1;
	
	Snake* s2 = NEW;
	s2->x = s1->x;
	s2->y = s1->y + 1;
	s2->next = NULL;
	s2->IMG_PREV = previous_image;
	s1->next = s2;
	
	return s;
}

void snake_draw(Snake* snake, int img) {
	Snake* s = snake;
	while(s) {
		draw_image(img, s->x, s->y);
		s = s->next;
	}
}

void snake_free_mem(Snake* snake){
	Snake* s = snake;
	while (s){
		Snake* next = s->next;
		free(s);
		s = next;
	}
}

int snake_has_collision(Snake* snake){
	
	int head_x = snake->x;
	int head_y = snake->y;
	
	Snake* s = snake->next;
	while (s)
		if (s->x == head_x && s->y == head_y)
			return 1;
		else s = s->next;
	
	return 0;
}
int snake_count(Snake* snake)
{
	Snake* s = snake;
	int count = 0;
	while(s)
	{
		count++;
		s = s->next;
	}
	return count;
}
int* snake_positions(Snake* snake)
{
	Snake* s = snake;
	int count = snake_count(snake);
	
	int* snake_poses = malloc(sizeof(int) * count * 2);
	for(int i = 0; i < count * 2; i+=2)
	{
		snake_poses[i] = s->x;
		snake_poses[i+1] = s->y;
		s = s->next;
	}

	return snake_poses;
}

Snake* snake_grow(Snake* snake, int deltaX, int deltaY){
	int newx = snake->x + deltaX;
	int newy = snake->y + deltaY;
	
	Snake* s = NEW;
	s->x = newx;
	s->y = newy;
	
	s->next = snake;
	
	draw_image(IMG_SNAKE, s->x, s->y);
	
	return s;
}

int snake_update(Snake* snake, int deltaX, int deltaY){
	int prevX = snake->x;
	int prevY = snake->y;
	int nx = snake->x + deltaX;
	int ny = snake->y + deltaY;
	
	if (nx == snake->next->x && ny == snake->next->y)
		return 0;
	
	snake->x = nx;
	snake->y = ny;
	
	if(snake->x == CELL_WIDTH)
		snake ->x = 0;
	
	if(snake->x == -1)
		snake ->x = CELL_WIDTH - 1;
	
	if(snake->y == CELL_HEIGHT+1)
		snake ->y = 3;
	
	if(snake->y == 2)
		snake ->y = CELL_HEIGHT;
	
	draw_image(IMG_SNAKE, snake->x, snake->y);
	snake_clear_previous(snake->next, prevX, prevY);
	return 1;
}

void snake_clear_previous(Snake* snake, int x, int y){
	int prevX = snake->x;
	int prevY = snake->y;
	snake->x = x;
	snake->y = y;
	
	if (snake->next){
		snake_clear_previous(snake->next, prevX, prevY);
	}else{
		draw_image(snake->IMG_PREV, prevX, prevY);
	}
}
