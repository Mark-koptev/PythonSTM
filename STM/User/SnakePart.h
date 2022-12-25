#ifndef SNAKEPART_H
#define SNAKEPART_H

#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include "stm32f3xx_it.h"
#include "Settings.h"
#include "Draw.h"

#define NEW ((Snake*) malloc((sizeof(Snake))))


typedef struct Snake {
	int x;
	int y;
	int IMG_PREV;
	struct Snake* next;
} Snake;

/**
@brief односвязный список для хранения змейки
*/

/**
@brief инициализация змейки из 3 состовляющих тела
@param x,y - координаты головы змейки
@param previous_image - изображение части тела змейки
*/
Snake* snake_create(int x, int y, int previous_image);
/**
@brief отрисовка тела змейки на экран
@param snake - односвязный список для хранения тела змейки
@param img - изображение тела змеи ТУТ КОД ИЗОБРАЖЕНИЯ из SWITCH
*/
void snake_draw(Snake* snake, int img);
/**
@brief освобождение памяти 
@param snake - односвязный список для хранения тела змейки
*/
void snake_free_mem(Snake* snake);
/**
@brief обновление координат змейки
@param snake - односвязный список для хранения тела змейки
@param deltaX, deltaY - смещение на экране
*/
int snake_update(Snake*, int, int);
/**
@brief очистка хвоста
@param snake - односвязный список для хранения тела змейки
@param deltaX, deltaY - смещение на экране
*/
void snake_clear_previous(Snake*, int, int);

int snake_has_collision(Snake*);

int snake_has_coords(Snake* snake, int x, int y);

int* snake_positions(Snake* snake);

int snake_count(Snake* snake);

Snake* snake_grow(Snake* snake, int, int);

#endif
