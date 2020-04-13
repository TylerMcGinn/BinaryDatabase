#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>


bool fileExists(char** fileName){
    FILE* file;
    file = fopen(fileName, "rb");
    bool exists = (file != NULL) ? true : false;
    if(exists)
        fclose(file);
    return exists;
}


void newFile(char** fileName){
    FILE* file1 = fopen(fileName, "wb");
    if(file1 != NULL){
        fclose(file1);
        printf("created successfully: %s\n", fileName);
        system("pause");
    }
    else{
        printf("An Error occured while trying to create: %s\n", fileName);
        system("pause");
    }
}


void createFile(char** fileName){
    if(fileExists(fileName)){
        char yesNo;
        printf("%s already exists. All data will be overwritten do you wish to procceed? Y/N:", fileName);
        scanf("%c", &yesNo);
        fflush(stdin);
        if(toupper(yesNo) == 'Y')
            newFile(fileName);
    }
    else{
        newFile(fileName);
    }
}

void createFileUserInput(){
    char* fileUri;
    system("cls");
    printf("Enter filepath/filename:");
    scanf("%s", &fileUri);
    fflush(stdin);
    createFile(&fileUri);
    system("cls");
}

