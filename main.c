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

void setCenterTile(){
    uint8_t randomNumberIndex = rand();
    randomNumberIndex = randomNumberIndex % 4;
    set_bkg_tile_xy(centerX, centerY, randomNumberIndex);
}

void getCenterTile(){
    
}

uint8_t rollRNG(uint8_t centerTile, uint8_t tempX, uint8_t tempY){
    uint8_t randomNumberIndex = rand();
    randomNumberIndex = randomNumberIndex % 4;

    for(uint8_t i = 0; i < 3; i++){
        for (uint8_t j = 0; j < 3; j++)
        {
        if(centerTile[i] = )
        }
        
    }

    /*
    printf("%hu", randomNumberIndex);
    printf("%s", " ");
    */
   return randomNumberIndex;
}

void northTile(){
    tempX = centerX;
    tempY = centerY - 1;
}

void eastTile(){
    tempX = centerX + 1;
    tempY = centerY;
}

void southTile(){
    tempX = centerX;
    tempY = centerY + 1;
}

void westTile(){
    tempX = centerX - 1;
    tempY = centerY;
}

void wtf_is_entropy(){


    set_bkg_data(0, 5, TileLabel);
    set_bkg_tile_xy(centerX, centerY, centerTile);

/*
    if(startingX <= 0){
        //skip
    }
*/

    if(get_bkg_tile_xy(centerX, centerY) == 0){
        if(centerX > 0){
            tempX = centerX - 1;
            tempY = centerY;
            uint8_t i = rollRNG();
            if()
        }

        else{
            tempX = centerX - 1;
            tempY = centerY;
            if(){

            }
            set_bkg_tile_xy(tempX, tempY, #);
        }
    }

    if (rollRNG() == 0)
    {


    }

    SHOW_BKG;
    DISPLAY_ON;
}

void main(){
    while(1){
        wtf_is_entropy();
        delay(1000);
    }
/*
    set_bkg_data(0, 5, TileLabel);
    set_bkg_tiles(0, 0, 20, 18, tilebkrmaplabel);

    for(int8_t y = 0; y<9; y++){
        for(int8_t x = 0; x<20; x++){
            set_bkg_tile_xy(x, y, 0);
        }
    }
    SHOW_BKG;
    DISPLAY_ON;    
*/
}