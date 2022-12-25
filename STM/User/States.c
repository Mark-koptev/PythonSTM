#include "States.h"

State* CreateState(void (*update) (StateData*), void (*start) (StateData*), void (*changer) (), void (*input) (uint32_t, StateData*))
{
	State* state = (State*) malloc((sizeof(State)));
	state->update = update;
	state->start = start;
	state->changer = changer;
	state->input = input;
	return state;
}