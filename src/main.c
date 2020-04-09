#include <stdio.h>
#include <stdlib.h>
#include "ticTacToe.h"

// void scores(int** line, int player){
//     for(int i=0; i<3; i++){
//         printf("#d\n", *line[i]);
//     }
// }

int main(){
    generateSeed();
    // while(1){
    //     botPlayerMove();
    //     delay(1000);
    // }
    for(int i=0; i<8; i++){
        printf("%d,%d,%d\n", *rowsColumnsDiags.all[i][0], *rowsColumnsDiags.all[i][1], *rowsColumnsDiags.all[i][2]);
    }
    system("pause");
    return 0;
}