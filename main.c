#include <gb/gb.h>
#include <gb/drawing.h>
#include <types.h>
#include <stdint.h>
#include <gb/drawing.h>
#include "player.c"

#define WHITE   0
#define BLACK   3
#define SOLID   0x00

#define M_NOFILL   0
#define M_FILL   1

#define GRAPHICS_WIDTH  160
#define GRAPHICS_HEIGHT 144

#define SIN(a)  (lut_sine_wave[(uint8_t)(a)])
#define COS(a)  (lut_sine_wave[(uint8_t)((uint8_t)(a) + 64u)])

const int8_t lut_sine_wave[180] = {
0, 2, 3, 5, 7, 9, 10, 12, 14, 16, 17, 19, 21, 22, 24, 26,
28, 29, 31, 33, 34, 36, 37, 39, 41, 42, 44, 45, 47, 48, 50,
52, 53, 54, 56, 57, 59, 60, 62, 63, 64, 66, 67, 68, 69, 71,
72, 73, 74, 75, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87,
87, 88, 89, 90, 91, 91, 92, 93, 93, 94, 95, 95, 96, 96, 97,
97, 97, 98, 98, 98, 99, 99, 99, 99, 100, 100, 100, 100, 100,
100, 100, 100, 100, 100, 100, 99, 99, 99, 99, 98, 98, 98, 97,
97, 97, 96, 96, 95, 95, 94, 93, 93, 92, 91, 91, 90, 89, 88,
87, 87, 86, 85, 84, 83, 82, 81, 80, 79, 78, 77, 75, 74, 73,
72, 71, 69, 68, 67, 66, 64, 63, 62, 60, 59, 57, 56, 54, 53,
52, 50, 48, 47, 45, 44, 42, 41, 39, 37, 36, 34, 33, 31, 29,
28, 26, 24, 22, 21, 19, 17, 16, 14, 12, 10, 9, 7, 5, 3, 2
};

int8_t player_x;
int8_t player_y;

int8_t current_angle;

void drawlines(){
    color(BLACK, WHITE, SOLID);
    line(player_x, player_y, SIN(player_x), COS(player_y));
}

void clearLastLine(){
    color(WHITE, WHITE, SOLID);
    line(player_x, player_y, SIN(player_x), COS(player_y));
}

void gridify(){
    color(BLACK, WHITE, SOLID);
    for (uint8_t i = 0; i < 160; i = i + 10)
    {
        line(i, 0, i, 143);
        delay(1);
    }

    for (uint8_t i = 0; i < 144; i = i + 10)
    {
        line(0, i, 159, i);
        delay(1);
    }
    
}

void clearCalAngles(){
    color(WHITE, WHITE, SOLID);
    circle(player_x, player_y, 6, M_NOFILL);
}

void calAngles(){
    color(BLACK, WHITE, SOLID);
    for (uint8_t i = 0; i < 25; i++)
    {
        line(player_x, player_y, COS(i) + 10, SIN(i) + 10)
    }

    circle(player_x, player_y, 6, M_NOFILL);
}

void main(){

    set_sprite_data(0, 0, player);
    set_sprite_tile(0, 0);
    move_sprite(0, 88, 78);

    player_x = 88;
    player_y = 70;

    //drawlines();
    //gridify();
    SHOW_SPRITES;
    DISPLAY_ON;

    while(1){
        switch(joypad()){
            case J_LEFT:
                clearCalAngles();
                clearLastLine();
                player_x = player_x - 1;
                scroll_sprite(0,-1,0);
                break;
            case J_RIGHT:
                clearCalAngles();
                clearLastLine();
                player_x = player_x + 1;
                scroll_sprite(0,1,0);
                drawlines();
                calAngles();
                break;  
            case J_UP:
                clearCalAngles();
                clearLastLine();
                player_y = player_y - 1;
                scroll_sprite(0,0,-1);
                drawlines();
                calAngles();
                break; 
            case J_DOWN:
                clearCalAngles();
                clearLastLine();
                player_y = player_y + 1;
                scroll_sprite(0,0,1);
                drawlines();
                calAngles();
                break;                                                   
        }
        delay(100);
    }
}