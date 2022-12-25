#ifndef SNAKEMOVEMENTSTATE_H
#define SNAKEMOVEMENTSTATE_H

#include "User/SnakePart.h"
#include "User/AppleGenerator.h"
#include "User/States.h"

void set_direction(int x, int y);
void snake_movement_state(void);
void snake_movement_state_start(void);
void snake_movement_state_changer(void (*change_method)(int));
void snake_movement_state_input(uint32_t code);

#endif
