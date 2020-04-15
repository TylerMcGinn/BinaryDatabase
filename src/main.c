#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "binaryFile.h"
#include "sharedData.h"






int main(){
    Student student1 = {
        "12",
        "tyler mcginn",
        "systematyler@gmail.com",
        "COMP 2131",
        "85"
    };

    Student student2 = {
        "113",
        "max tougas",
        "max@gmail.com",
        "GIS 2131",
        "70"
    };

    // writeToFile(student1);
    // writeToFile(student2);
    // writeToFile(student1);
    // writeToFile(student2);
    
    while(state.menuCommand != exitMenu){
        mainMenu();
    }
    // getUri();
    // printf("%d\n",objectLen());
    // deleteEntry();
    printf("end\n");
    PAUSE;
    return 0;
}