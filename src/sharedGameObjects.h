#ifndef GAME_OBJECTS
#define GAME_OBJECTS

#define X_PLAY " X "
#define O_PLAY " O "
#define OPEN_POSITION "   "
#define VERTICAL_DIV " | "
#define HORIZONTAL_DIV "---"

typedef struct {
    bool playerTurn;
    bool playerX;
    bool playerO;
    int playerInputX;
    int playerInputY;
    bool gameJustStarted;
    bool gameInPlay;
    bool winningPlayer;
    int boardState[3][3];
}TicTacToe;


typedef struct{
    int score;
    int coordinates[3][2];
    int* targetCells[3];
}cells;


typedef struct {
    cells leftDiag;
    cells rightDiag;
    cells upperRow;
    cells middleRow;
    cells lowerRow;
    cells leftColumn;
    cells middleColumn;
    cells rightColumn;
    cells* all[8];
}boardPositions;


TicTacToe game;


boardPositions rowsColumnsDiags;


#endif