#ifndef SETTINGS_H
#define SETTINGS_H
/**
@file
@brief константы 
*/
#define RESTART 1
#define LEFT 6
#define RIGHT 8
#define DOWN 11
#define UP 3

#define byte char

#define SNAKE_MOVEMENT_STATE 0
#define MENU_STATE 1

#define SCREEN_HEIGHT 320
#define SCREEN_WIDTH 240
#define CELL_SIZE 10
#define CELL_WIDTH (SCREEN_WIDTH / CELL_SIZE)
#define CELL_HEIGHT ((SCREEN_HEIGHT / CELL_SIZE) - 1)

#define START_X 12
#define START_Y 12

#endif
