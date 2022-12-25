#ifndef SNAKEMOVEMENTSTATE_H
#define SNAKEMOVEMENTSTATE_H
/**
@file 
@brief описание движения змейки
*/
#include "SnakePart.h"
#include "AppleGenerator.h"
#include "WallGenerator.h"
#include "States.h"
#include "SoundManager.h"

/**
@brief установка траектории после нажатия клавиши
@param х - траектория по х
@param у - траектория по у
*/
void set_direction(int x, int y);
/**
@brief изменение очков после съедания яблока
@param score - текущие очки
*/
void snake_score_changed(int score);
/**
@brief логика движения змейки
@param StateData - информация о уровне, лучшем результате и текущем результате
*/
void snake_movement_state(StateData*);
/**
@brief генерация уровня
@param StateData - информация о уровне, лучшем результате и текущем результате
*/
void snake_movement_state_start(StateData*);
/**
@brief изменение текущего состояния
@param change_method - на функцию для именения состояния (указатель функции)
*/
void snake_movement_state_changer(void (*change_method)(int));
/**
@brief обработка кнопки
@param code - код нажатой кнопки
@param StateData - информация о уровне, лучшем результате и текущем результате
*/
void snake_movement_state_input(uint32_t code, StateData*);

#endif
