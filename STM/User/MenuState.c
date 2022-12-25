#include "MenuState.h"

void (*menu_state_change) (int);

Snake* menu_snake = NULL;
Button** menu_buttons = NULL;

int dX[] = { 0, 1, 0, -1};
int dY[] = { -1, 0, 1, 0};

int count_levels = 3;
char* levels[] = {"EASY", "MEDIUM", "HARD"};

int menu_last_color_button = LCD_COLOR_GRAY;

int menu_buttons_count = 4;
int menu_selected_button = 0;
int current_dir;
int count_step;

void menu_button_start_play()
{
	menu_state_change(SNAKE_MOVEMENT_STATE);
}
void menu_level_step(int step, StateData* state_data)
{
	state_data->level += step;
	
	if(state_data->level < 0)
		state_data->level = count_levels - 1;
	if(state_data->level >= count_levels)
		state_data->level = 0;
	
	menu_buttons[3]->text_color = LCD_COLOR_BLACK;
	menu_buttons[3]->back_color = LCD_COLOR_BLACK;
	
	menu_draw_buttons(state_data);
	
	menu_buttons[3]->text_color = LCD_COLOR_YELLOW;
	menu_buttons[3]->back_color = LCD_COLOR_GREEN;
	
	menu_buttons[3]->x = 120 - strlen(levels[state_data->level]) * 5 - 10;
	menu_buttons[3]->name = levels[state_data->level];
	
	uint8_t write = state_data->level;
	
	menu_draw_buttons(state_data);
}
void menu_button_left_level(StateData* state_data)
{
	menu_level_step(-1, state_data);
}
void menu_button_right_level(StateData* state_data)
{
	menu_level_step(1, state_data);
}
void menu_button_level()
{

}
void menu_init_buttons(StateData* state_data)
{
	if(menu_buttons != NULL)
		return;
	
	menu_buttons = (Button**) malloc((sizeof(Button) * menu_buttons_count));
	
	menu_buttons[0] = CreateButton("PLAY", 90, 230, LCD_COLOR_PURPLE, LCD_COLOR_YELLOW, menu_button_start_play);
	menu_buttons[1] = CreateButton("<", 30, 270, LCD_COLOR_GRAY, LCD_COLOR_YELLOW, menu_button_left_level);
	menu_buttons[2] = CreateButton(">", 180, 270, LCD_COLOR_GRAY, LCD_COLOR_YELLOW, menu_button_right_level);
	menu_buttons[3] = CreateButton(levels[0], 120 - strlen(levels[state_data->level]) * 5 - 10, 270, LCD_COLOR_GREEN, LCD_COLOR_YELLOW, menu_button_level);
}
void menu_draw_buttons(StateData* state_data)
{
	menu_init_buttons(state_data);
	
	for(int i = 0; i < menu_buttons_count; i++)
		draw_button(
			menu_buttons[i]->name, menu_buttons[i]->x, menu_buttons[i]->y, 10, menu_buttons[i]->text_color, menu_buttons[i]->back_color);
}
void menu_state(StateData* state_data)
{
	 sound_correct_key();
	
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
void menu_state_start(StateData* state_data)
{	
	fill_screen(color(4));

	if(menu_snake)
		snake_free_mem(menu_snake);
	
	menu_snake = snake_create(5, 15, IMG_BOX);
	
	menu_selected_button = 0;
	count_step = 2;
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

	draw_message("BEST SCORE: ", 65, 200, 10, LCD_COLOR_YELLOW);
	
	char string_score[5];
	sprintf(string_score, "%d", state_data->best_score);
	draw_message(string_score, 175, 200, 10, LCD_COLOR_GREEN);
	
	menu_draw_buttons(state_data);
}
void menu_state_changer(void (*change_method)(int))
{
	menu_state_change = change_method;
}
void menu_select_button_by_step(int step, StateData* state_data)
{
	menu_buttons[menu_selected_button]->back_color = menu_last_color_button;
	
	menu_selected_button += step;
	if(menu_selected_button >= menu_buttons_count)
		menu_selected_button = 0;
	if(menu_selected_button < 0)
		menu_selected_button = menu_buttons_count-1;
	
	menu_last_color_button = menu_buttons[menu_selected_button]->back_color;
	menu_buttons[menu_selected_button]->back_color = LCD_COLOR_PURPLE;
	
	menu_draw_buttons(state_data);
}
void menu_state_input(uint32_t code, StateData* state_data)
{
	switch (code) {
		case LEFT: menu_select_button_by_step(1, state_data); break;
		case RIGHT: menu_select_button_by_step(-1, state_data); break;
		case UP: menu_select_button_by_step(-1, state_data); break;
		case DOWN: menu_select_button_by_step(1, state_data); break;
		case 7: menu_buttons[menu_selected_button]->on_click(state_data); break;
	}
}
