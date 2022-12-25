#include "MenuState.h"

void (*menu_state_change) (int);
Snake* menu_snake = NULL;

int dX[] = { 0, 1, 0, -1};
int dY[] = { -1, 0, 1, 0};
int current_dir;
int count_step;

void menu_state(void)
{
	if(menu_snake)
	{
		snake_update(menu_snake, dX[current_dir], dY[current_dir]);
		count_step++;
		
		if(count_step > 12)
		{
			current_dir++;
			count_step = 0;
			
			if(current_dir > 3)
				current_dir = 0;
		}
	}
}
void menu_state_start(void)
{	
	fill_screen(color(4));
	
	if(menu_snake)
		snake_free_mem(menu_snake);
	
	menu_snake = snake_create(5, 17, IMG_APPLE);
	count_step = 0;
	current_dir = 0;

	//TRIANGLE DRAW
	int startX = 10;
	int startY = 5;
	
	for(int j = 11; j >= 0; j--) 
	{
		for(int i = 11 - j; i < j; i++)
		{
			draw_image(IMG_BOX, startX+11-j, startY + i);
		}
	}
	for(int i = 0; i < 5; i++)
	{
		draw_image(IMG_TRIANGLE_LEFT_DOWN, startX + i, startY + i);
		draw_image(IMG_TRIANGLE_LEFT_UP, startX + i, startY - i + 10);
	}
	draw_image(IMG_TRIANGLE_LEFT, startX + 5, startY + 5);
	
	draw_message("PLAY", 100, 200, 10, LCD_COLOR_YELLOW);
	draw_message("BEST SCORE: ", 50, 230, 10, LCD_COLOR_YELLOW);
}
void menu_state_changer(void (*change_method)(int))
{
	menu_state_change = change_method;
}
void menu_state_input(uint32_t code)
{
	menu_state_change(SNAKE_MOVEMENT_STATE);
}
