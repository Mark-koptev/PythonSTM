#include "GameOverState.h"

void (*g_over_state_change) (int);

void g_over_state(StateData* state_data)
{

}
void g_over_state_start(StateData* state_data)
{
	fill_screen(color(4));
	
	draw_message("GAME OVER!", 70, 100, 10, LCD_COLOR_YELLOW);
	draw_message("SCORE: ", 80, 230, 10, LCD_COLOR_YELLOW);
	
	if(state_data->score > state_data->best_score)
		state_data->best_score = state_data->score;
	
	char string_score[5];
	sprintf(string_score, "%d", state_data->score);
	draw_message(string_score, 140, 230, 10, LCD_COLOR_GREEN);
}
void g_over_state_changer(void (*change_method)(int))
{
	g_over_state_change = change_method;
}
void g_over_state_input(uint32_t code, StateData* state_data)
{
	g_over_state_change(MENU_STATE);
}
