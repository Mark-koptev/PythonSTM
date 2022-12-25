#ifndef STATESYSTEM_H
#define STATESYSTEM_H

#include "MenuState.h"
#include "SnakeMovementState.h"
#include "GameOverState.h"
#include "ExampleState.h"
#include "States.h"

/**
@brief инициализация состояния меню
*/
void state_system_init(void);
/**
@brief обновление текущего состояния игры
*/
void state_system_update(void);
/**
@brief передает состояние нажатой кнопки
@param - код кнопки
*/
void state_system_input(uint32_t code);
/**
@brief изменение состояния игры
@param state_id - текущее состояние игры
*/
void change_state(int state_id);

#endif
