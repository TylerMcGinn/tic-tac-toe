#include <stdbool.h>
#include <stdio.h>
#include "sharedGameObjects.h"


void getUsersName(){
    char usersName[100];
    printf("What's your name:");
    scanf("%s", &usersName);
    printf("\nHi %s, lets play, you will be X and I will be O\n",usersName);
}


void userPlayerMove(){
    printf("\nEnter your move X,Y:");
    scanf("%d , %d", &game.playerInputX, &game.playerInputY);
    game.playerInputX--;
    game.playerInputY--;
    if(isLegalMove(game.playerInputX, game.playerInputY)){
        game.boardState[game.playerInputX][game.playerInputY] = game.playerX;
        fflush(stdin);
        drawBoard();
    }
    else{
        printf("\nIllegal move! try again.\n");
        fflush(stdin);
        userPlayerMove();
    }
}