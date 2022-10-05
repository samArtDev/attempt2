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
uint8_t emptyTruthTable[4] = {0, 0, 0, 0};

uint8_t totalNumbOfTiles = 4;

int8_t centerX = 10;
int8_t centerY = 9;
int8_t tempX;
int8_t tempY;
uint8_t centerTile;
uint8_t placeholderCenterTile[4];
uint8_t placeholderRandArray[4];

void setPosition(uint8_t x, uint8_t y){
    centerX = x;
    centerY = y;
}

uint8_t rollRNG(){
    uint8_t randomNumberIndex = rand();
    randomNumberIndex = randomNumberIndex % 4;
    assignTruthTable(placeholderRandArray[4], randomNumberIndex);
    return(randomNumberIndex);
}

void setCenterTile(uint8_t centerX, uint8_t centerY, uint8_t centerTile){
    assignTruthTable(placeholderCenterTile, centerTile);
    set_bkg_tile_xy(centerX, centerY, centerTile);
}

void assignTruthTable(uint8_t arrayToBeAssigned[4], uint8_t index){

    uint8_t arrayToBeAssigned[4] = {0, 0, 0, 0};

    switch (index)
    {
    case 0:
        for (uint8_t i = 0; i < 3; i++)
        {
            arrayToBeAssigned[i] = blankTruthTable[i];
        }
        break;

    case 1:
        for (uint8_t i = 0; i < 3; i++)
        {
            arrayToBeAssigned[i] = upTruthTable[i];
        }
        break;

    case 2:
        for (uint8_t i = 0; i < 3; i++)
        {
            arrayToBeAssigned[i] = rightTruthTable[i];
        }
        break;
    
    case 3:
        for (uint8_t i = 0; i < 3; i++)
        {
            arrayToBeAssigned[i] = downTruthTable[i];
        }
        break;
    
    case 4:
        for (uint8_t i = 0; i < 3; i++)
        {
            arrayToBeAssigned[i] = leftTruthTable[i];
        }
        break;

    case 5:
        for (uint8_t i = 0; i < 3; i++)
        {
            arrayToBeAssigned[i] = emptyTruthTable[i];
        }
        break;
    }
}

void placeTile(){
    uint8_t RNGval = rollRNG();

    if(isN_Good == true){
        if(placeholderCenterTile[0] != placeholderRandArray[2]){
            rollRNG();
            placeTile();
        }
        if(placeholderCenterTile[1] != placeholderRandArray[3]){
            rollRNG();
            placeTile();
        }
        else{
            set_bkg_data(tempX, tempY, RNGval);
        }
    }
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
        placeTile(tempX, tempY);
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
        placeTile(tempX, tempY);
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
        placeTile(tempX, tempY);
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
        placeTile(tempX, tempY);
    } 
}

void main(){
    set_bkg_data(0, 5, TileLabel);
    setCenterTile(10, 9, rollRNG());
    for (uint8_t i = 0; i < 10; i++)
    {
        setPosition(i, 0); //temp values
        isN_Good(); //these are for debugging
        isE_Good(); //i'll refactor later
        isW_Good();
        isS_Good();

    }
    delay(1000);
    SHOW_BKG;
    DISPLAY_ON;
}