#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "sharedGameObjects.h"


void echoBotMove(int x, int y){
    delay(500);
    printf("\nComputer played:%d,%d\n",x + 1, y + 1);
    drawBoard();
}


void botRandomMove(){
    int randomMoveRow = randomNumber(3);
    int randomMoveCol = randomNumber(3);
    if(isLegalMove(randomMoveRow, randomMoveCol)){
        game.boardState[randomMoveRow][randomMoveCol] = game.playerO;
        echoBotMove(randomMoveRow, randomMoveCol);
    }
    else
        botRandomMove();
}


bool increaseScore(){
    updateAndSortScores(game.playerO);
    int i=0;
    while(rowsColumnsDiags.all[i]->score >= 1){
        int* availableGroup = availableCellGroup(i);
        if(availableGroup != NULL){
            int row = availableGroup[0];
            int col = availableGroup[1];
        // printf("%d,%d\n",row,col);

            game.boardState[row][col] = game.playerO;
            return true;
        }
        i++;
    }
    return false;
}



void botPlayerMove(){
    //make starting random move
    if(game.gameJustStarted){
        botRandomMove();
        game.gameJustStarted = false;
    }
    //if can win, play winning move
    else if(canWinNextMove(game.playerO) != NULL){
        int* moveCoordinates = canWinNextMove(game.playerO);
        int row = moveCoordinates[0];
        int col = moveCoordinates[1];
        game.boardState[row][col] = game.playerO;
        echoBotMove(row, col);
    }
    //if user is about to win, try to block
    else if(canWinNextMove(game.playerX) != NULL){
        int* moveCoordinates = canWinNextMove(game.playerX);
        int row = moveCoordinates[0];
        int col = moveCoordinates[1];
        game.boardState[row][col] = game.playerO;
        echoBotMove(row, col);
    }
    else
    {
        if(!increaseScore())
            botRandomMove();
    }
}






