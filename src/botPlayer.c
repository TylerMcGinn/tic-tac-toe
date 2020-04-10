#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "sharedGameObjects.h"


void echoBotMove(int x, int y){
    printf("Computer played:%d,%d\n",x + 1, y + 1);
    drawBoard();
}


cells* canWinNextMove(int player){
    for(int i=0; i<8; i++){
        if(playerScore(rowsColumnsDiags.all[i]->targetCells, player) == 2)
            return rowsColumnsDiags.all[i];
    }
    return NULL;
}


//TODO: need to clean this method up
void botPlayerMove(){
    int randomMoveX = randomNumber(3);
    int randomMoveY = randomNumber(3);
    if(game.gameJustStarted){
        game.boardState[randomMoveY][randomMoveX] = game.playerO;
        game.gameJustStarted = false;
        echoBotMove(randomMoveX, randomMoveY);
    }
    else{
        updateAndSortScores(game.playerO);
        // int** winningMoveBot = canWinNextMove(game.playerO);
        // int** winningMovePlayer = canWinNextMove(game.playerX);
        // if(winningMoveBot != NULL){
        //     for(int i=0; i<3; i++){
        //         if(*winningMoveBot[i] == -1)
        //             *winningMoveBot[i] = 0;
        //     }
        //     echoBotMove(randomMoveX, randomMoveY);
        // }
        // else if(*winningMovePlayer != NULL){

        // }
    }
}






