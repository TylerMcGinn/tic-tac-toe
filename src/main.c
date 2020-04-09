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
}


int main(){
    generateSeed();
    for(int i=0; i<8; i++){
        // printf("%d\n", playerScore(rowsColumnsDiags.all[i]->targetCells, game.playerX));
        int newScore = playerScore(rowsColumnsDiags.all[i]->targetCells, game.playerX);
        updateScore(rowsColumnsDiags.all[i], newScore);
    }
    sortScores(rowsColumnsDiags.all);
    for(int i=0; i<8; i++){
        printf("%d\n", rowsColumnsDiags.all[i]->score);
    }
    
    system("pause");
    return 0;
}