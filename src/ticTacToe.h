#ifndef TICTACTOE
#define TICTACTOE
#include <stdio.h>
#include <math.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
#define X_PLAY " X "
#define O_PLAY " O "
#define OPEN_POSITION "   "
#define VERTICAL_DIV " | "
#define HORIZONTAL_DIV "---"

int diagonals[] = {0,0};

void startGame();
void greeting();
void getUsersName();
void randomStart();
void play();
void botMove();
void botPlayMove();
void getPlayerMove();
int isValidRange(int x, int y);
int moveAvailable(int x, int y);
int isLegalMove(int x, int y);
char* drawMove(int play);
void drawBoard();
// void checkdiagonals(int player);
// int checkWin();
int randomBool();
int randomNumber(int upperLimit);
void delay(int ms);


struct TicTacToe{
    int playerTurn;
    int playerX;
    int playerO;
    int playerInputX;
    int playerInputY;
    int gameJustStarted;
    int finished;
    int boardState[3][3];
}game = {
    0,
    1,
    0,
    0,
    0,
    1,
    0,
    {{-1, -1, -1},
    {-1, -1, -1},
    {-1, -1, -1}}
};


struct{
    int* leftDiag[3];
    int* rightDiag[3];
    int* leftVert[3];
    int* middleVert[3];
    int* rightVert[3];
    int* upperHor[3];
    int* middleHor[3];
    int* lowerHor[3];
}point = {
    {
        //leftDiag
        &game.boardState[0][0],
        &game.boardState[1][1],
        &game.boardState[2][2]
    },
    {
        //rightDiag
        &game.boardState[0][2],
        &game.boardState[1][1],
        &game.boardState[2][0]
    },
    {
        //leftVert
        &game.boardState[0][0],
        &game.boardState[1][0],
        &game.boardState[2][0]
    
    },
    {
        //middleVert
        &game.boardState[0][1],
        &game.boardState[1][1],
        &game.boardState[2][1]
    },
    {
        //rightVert
        &game.boardState[0][2],
        &game.boardState[1][2],
        &game.boardState[2][2]
    },
    {
        //upperHor
        &game.boardState[0][0],
        &game.boardState[0][1],
        &game.boardState[0][2]
    },
    {
        //middleHor
        &game.boardState[1][0],
        &game.boardState[1][1],
        &game.boardState[1][2]
    },
     {
        //bottomHor
        &game.boardState[2][0],
        &game.boardState[2][1],
        &game.boardState[2][2]
    }
};



void startGame(){
    greeting();
    getUsersName();
    randomStart();
    while(1){
        play();
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


void getUsersName(){
    char usersName[100];
    printf("What's your name:");
    scanf("%s", &usersName);
    printf("\nHi %s, lets play, you will be X and I will be O\n",usersName);
}


void randomStart(){
    game.playerTurn = randomBool();
}


void play(){
    if(game.playerTurn){
        getPlayerMove();
        game.playerTurn = !game.playerTurn;
    }
    else{
        botPlayMove();
        game.playerTurn = !game.playerTurn;
    }
}

void botMove(){
    int randomMoveX = randomNumber(3);
    delay(randomNumber(1000));
    int randomMoveY = randomNumber(3);
    if(isLegalMove(randomMoveX, randomMoveY)){
        game.boardState[--randomMoveX][--randomMoveY] = game.playerO;
        drawBoard();
    }
    else{
        delay(500);
        botMove();
    }

}

void botPlayMove(){
    if(game.gameJustStarted){
        botMove();
        game.gameJustStarted = FALSE;
    }
    else{
        botMove();
    }
        
    //todo:gamecheck and play logic
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


// void checkdiagonals(int player){
//     diagonals[0] = 0, diagonals[1] = 0;
//     for(int i=0;i<3; i++){
//         if(game.boardState[i][i] == player)
//             diagonals[0]++;
//     }
//     for(int i=0; i<=2; i++){
//         if(game.boardState[i][abs(2-i)] == player)
//             diagonals[1]++;
//     }
// }


// int checkWin(){
//     for(int row=0; row<3; row++){
//         for(int col=0; col<3; col++){

//         }
//     }
// }

int randomBool(){
    srand(time(0));
    int rando = 1 + (rand() % 100);
    float number = rando / 100.0f;
    return round(number);
}


int randomNumber(int upperLimit){
    struct timespec ts;
    // timespec_get(&ts, TIME_UTC);

    // printf("&09ld\n",ts.tv_nsec);
    int seed = (ts.tv_nsec & time(NULL));
    srand(seed);
    int rando = 1 + (rand() % 1000);
    float number = rando / 1000.0f;
    return (int)((number * (upperLimit-1)) + 1);
}

void delay(int delayMs){
    int start = clock();
    while(clock() < (start + delayMs));
}


#endif