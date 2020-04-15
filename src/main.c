#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "binaryFile.h"
#include "sharedData.h"


int main(){
    while(state.menuCommand != exitMenu){
        mainMenu();
    }
    CLEAR;
    printf("GoodBye!\n");
    PAUSE;
    return 0;
}