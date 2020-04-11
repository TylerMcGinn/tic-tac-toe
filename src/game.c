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


void playGame(){
    generateSeed();
    greeting();
    getUsersName();
    startingPlayerRandomize();
    while(checkForWinner() && openMoves()){
        play();
    }
    echoGameOver(game.winningPlayer);
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
        game.playerTurn = game.playerO;
    }
    else{
        botPlayerMove();
        game.playerTurn = game.playerX;
    }
}