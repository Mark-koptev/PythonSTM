#ifndef MENUSTATE_H
#define MENUSTATE_H

#include "User/Draw.h"
#include "User/States.h"
#include "User/SnakePart.h"

void menu_state(void);
void menu_state_start(void);
void menu_state_changer(void (*change_method)(int));
void menu_state_input(uint32_t code);

#endif
