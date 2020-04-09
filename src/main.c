#include <stdio.h>
#include <stdlib.h>
#include "ticTacToe.h"
#include <ctype.h>

void testplayerScore(int** cell, int player){
    int sum = 0;
    for(int i=0; i<3; i++){
        printf("value:%d\n",*cell[i]);
        if(*cell[i] == player)
            sum++;
    }
    printf("sum:%d\n",sum);
    // return sum;
}

void updateScore(lines* object){
    object->score++;
}

int main(){
    generateSeed();
    testplayerScore(rowsColumnsDiags.all[0],game.playerX);

    system("pause");
    return 0;
}