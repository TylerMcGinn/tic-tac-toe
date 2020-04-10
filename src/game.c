#include <stdbool.h>
#include <stdio.h>
#include "sharedGameObjects.h"


void greeting(){
    char* game = "Tic-Tac-Toe";
    char* myName = "Tyler McGinn T00661302";
    char* course = "COMP 2131 - SPRING 2020";
    char* message = "You will be playing against the Computer!";
    for(int i=0; i<80 ; i++) printf("*");
    printf("\n%s\n%s\n%s\n%s\n",game, myName, course, message);
    for(int i=0; i<80; i++) printf("*");
    printf("\n\n");
}


void startGame(){
    generateSeed();
    greeting();
    getUsersName();
    startingPlayerRandomize();
    while(1){
        play();
    }
}


char* drawMove(int play){
    return play == -1 ? OPEN_POSITION : (play == 1) ? X_PLAY : O_PLAY;
}


void drawBoard(){
    for(int row=0; row < 3; row++){
        for(int col = 0; col < 3; col++){
            printf("%s",drawMove(game.boardState[row][col]));
            if(col < 2)
                printf("%s", VERTICAL_DIV);
        }
        if(row < 2)
            printf("\n%s%s%s%s%s\n", HORIZONTAL_DIV, VERTICAL_DIV, HORIZONTAL_DIV, VERTICAL_DIV, HORIZONTAL_DIV);
    }
    printf("\n");
}


void play(){
    if(game.playerTurn){
        userPlayerMove();
        game.playerTurn = false;
    }
    else{
        botPlayerMove();
        game.playerTurn = true;
    }
}


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

  
cells* canWinNextMove(int player){
    updateAndSortScores(player);
    for(int i=0; i<8; i++){
        int score = playerScore(rowsColumnsDiags.all[i]->targetCells, player);
        int move = cellsHaveLegalMove(rowsColumnsDiags.all[i]->targetCells);
        if(score == 2 && move != NULL)
            return rowsColumnsDiags.all[i]->coordinates[move];
    }
    return NULL;
}