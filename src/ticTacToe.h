#ifndef TICTACTOE
#define TICTACTOE
#include <stdio.h>
#include <math.h>
#define X_PLAY " X "
#define O_PLAY " O "
#define OPEN_POSITION "   "
#define VERTICAL_DIV " | "
#define HORIZONTAL_DIV "---"

int diagonals[] = {0,0};

void startGame();
void greeting();
void getUsersName();
void getPlayerMove();
int isValidRange(int x, int y);
int moveAvailable(int x, int y);
int isLegalMove(int x, int y);
char* drawMove(int play);
void drawBoard();
void checkdiagonals(int player);
int checkWin();
int betweenOneAndThree();

struct{
    int playerX;
    int playerO;
    int playerInputX;
    int playerInputY;
    int finished;
    int boardState[3][3];
}game = {
    1,
    0,
    0,
    0,
    0,
    {{0, -1, -1},
    {-1, 1, -1},
    {0, -1, 1}}
};


void startGame(){
    greeting();
    getUsersName();
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


void getUsersName(){
    char usersName[100];
    printf("What's your name:");
    scanf("%s", &usersName);
    printf("\nHi %s, lets play, you will be X and I will be O\n",usersName);
}


int isValidRange(int x, int y){
    return (x >= 1 && x <= 3 && y >= 1 && y <= 3 ) ? 1 : 0;
}


int moveAvailable(int x, int y){
    return (game.boardState[--x][--y] == -1) ? 1 : 0;
}


int isLegalMove(int x, int y){
    return (isValidRange(x, y) && moveAvailable(x, y)) ? 1 : 0;
}


void getPlayerMove(){
    char separator;
    printf("\nEnter your move X,Y:");
    scanf("%d , %d", &game.playerInputX, &game.playerInputY);
    if(isLegalMove(game.playerInputX, game.playerInputY)){
        game.boardState[--game.playerInputX][--game.playerInputY] = game.playerX;
        fflush(stdin);
        drawBoard();
    }
    else{
        printf("\nIllegal move! try again.\n");
        fflush(stdin);
        getPlayerMove();
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


void checkdiagonals(int player){
    diagonals[0] = 0, diagonals[1] = 0;
    for(int i=0;i<3; i++){
        if(game.boardState[i][i] == player)
            diagonals[0]++;
    }
    for(int i=0; i<=2; i++){
        if(game.boardState[i][abs(2-i)] == player)
            diagonals[1]++;
    }
}


int checkWin(){
    for(int row=0; row<3; row++){
        for(int col=0; col<3; col++){

        }
    }
}


int betweenOneAndThree(){
    rand()
    //todo: make random number between 1 and 3
}


#endif