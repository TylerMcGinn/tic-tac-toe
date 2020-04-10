#ifndef TICTACTOE
#define TICTACTOE


#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include "sharedGameObjects.h"


//gameUtil.c
void generateSeed();
bool randomBool();
int randomNumber(int upperLimit);
void startingPlayerRandomize();
void delay(int ms);


//botPlayer.c
void echoBotMove(int x, int y);
void botRandomMove();
void botPlayerMove();


//userPlayer.c
void getUsersName();
void userPlayerMove();


//game.c
void greeting();
void startGame();
char* drawMove(int play);
void drawBoard();
void play();
bool isValidRange(int x, int y);
bool moveAvailable(int x, int y);
bool isLegalMove(int x, int y);
int cellsHaveLegalMove(int** cells);
void gameWon();
bool playerWon(int score);
int playerScore(int** cell, int player);
void updateScore(cells* object, int score);
void swapScores(cells* x, cells* y);
void sortScores(cells** array);
void updateAndSortScores(int player);
cells* canWinNextMove(int player);


TicTacToe game = {
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
    {-1, -1, -1},
    {-1, -1, -1}}
};


boardPositions rowsColumnsDiags = {
    {
        0,
        {{1,1},{2,2},{3,3}},
        {
            //leftDiag
            &game.boardState[0][0],
            &game.boardState[1][1],
            &game.boardState[2][2]
        }
    },
    {
        0,
        {{1,2},{2,2},{3,3}},
        {
            //rightDiag
            &game.boardState[0][2],
            &game.boardState[1][1],
            &game.boardState[2][0]
        }
    },
    {
        0,
        {{1,3},{2,2},{3,3}},
        {
            //upperRow
            &game.boardState[0][0],
            &game.boardState[1][0],
            &game.boardState[2][0]
        }
    },
    {
        0,
        {{1,4},{2,2},{3,3}},
        {
            //middleRow
            &game.boardState[0][1],
            &game.boardState[1][1],
            &game.boardState[2][1]
        }
    },
    {
        0,
        {{1,1},{2,2},{3,3}},
        {
            //bottomRow
            &game.boardState[0][2],
            &game.boardState[1][2],
            &game.boardState[2][2]
        }
    },
    {
        0,
        {{1,1},{2,2},{3,3}},
        {
            //leftColumn
            &game.boardState[0][0],
            &game.boardState[0][1],
            &game.boardState[0][2]
        }
    },
    {
        0,
        {{1,1},{2,2},{3,3}},
        {
            //middleColumn
            &game.boardState[1][0],
            &game.boardState[1][1],
            &game.boardState[1][2]
        }
    },
     {
         0,
         {{1,1},{2,2},{3,3}},
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