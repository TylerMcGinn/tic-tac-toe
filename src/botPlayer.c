#include <stdbool.h>
#include "sharedGameObjects.h"

void botPlayerMove(){
    int randomMoveX = randomNumber(3);
    int randomMoveY = randomNumber(3);
    if(game.gameJustStarted){
        game.boardState[randomMoveX][randomMoveY] = game.playerO;
        game.gameJustStarted = false;
        drawBoard();
    }
    else{
        if(isLegalMove(randomMoveX, randomMoveY)){
            game.boardState[randomMoveX][randomMoveY] = game.playerO;
            drawBoard();
        }
        else{
            botPlayerMove();
        }
    }
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
