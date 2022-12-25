#include "Draw.h"
#include "Images.h"


void fill_screen(uint16_t color){
		int x = 0;
		for (x = 0; x < SCREEN_WIDTH; x++ ){
			int y;
			for(y = 0; y < SCREEN_HEIGHT; y++){
				lcd_set_pixel(x,y,color);
			}
		}
}


uint16_t color(char code){
	switch (code) {
		case 0 : return LCD_COLOR_BACKGROUND;
		case 3 : return LCD_COLOR_RED;
		case 2 : return LCD_COLOR_WHITE;
		case 4 : return LCD_COLOR_BLACK;
		case 1 : return LCD_COLOR_GRAY;
		case 5 : return LCD_COLOR_DARK_GREEN;
		case 6 : return LCD_COLOR_YELLOW;
	}
	
	return ERROR_COLOR;
}

uint16_t img_color(int image, int x, int y){
	switch (image){
		case IMG_NONE :  return color(NONE[y][x]);
		case IMG_SNAKE : return color(SNAKE[y][x]);
		case IMG_APPLE : return color(APPLE[y][x]);
		case IMG_BOX : return color(BOX[y][x]);
		case IMG_SNAKE_DEAD : return color(DEAD_SNAKE[y][x]);
		case IMG_TRIANGLE_LEFT_UP : return color(TRIANGLE_LEFT_UP[y][x]);
		case IMG_TRIANGLE_LEFT_DOWN : return color(TRIANGLE_LEFT_DOWN[y][x]);
		case IMG_TRIANGLE_LEFT : return color(TRIANGLE_LEFT[y][x]);
		case IMG_WALL : return color(WALL[y][x]);
	}
	
	
	return ERROR_COLOR;
}

void draw_image(int tileCode, int x, int y) {
    int display_x = x * CELL_SIZE;
    int display_x_end = (x+1) * CELL_SIZE;
    int display_y = y * CELL_SIZE;
    int display_y_end = (y+1) * CELL_SIZE;
    int image_x = 0;
    for(; display_x < display_x_end; display_x++){
        int image_y = 0;   
        display_y = y * CELL_SIZE;
        for (; display_y < display_y_end; display_y++){
						uint16_t color = img_color(tileCode, image_x, image_y);

            lcd_set_pixel(display_x, display_y, color);
						
            image_y++;
        }
		
        image_x++;
    }        
}
void draw_message(char* message,int leftSpace,int y, int spacing,uint16_t color)
{
	size_t size=strlen(message);
	for (int i=0;i<size;i++)
	{
		prein_ascii(message[i], leftSpace,y,color);
		leftSpace=spacing+leftSpace;
	}
}
void draw_button(char* message,int leftSpace,int y, int spacing,uint16_t textColor, uint16_t backColor)
{
	int sizeButton = strlen(message) * spacing + 20;
	
	for(int x = leftSpace; x < sizeButton + leftSpace; x++)
	{
		for(int _y = y-5; _y < 20 + y; _y++)
		{
			lcd_set_pixel(x, _y, backColor);
		}
	}
	
	size_t size=strlen(message);
	for (int i=0;i<size;i++)
	{
		prein_ascii(message[i], leftSpace + 10,y, textColor);
		leftSpace=spacing+leftSpace;
	}
}
