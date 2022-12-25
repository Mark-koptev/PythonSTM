#ifndef WALLGENERATOR_H
#define WALLGENERATOR_H

#include "Draw.h"
	
extern char** wall_map;
void wall_generate_map();
void wall_select_map(int index);
void wall_initialize();

int wall_has_collision(int x, int y);

#endif
