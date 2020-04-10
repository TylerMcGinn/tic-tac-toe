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


int cellsHaveLegalMove(int** cells){
    for(int i=0; i<3; i++){
        if(*cells[i] == -1)
            return i;
    }
    return NULL;
}


void echoGameOver(int player){
    if(player == game.playerX)
        printf("YOU WIN!\n");
    else if(player == game.playerO)
        printf("COMPUTER WON!\n");
    else
        printf("DRAW!\n");
}


//NOTE: input format = playerScore(rowsColumnsDiags.all[i]->targetCells, game.playerX);
int playerScore(int** cell, int player){
    int sum = 0;
    for(int i=0; i<3; i++){
        if(*cell[i] == player)
            sum++;
    }
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

  
int* canWinNextMove(int player){
    updateAndSortScores(player);
    for(int i=0; i<8; i++){
        int score = playerScore(rowsColumnsDiags.all[i]->targetCells, player);
        int move = cellsHaveLegalMove(rowsColumnsDiags.all[i]->targetCells);
        if(score == 2 && move != NULL)
            return rowsColumnsDiags.all[i]->coordinates[move];
    }
    return NULL;
}


void openMoves(){
    bool openPositions = false;
    for(int row=0; row<3; row++){
        for(int col=0; col<3; col++){
            if(game.boardState[row][col] == -1)
                openPositions = true;
            // printf("val:%d\n", game.boardState[row][col]);
        }
    }
    game.gameInPlay = openPositions;
}


void checkForWinner(){
    for(int i=0; i<8; i++){
        // printf("%d\n",playerScore(rowsColumnsDiags.all[i]->targetCells, game.playerO));
        if(playerScore(rowsColumnsDiags.all[i]->targetCells, game.playerX) == 3){
            printf("\nhit Player O\n");
            game.winningPlayer = game.playerX;
            game.gameInPlay = false;
            printf("%s\n", game.gameInPlay ? "true": "false");

        }
        if(playerScore(rowsColumnsDiags.all[i]->targetCells, game.playerO) == 3){
            printf("\nhit Player O\n");
            game.winningPlayer = game.playerO;
            game.gameInPlay = false;
            printf("%s\n", game.gameInPlay ? "true": "false");
        }
    }
}