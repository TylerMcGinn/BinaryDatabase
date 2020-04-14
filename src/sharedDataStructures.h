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
    int id;
    char name[40];
    char email[40];
    char course[10];
    int grade;
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


#endif