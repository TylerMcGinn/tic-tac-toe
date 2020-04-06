#ifndef TICTACTOE
#define TICTACTOE
#include <stdio.h>


void startGame();
void getUsersName();
void drawBoard();
void greeting();


typedef struct{
    char* boardVertical;
    char* boardHorizontal;
    char* playerX;
    char* playerO;
    char* state[3][3];
    void (*startGame)();
    void (*drawBoard)();
}ticTacToe;


ticTacToe game = {
    " | ",
    "---",
    " x ",
    " o ",
    {{"   ","   ","   "},
    {"   ","   ","   "},
    {"   ","   ","   "}},
    &startGame,
    &drawBoard
};


void startGame(){
    greeting();
}

void getUsersName(){
    printf("What's your name:");
    //todo:start here
}



void drawBoard(){
    for(int row=0; row < 3; row++){
        for(int col = 0; col < 2; col++){
            printf("%s", game.state[row][col]);
            if(col < 2)
                printf("%s",game.boardVertical);
        }
        if(row < 2)
            printf("\n%s%s%s%s%s\n",game.boardHorizontal, game.boardVertical, game.boardHorizontal, game.boardVertical, game.boardHorizontal);
    }
    printf("\n");
}


void greeting(){
    char* game = "Tic-Tac-Toe";
    char* myName = "Tyler McGinn T00661302";
    char* course = "COMP 2131 - SPRING 2020";
    char* message = "You will be playing against the Computer!";
    for(int i=0; i<80; i++) printf("*");
    printf("\n%s\n%s\n%s\n%s\n",game, myName, course, message);
    for(int i=0; i<80; i++) printf("*");
}

#endif