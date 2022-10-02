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
uint8_t centerTile = 2;
uint8_t tempArray[];

void rollRNG(){
    uint8_t randomNumberIndex = rand();
    randomNumberIndex = randomNumberIndex % 4;
    validateRand(randomNumberIndex);
}

void validateRand(uint8_t RNGval){
    if(RNGval == 0){
        tempArray[4] = blankTruthTable[4];
    }
    if(RNGval == 1){
        tempArray[4] = upTruthTable[4];
    }
    if(RNGval == 2){
        tempArray[4] = rightTruthTable[4];
    }
    if(RNGval == 3){
        tempArray[4] = downTruthTable[4];
    }
    if(RNGval == 4){
        tempArray[4] = leftTruthTable[4];
    }

    for (uint8_t i = 0; i < 3; i++){
        if (tempArray[RNGval] != centerTile[RNGval]){
            if(i == 0){
                tempX = centerX;
                tempY = centerY - 1;
                set_bkg_tile_xy(centerX, centerY, 0);
            }
            if(i == 1){
                tempX = centerX + 1;
                tempY = centerY;
                set_bkg_tile_xy(centerX, centerY, 1);
            }
            if(i == 2){
                tempX = centerX;
                tempY = centerY + 1;
                set_bkg_tile_xy(centerX, centerY, 2);
            }
            if(i == 3){
                tempX = centerX - 1;
                tempY = centerY;
                set_bkg_tile_xy(centerX, centerY, 3)
            }
        }
        else{
            rollRNG();
        }
        
    }
    
}

void main(){
    set_bkg_data(0, 5, TileLabel);
    set_bkg_tile_xy(centerX, centerY, 2);
    while(1){
        validateRand();
        delay(1000);
    }
    SHOW_BKG;
    DISPLAY_ON;
}