#include "StateSystem.h"

State** states;
/**
@brief текущее состояние игры
*/
int CURRENT_STATE;
StateData* state_data;

void state_system_init(void)
{
	int states_count = 4;
	states = (State**) malloc(sizeof(State**) * states_count);
	
	states[0] = CreateState(snake_movement_state, snake_movement_state_start, snake_movement_state_changer, snake_movement_state_input);
	states[1] = CreateState(menu_state, menu_state_start, menu_state_changer, menu_state_input);
	states[2] = CreateState(g_over_state, g_over_state_start, g_over_state_changer, g_over_state_input);
	states[3] = CreateState(example_state_update, example_state_start, example_state_changer, example_state_input);
	
	state_data = NEW_DATA;
	state_data->score = 0;
	state_data->best_score = 0;
	state_data->level = 0;
	
	change_state(MENU_STATE);
}

void state_system_update(void)
{
	states[CURRENT_STATE]->update(state_data);
	
	printf("state_update\n");
}
void change_state(int state_id)
{
	printf("state_changed\n");
	
	CURRENT_STATE = state_id;
	
	states[CURRENT_STATE]->start(state_data);
	states[CURRENT_STATE]->changer(change_state);
}
void state_system_input(uint32_t code)
{
	printf("state_input\n");
	
	states[CURRENT_STATE]->input(code, state_data);
}
