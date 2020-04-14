#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "sharedDataStructures.h"

bool fileExists(){
    char* uri = (char*)&state.fileUri;
    FILE* file = fopen(uri, "rb");
    bool exists = (file != NULL) ? true : false;
    if(exists)
        fclose(file);
    return exists;
}


void newFile(){
    char* uri = (char*)&state.fileUri;
    FILE* file1 = fopen(uri, "wb");
    if(file1 != NULL){
        fclose(file1);
        printf("created successfully: %s\n", uri);
        system("pause");
    }
    else{
        printf("An Error occured while trying to create: %s\n", uri);
        system("pause");
    }
}


void createFile(){
    char* uri = (char*)&state.fileUri;
    if(fileExists())
        printf("%s already exists.\n", uri);
    else
        newFile();
}

void createFileUserInput(){
    // system("cls");
    printf("Enter filepath/filename:");
    scanf("%s", &state.fileUri);
    fflush(stdin);
    createFile();
    // system("cls");
}

