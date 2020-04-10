#include <stdio.h>
#include <stdlib.h>
#include "ticTacToe.h"


int main(){
    //   for(int i=0; i<8; i++){
    //     int newScore = playerScore(rowsColumnsDiags.all[i]->targetCells, game.playerX);
    //     updateScore(rowsColumnsDiags.all[i], newScore);
    // }
    // sortScores(rowsColumnsDiags.all);
    // for(int i=0; i<8; i++){
    //     printf("%d\n", rowsColumnsDiags.all[i]->score);
    // }
    boardPositions* selectedCells = canWinNextMove(game.playerX);
    if(selectedCells != NULL){
        for(int i=0; i<3; i++){
            printf("%d\n",**selectedCells[i]->leftColumn.score);

        }
        printf("not null");
    }
    printf("end\n");
    
    system("pause");
    return 0;
}









  
    