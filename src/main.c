#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "binaryFile.h"

int main(){
    while(menuState.selected == noSelection){
        mainMenu();
    }    
    printf("end\n");
    system("pause");
    return 0;
}