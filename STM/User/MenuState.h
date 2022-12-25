#ifndef MENUSTATE_H
#define MENUSTATE_H
/**
@file 
@brief описание взаимодействия с меню
*/
#include "Draw.h"
#include "States.h"
#include "SnakePart.h"
#include "Button.h"
#include "SoundManager.h"

/**
@brief обновление логики меню
@param StateData - информация о уровне, лучшем результате и текущем результате
*/
void menu_state(StateData*);
/**
@brief инициализация состояния меню
@param StateData - информация о уровне, лучшем результате и текущем результате
*/
void menu_state_start(StateData*);
/**
@brief инициализация состояния меню
@param change_method - на функцию для именения состояния (указатель функции)
*/
void menu_state_changer(void (*change_method)(int));
/**
@brief обработка кнопки
@param code - код нажатой кнопки
@param StateData - информация о уровне, лучшем результате и текущем результате
*/
void menu_state_input(uint32_t code, StateData*);

/**
@brief создание кнопок
@param StateData - информация о уровне, лучшем результате и текущем результате
*/
void menu_init_buttons(StateData*);
/**
@brief отрисовка кнопок
@param StateData - информация о уровне, лучшем результате и текущем результате
*/
void menu_draw_buttons(StateData*);

/**
@brief изменение состояния на SNAKE_MOVEMENT_STATE
*/
void menu_start_play();
/**
@brief обработка выбранной кнопки
@param step - шаг
@param StateData - информация о уровне, лучшем результате и текущем результате
*/
void menu_level_step(int step, StateData* state_data);
/**
@brief изменение кнопки 
@param step - шаг
@param StateData - информация о уровне, лучшем результате и текущем результате
*/
void menu_select_button_by_step(int step, StateData*);
/**
@brief пустной метод
*/
void menu_button_level();
/**
@brief изменение текущего уровня
@param StateData - информация о уровне, лучшем результате и текущем результате
*/
void menu_button_left_level(StateData* state_data);
/**
@brief изменение текущего уровня
@param StateData - информация о уровне, лучшем результате и текущем результате
*/
void menu_button_right_level(StateData* state_data);

#endif
