#include <stdio.h>
#include <stdlib.h>
#include "ticTacToe.h"
#include <ctype.h>

// void getScore(int** line, int player){
//     int sum = 0;
//     for(int i=0; i<3; i++){
//         printf("value:%d\n",*line[i]);
//         if(*line[i] == player)
//             sum++;
//     }
//     printf("sum:%d\n\n",sum);
//     return sum;
// }

int main(){
    generateSeed();
    // while(1){
    //     botPlayerMove();
    //     delay(1000);
    // }
    // for(int i=0; i<8; i++){
    //     printf("%d,%d,%d\n", *rowsColumnsDiags.all[i][0], *rowsColumnsDiags.all[i][1], *rowsColumnsDiags.all[i][2]);
    // }
    for(int i = 0; i<8; i++){
        printf("%d\n", playerScore(rowsColumnsDiags.all[i], game.playerO));
        
    }
    system("pause");
    return 0;
}