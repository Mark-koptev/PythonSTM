#ifndef STATES_H
#define STATES_H
/**
@file 
@brief состояния игры
*/
#include <cstdlib>
#include <stdint.h>

#define SNAKE_MOVEMENT_STATE 0
#define MENU_STATE 1
#define GAME_OVER_STATE 2
#define EXAMPLE_STATE 3

#define NEW_DATA ((StateData*) malloc((sizeof(StateData))))

typedef struct {
	int score;
	int best_score;
	int level;
} StateData;

typedef struct {
	void (*update) (StateData*);
	void (*start) (StateData*);
	void (*changer) ();
	void (*input) (uint32_t, StateData*);
} State;

extern State* CreateState(void (*update) (StateData*), void (*start) (StateData*), void (*changer) (), void (*input) (uint32_t, StateData*));

#endif
