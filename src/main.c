#include <stdio.h>
#include <stdlib.h>
#include "ticTacToe.h"

int cellsHaveLegalMove(int** cells){
    for(int i=0; i<3; i++){
        if(*cells[i] == -1)
            return i;
    }
    return NULL;
    // for(int i=0; i<3; i++){
    //     printf("%d\n",*cells[i]);
    // }
}


int main(){
   
    // cells* selectedCells = canWinNextMove(game.playerX);
    // if(selectedCells != NULL){
    //     // for(int i=0; i<3; i++){
    //     //     printf("%d\n",selectedCells[i]->leftColumn.score);

    //     // }

    //     printf("%d\n",selectedCells->score);
    //     printf("not null\n");
    // }
    // for(int i=0; i<8; i++){
    //     int newScore = playerScore(rowsColumnsDiags.all[i]->targetCells, game.playerX);
    //     updateScore(rowsColumnsDiags.all[i], newScore);
    // }
    // sortScores(rowsColumnsDiags.all);
    updateAndSortScores(game.playerX);
    for(int i=0; i<8; i++){
        // printf("%d\n", cellsHaveLegalMove(&rowsColumnsDiags.all[i]->targetCells));
        cellsHaveLegalMove(rowsColumnsDiags.all[i]->targetCells);
        printf("%s\n",cellsHaveLegalMove(rowsColumnsDiags.all[i]->targetCells) ? "true" : "false");
        // printf(" %d\n", rowsColumnsDiags.all[i]->score);
    }
    printf("end\n");
    system("pause");
    return 0;
}


 






  
    