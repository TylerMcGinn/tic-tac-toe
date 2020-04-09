#ifndef TICTACTOE
#define TICTACTOE

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define X_PLAY " X "
#define O_PLAY " O "
#define OPEN_POSITION "   "
#define VERTICAL_DIV " | "
#define HORIZONTAL_DIV "---"

struct TicTacToe{
    bool playerTurn;
    bool playerX;
    bool playerO;
    int playerInputX;
    int playerInputY;
    bool gameJustStarted;
    int boardState[3][3];
};

typedef struct{
    int score;
    int* targetCells[3];
}cells;

void generateSeed();
void startGame();
void greeting();
void getUsersName();
void startingPlayerRandomize();
void play();
void botPlayerMove();
void getPlayerMove();
bool isValidRange(int x, int y);
bool moveAvailable(int x, int y);
bool isLegalMove(int x, int y);
char* drawMove(int play);
void drawBoard();
void gameIsDraw();
void gameWon();
int checkWin();
bool playerWon(int score);
int playerScore(int** cell, int player);
bool randomBool();
int randomNumber(int upperLimit);
void delay(int ms);
void updateScore(cells* object, int score);
void swapScores(cells* x, cells* y);
void sortScores(cells** array);


struct TicTacToe game = {
    false,
    true,
    false,
    0,
    0,
    true,
    // {{-1, -1, -1},
    // {-1, -1, -1},
    // {-1, -1, -1}}
    // {{1, 2, 3},
    // {4, 5, 6},
    // {7, 8, 9}}
     {{1, 1, 0},
    {-1, -1, 0},
    {-1, -1, -1}}
};


struct{
    cells leftDiag;
    cells rightDiag;
    cells upperRow;
    cells middleRow;
    cells lowerRow;
    cells leftColumn;
    cells middleColumn;
    cells rightColumn;
    cells* all[8];
}rowsColumnsDiags = {
    {
        0,
        {
            //leftDiag
            &game.boardState[0][0],
            &game.boardState[1][1],
            &game.boardState[2][2]
        }
    },
    {
        0,
        {
            //rightDiag
            &game.boardState[0][2],
            &game.boardState[1][1],
            &game.boardState[2][0]
        }
    },
    {
        0,
        {
            //upperRow
            &game.boardState[0][0],
            &game.boardState[1][0],
            &game.boardState[2][0]
        }
    },
    {
        0,
        {
            //middleRow
            &game.boardState[0][1],
            &game.boardState[1][1],
            &game.boardState[2][1]
        }
    },
    {
        0,
        {
            //bottomRow
            &game.boardState[0][2],
            &game.boardState[1][2],
            &game.boardState[2][2]
        }
    },
    {
        0,
        {
            //leftColumn
            &game.boardState[0][0],
            &game.boardState[0][1],
            &game.boardState[0][2]
        }
    },
    {
        0,
        {
            //middleColumn
            &game.boardState[1][0],
            &game.boardState[1][1],
            &game.boardState[1][2]
        }
    },
     {
         0,
         {
            //rightColumn
            &game.boardState[2][0],
            &game.boardState[2][1],
            &game.boardState[2][2]
         }
    },
    {
        //array of all rows, columns and diagonals
        &rowsColumnsDiags.leftDiag,
        &rowsColumnsDiags.rightDiag,
        &rowsColumnsDiags.leftColumn,
        &rowsColumnsDiags.middleColumn,
        &rowsColumnsDiags.rightColumn,
        &rowsColumnsDiags.upperRow,
        &rowsColumnsDiags.middleRow,
        &rowsColumnsDiags.lowerRow
    }
};


void generateSeed(){
    srand(time(0));
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


void startingPlayerRandomize(){
    game.playerTurn = randomBool();
}


void play(){
    if(game.playerTurn){
        getPlayerMove();
        game.playerTurn = false;
    }
    else{
        botPlayerMove();
        game.playerTurn = true;
    }
}


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



bool isValidRange(int x, int y){
    return (x >= 0 && x <= 2 && y >= 0 && y <= 2 ) ? true : false;
}


bool moveAvailable(int x, int y){
    return (game.boardState[x][y] == -1) ? true: false;
}


bool isLegalMove(int x, int y){
    return (isValidRange(x, y) && moveAvailable(x, y)) ? true : false;
}


void getPlayerMove(){
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


void gameIsDraw(){

}


void gameWon(int player){
    if(player == game.playerX)
        printf("YOU WIN!\n");
    else
        printf("COMPUTER WON!\n");
    
}



int checkWin(int player){
    
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
    return sum;
}


bool randomBool(){
    srand(time(0));
    int random = 1 + (rand() % 100);
    float number = random / 100.0f;
    return round(number);
}


int randomNumber(int upperLimit){
    return rand() % upperLimit;
}


void delay(int delayMs){
    int start = clock();
    while(clock() < (start + delayMs));
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

#endif