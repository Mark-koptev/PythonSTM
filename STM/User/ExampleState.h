#ifndef EXAMPLESTATE_H
#define EXAMPLESTATE_H

#include "States.h"

void example_state_update(StateData*);
void example_state_start(StateData*);
void example_state_changer(void (*change_method)(int));
void example_state_input(uint32_t code, StateData*);

#endif
