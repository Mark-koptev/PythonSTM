#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include "Draw.h"
#include "States.h"

void g_over_state(StateData*);
void g_over_state_start(StateData*);
void g_over_state_changer(void (*change_method)(int));
void g_over_state_input(uint32_t code, StateData*);

#endif
