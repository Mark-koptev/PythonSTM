#include "SnakeMovementState.h"

void (*snake_state_change) (int);


int dirX; /**
@brief траектория по x
*/
int dirY;/**
@brief траектория по у
*/

/**
@brief количество очков в текущей сессии
*/
int score;

/**
@brief инициализация змейки
*/
Snake* snake = NULL;

void set_direction(int x, int y)
{
	if(x == -dirX && y == -dirY)
		return;
	
	dirX = x;
	dirY = y;
}
void snake_score_changed(int score)
{	
	for(int i = 0; i < 24; i++)
		for(int j = 0; j < 3; j++)
			draw_image(IMG_BOX, i, j);
	
	draw_message("SCORE: ", 80, 10, 10, LCD_COLOR_YELLOW);
	
	char string_score[5];
	sprintf(string_score, "%d", score);

	draw_message(string_score, 145, 10, 10, LCD_COLOR_YELLOW);
}
void snake_movement_state(StateData* state_data)
{
	if(!snake)
		return;
	
	if(wall_has_collision(snake->x + dirX, snake->y + dirY))
	{
		snake_state_change(GAME_OVER_STATE);
		return;
	}
		
	if (!snake_update(snake, dirX, dirY)){
		snake_draw(snake, IMG_SNAKE_DEAD);
		
		snake_state_change(GAME_OVER_STATE);
	}
	if (snake_has_collision(snake)){
		snake_draw(snake, IMG_SNAKE_DEAD);
		
		snake_state_change(GAME_OVER_STATE);
	}
	if (apple_is_eaten(snake->x, snake->y)){
		apple_create(wall_map, snake_positions(snake), snake_count(snake));
		snake = snake_grow(snake, dirX, dirY);
		state_data->score++;
		
		speaker_squeak_hz(0.001f, 5000);
		
		snake_score_changed(state_data->score);
	}
}
void snake_movement_state_start(StateData* state_data)
{
	fill_screen(color(0));
	
	wall_initialize();
	
	if(snake)
		snake_free_mem(snake);
	
	state_data->score = 0;
	dirX = 0;
	dirY = -1;
	
	snake = snake_create(12, 12, IMG_NONE);
	
	wall_select_map(state_data->level);
	wall_generate_map();
	
	apple_create(wall_map, snake_positions(snake), snake_count(snake));
	
	snake_score_changed(0);
}
void snake_movement_state_changer(void (*change_method)(int))
{
	snake_state_change = change_method;
}
void snake_movement_state_input(uint32_t code, StateData* state_data)
{
	switch (code) {
		case LEFT: set_direction(-1, 0); break;
		case RIGHT: set_direction(1, 0); break;
		case UP: set_direction(0, -1); break;
		case DOWN: set_direction(0, 1); break;
		case RESTART: snake_state_change(MENU_STATE); break;
	}
}
