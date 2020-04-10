#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "sharedGameObjects.h"


void echoBotMove(int x, int y){
    printf("Computer played:%d,%d\n",x + 1, y + 1);
    drawBoard();
}


void botRandomMove(){
    int randomMoveX = randomNumber(3);
    int randomMoveY = randomNumber(3);
    game.boardState[randomMoveY][randomMoveX] = game.playerO;
    echoBotMove(randomMoveX, randomMoveY);
}





//TODO: need to clean this method up
void botPlayerMove(){
    if(game.gameJustStarted){
        botRandomMove();
        game.gameJustStarted = false;
    }
    else if(canWinNextMove(game.playerO) != NULL){
        
     
    }
    else if(canWinNextMove(game.playerX) != NULL){

    }
    else
    {
        botRandomMove();
    }
}






