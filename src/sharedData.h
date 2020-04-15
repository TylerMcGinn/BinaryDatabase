#include <stdlib.h>
#include <stdio.h>


#ifdef _WIN32
#define PAUSE system("pause")
#define CLEAR system("cls")
#define LIST_DIR system("dir")
#else
#define PAUSE printf("Press any key to continue...");fget(stdin)
#define CLEAR system("cls")
#define LIST_DIR system("dir")
#endif


#ifndef SHAREDDATA
#define SHAREDDATA


typedef struct{
    char id[10];
    char name[40];
    char email[40];
    char course[10];
    char grade[3];
}Student;


typedef enum{
    noSelection,
    createNewFile,
    readFile,
    queryFile,
    updateFile, 
    deleteFile,
    exitMenu
}MenuOption;


typedef struct{
    MenuOption menuCommand;
}State;


State state;


char fileUri[50];
int entryIndex;


//clean up later///////////////////
void executeMenuSelection();
void createFileUserInput();
void readFromFile();
void getUri();
void getIndex();
void deleteEntry();
//////////////////////////////////
#endif