#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>


bool fileExists(char* fileName){
    FILE* file = fopen(fileName, "rb");
    bool exists = file != NULL ? true : false;
    if(exists)
        fclose(file);
    return exists;
}


void newFile(char* fileName){
    FILE* file = fopen(fileName, "wb");
    fclose(file);
}


void createFile(char* fileName){
    if(fileExists(fileName)){
        char yesNo;
        printf("%s already exists. All data will be overwritten do you wish to procceed? Y/N:", fileName);
        scanf("%c", &yesNo);
        if(toupper(yesNo) == 'Y')
            newFile(fileName);
    }
    else{
        newFile(fileName);
    }
}



