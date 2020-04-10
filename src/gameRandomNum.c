#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include "sharedGameObjects.h"


void generateSeed(){
    srand(time(0));
}


bool randomBool(){
    srand(time(0));
    int random = 1 + (rand() % 100);
    float number = random / 100.0f;
    return round(number);
}


int randomNumber(int upperLimit){
    return rand() % upperLimit;
}


void startingPlayerRandomize(){
    game.playerTurn = randomBool();
}

void delay(int delayMs){
    int start = clock();
    while(clock() < (start + delayMs));
}


