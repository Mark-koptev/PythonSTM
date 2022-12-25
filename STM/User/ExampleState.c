#include "ExampleState.h"

void (*example_state_change) (int);

void example_state_update(StateData* state_data)
{

}
void example_state_start(StateData* state_data)
{

}
void example_state_changer(void (*change_method)(int))
{
	example_state_change = change_method;
}
void example_state_input(uint32_t code, StateData* state_data)
{
	example_state_change(MENU_STATE);
}
