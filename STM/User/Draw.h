#ifndef DRAW_H
#define DRAW_H
/**
@file 
@brief отрисовка изображений и текста
*/
#include "Settings.h"
#include "LCD_ILI9325.h"
#include "display.h"
#include <stdio.h>
#include <cstdlib>
#include "stm32f3xx_it.h"



#define BACKGROUND_COLOR LCD_COLOR_BLACK
#define ERROR_COLOR LCD_COLOR_AQUA
#define GRAY LCD_COLOR_GRAY

#define IMG_NONE 0
#define IMG_SNAKE 1
#define IMG_APPLE 2
#define IMG_BOX 4
#define IMG_SNAKE_DEAD 3
#define IMG_TRIANGLE_LEFT_UP 5
#define IMG_TRIANGLE_LEFT_DOWN 6
#define IMG_TRIANGLE_LEFT 7
#define IMG_WALL 8


uint16_t color(char code);

/**
@brief заполнение экрана цветом
@param цвет для заполнения
*/
void fill_screen(uint16_t);

/**
@brief отрисовка на экране изображения (яблоко, части тела змеи)
@param tileCode - код изображения для выбора изображения в функции img_color
@param x,y - координаты изображения
*/
void draw_image(int tileCode, int x, int y);

/**
@brief вывод строчки текста на экран
@param message - содержание строки
@param leftSpace - отступ от левой части экрана
@param y - положение по высоте на экране
@param spacing - отступ между буквами
@param color - цвет текста
*/
void draw_message(char* message,int leftSpace,int y, int spacing,uint16_t color);

/**
@brief вывод кнопки
@param message - содержание строки
@param leftSpace - отступ от левой части экрана
@param y - положение по высоте на экране
@param spacing - отступ между буквами
@param textColor - цвет текста
@param backColor - цвет заднего фона
*/
void draw_button(char* message,int leftSpace,int y, int spacing,uint16_t textColor, uint16_t backColor);

#endif
