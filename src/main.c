#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "binaryDatabase.h"


int main(){
    while(menuSelection() != 6){
        mainMenu();
    }    
    printf("end\n");
    system("pause");
    return 0;
}