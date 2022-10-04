#include <gb/gb.h>
#include <stdio.h>
#include <stdbool.h>
#include <rand.h>

#include "tiles.c"
#include "tilebkrmap.c"

uint8_t blankTruthTable[4] = {0, 0, 0, 0};
uint8_t upTruthTable[4] = {1, 1, 0, 1};
uint8_t rightTruthTable[4] = {1, 1, 1, 0};
uint8_t downTruthTable[4] = {0, 1, 1, 1};
uint8_t leftTruthTable[4] = {1, 0, 1, 1};

uint8_t totalNumbOfTiles = 4;

int8_t centerX = 10;
int8_t centerY = 9;
int8_t tempX;
int8_t tempY;
uint8_t centerTile[4];
uint8_t tempArray[4];

uint8_t rollRNG(){
    uint8_t randomNumberIndex = rand();
    randomNumberIndex = randomNumberIndex % 4;
    return(randomNumberIndex);
}

void setCenterTile(uint8_t centerX, uint8_t centerY, uint8_t centerTile){
    set_bkg_tile_xy(centerX, centerY, centerTile);
}

void isN_Good(){
    tempX = centerX;
    tempY = centerY - 1;
    if (tempX < 0 | tempY < 0)
    {
        return false;
    }
    
    if(get_bkg_tile_xy(tempX, tempY) == 0){
        return true;
    } 
}

void isE_Good(){
    tempX = centerX - 1;
    tempY = centerY;
    if (tempX < 0 | tempY < 0)
    {
        return false;
    }
    
    if(get_bkg_tile_xy(tempX, tempY) == 0){
        return true;
    } 
}

void isW_Good(){
    tempX = centerX + 1;
    tempY = centerY;
    if (tempX < 0 | tempY < 0)
    {
        return false;
    }
    
    if(get_bkg_tile_xy(tempX, tempY) == 0){
        return true;
    } 
}

void isS_Good(){
    tempX = centerX;
    tempY = centerY + 1;
    if (tempX < 0 | tempY < 0)
    {
        return false;
    }
    
    if(get_bkg_tile_xy(tempX, tempY) == 0){
        return true;
    } 
}

void main(){
    set_bkg_data(0, 5, TileLabel);
    //set_bkg_tile_xy(centerX, centerY, 2);
    setCenterTile(10, 9, rollRNG());
    for (uint8_t i = 0; i < 10; i++)
    {
        setPosition(i, 0);
        isN_Good();
        isE_Good();
        isW_Good();
        isS_Good();

    }
    
    setN_E_W_S();
    delay(1000);
    SHOW_BKG;
    DISPLAY_ON;
}