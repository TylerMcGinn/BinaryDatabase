#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "sharedData.h"


void readFromFile(){
    LIST_DIR;
    if(getUri()){
        CLEAR;
        printf("ENTRIES\n\n");
        listEntries();
    }
    else
        printf("Invalid URI: %s\n", state.fileUri);
    PAUSE;
}