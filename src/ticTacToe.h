#ifndef TICTACTOE
#define TICTACTOE


#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include "sharedGameObjects.h"


//botPlayer.c - bot player functions
void echoBotMove(int x, int y);
void botRandomMove();
bool increaseScore();
void botPlayerMove();


//userPlayer.c - user player functions
void getUsersName();
void userPlayerMove();


//game.c - main game step through logic
void greeting();
void playGame();
char* drawMove(int play);
void drawBoard();
void play();


//gameUtil.c - shared validation, sorting and update functions
bool isValidRange(int x, int y);
bool moveAvailable(int x, int y);
bool isLegalMove(int x, int y);
int cellsHaveLegalMove(int** cells);
void echoGameOver();
int playerScore(int** cell, int player);
void updateScore(cells* object, int score);
void swapScores(cells* x, cells* y);
void sortScores(cells** array);
void updateAndSortScores(int player);
int* canWinNextMove(int player);
bool openMoves();
bool checkForWinner();
int* availableCellGroup(int index);


//gameRandomNum.c - delay and random number functions
void generateSeed();
bool randomBool();
int randomNumber(int upperLimit);
void startingPlayerRandomize();
void delay(int ms);



TicTacToe game = {
    false,
    true,
    false,
    0,
    0,
    true,
    -1,
    {{-1, -1, -1},
    {-1, -1, -1},
    {-1, -1, -1}}
    // {{-1, -1, -1},
    // {-1, -1, 0},
    // {-1, -1, -1}}
};


boardPositions rowsColumnsDiags = {
    {
        0,
        {{0,0},{1,1},{2,2}},
        {
            //leftDiag
            &game.boardState[0][0],
            &game.boardState[1][1],
            &game.boardState[2][2]
        }
    },
    {
        0,
        {{0,2},{1,1},{2,0}},
        {
            //rightDiag
            &game.boardState[0][2],
            &game.boardState[1][1],
            &game.boardState[2][0]
        }
    },
    {
        0,
        {{0,0},{1,0},{2,0}},
        {
            //upperRow
            &game.boardState[0][0],
            &game.boardState[1][0],
            &game.boardState[2][0]
        }
    },
    {
        0,
        {{0,1},{1,1},{2,1}},
        {
            //middleRow
            &game.boardState[0][1],
            &game.boardState[1][1],
            &game.boardState[2][1]
        }
    },
    {
        0,
        {{0,2},{1,2},{2,2}},
        {
            //bottomRow
            &game.boardState[0][2],
            &game.boardState[1][2],
            &game.boardState[2][2]
        }
    },
    {
        0,
        {{0,0},{0,1},{0,2}},
        {
            //leftColumn
            &game.boardState[0][0],
            &game.boardState[0][1],
            &game.boardState[0][2]
        }
    },
    {
        0,
        {{1,0},{1,1},{1,2}},
        {
            //middleColumn
            &game.boardState[1][0],
            &game.boardState[1][1],
            &game.boardState[1][2]
        }
    },
     {
         0,
         {{2,0},{2,1},{2,2}},
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


#endif