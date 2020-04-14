#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "sharedDataStructures.h"

void pauseMenu();


bool fileExists(char* fileName){
    FILE* file = fopen(fileName, "rb");
    bool exists = (file != NULL) ? true : false;
    if(exists)
        fclose(file);
    return exists;
}


void newFile(char* fileName){
    FILE* file1 = fopen(fileName, "wb");
    if(file1 != NULL){
        fclose(file1);
        printf("created successfully: %s\n", fileName);
        // system("pause");
    }
    else{
        printf("An Error occured while trying to create: %s\n", fileName);
        // system("pause");
    }
    // printf("%s\n",fileName);
}


void createFile(char* fileName){
    if(fileExists((char*)fileName))
        printf("%s already exists.\n", fileName);
    else
        newFile((char*)fileName);
}

void createFileUserInput(){
    char fileName[50];
    printf("Enter filepath/filename:");
    scanf("%s", &fileName);
    fflush(stdin);
    createFile((char*)fileName);
    pauseMenu();
    // system("cls");
}

