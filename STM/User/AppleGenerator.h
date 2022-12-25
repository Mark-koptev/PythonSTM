#ifndef APPLEGENERATOR_H
#define APPLEGENERATOR_H
/**
@file
@brief генерация и обрабока действий на "яблоком"
*/
#include "Settings.h"
#include "Draw.h"

/**
@brief генерация яблока, чтобы оно не находилось внутри змеи и стен
@param ПОКА НЕ ТРАГАЮ
*/
void apple_create(char** wall_map, int* xys, int count);
/**
@brief проверка, что яблоко сьедено (координаты яблока и головы змеи одинаковые)
@param x,y - координаты головы змеи
@return 0 - координаты головы и яблока не сходятся
@return 1 - змея коснулась яблока
*/
int apple_is_eaten(int x, int y);

int apple_in_snake(int x, int y, int* xys, int count);
#endif
