#include <stdbool.h>
#include <stdio.h>
#include "sharedGameObjects.h"

bool isValidRange(int x, int y){
    return (x >= 0 && x <= 2 && y >= 0 && y <= 2 ) ? true : false;
}


bool moveAvailable(int x, int y){
    return (game.boardState[x][y] == -1) ? true: false;
}


bool isLegalMove(int x, int y){
    return (isValidRange(x, y) && moveAvailable(x, y)) ? true : false;
}


// bool cellsHaveLegalMove(int* cells){
//     for(int i=0; i<3; i++){
//         if(cells[i] == -1)
//             return true;
//     }
//     return false;
// }


void gameWon(int player){
    if(player == game.playerX)
        printf("YOU WIN!\n");
    else
        printf("COMPUTER WON!\n");
}


bool playerWon(int score){
    return score == 3 ? true : false;
}

//NOTE: input format = playerScore(rowsColumnsDiags.all[i]->targetCells, game.playerX);
int playerScore(int** cell, int player){
    int sum = 0;
    for(int i=0; i<3; i++){
        if(*cell[i] == player)
            sum++;
    }
    // updateScore(&cell[i], sum);
    return sum;
}


void updateScore(cells* object, int score){
    object->score = score;
}


void swapScores(cells* x, cells* y){
    cells temp = *x;
    *x = *y;
    *y = temp;
}


void sortScores(cells** array){
    for(int i=0; i<8; i++){
        for(int j=i+1; j<8; j++){
            if(array[i]->score < array[j]->score)
                swapScores(array[i], array[j]);
        }
    }
}


void updateAndSortScores(int player){
    for(int i=0; i<8; i++){
        int newScore = playerScore(rowsColumnsDiags.all[i]->targetCells, player);
        updateScore(rowsColumnsDiags.all[i], newScore);
    }
    sortScores(rowsColumnsDiags.all);
}
