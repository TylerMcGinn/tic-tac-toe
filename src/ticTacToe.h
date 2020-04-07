#ifndef TICTACTOE
#define TICTACTOE
#include <stdio.h>


void startGame();
void getUsersName();
void drawBoard();
void greeting();
void getPlayerMove();


typedef struct{
    char* boardVertical;
    char* boardHorizontal;
    char* playerX;
    char* playerO;
    char* state[3][3];
    int playerMoveX;
    int playerMoveY;
    void (*startGame)();
    void (*drawBoard)();
}ticTacToe;


ticTacToe game = {
    " | ",
    "---",
    " X ",
    " O ",
    {{"   ","   ","   "},
    {"   ","   ","   "},
    {"   ","   ","   "}},
    0,
    0,
    &startGame,
    &drawBoard
};


void startGame(){
    greeting();
    getUsersName();
}


void getUsersName(){
    char usersName[100];
    printf("What's your name:");
    scanf("%s", &usersName);
    printf("\nHi %s, lets play, you will be X and I will be O\n",usersName);
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


void getPlayerMove(){
    // char separator[80];
    char separator;
    // game.playerMoveX = 0;
    // game.playerMoveY = 0;
    printf("\nEnter your move X,Y:");
    scanf("%d %d", &game.playerMoveX, &game.playerMoveY);
    if(game.playerMoveX >= 1 && game.playerMoveX <= 3 && game.playerMoveY >= 1 && game.playerMoveY <= 3 ){
        game.state[--game.playerMoveX][--game.playerMoveY] = game.playerX;
        drawBoard();
        // printf("hit");
    }
    else
    {
        printf("\nIllegal move! try again.\n");
        getPlayerMove();
    }
    
}


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

#endif