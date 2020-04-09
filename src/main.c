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
    while(1){
        botPlayerMove();
        delay(1000);
    }
   
    system("pause");
    return 0;
}