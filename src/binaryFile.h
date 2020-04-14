#include <stdbool.h>
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


#ifndef BINARYFILE
#define BINARYFILE
#include "sharedDataStructures.h"

State state = { noSelection, "t.bin" };

//menu.c
void menuSelection();
void executeMenuSelection();
void mainMenu();
void pauseMenu();


//createFile.c
bool fileExists(char** fileName);
void newFile(char** fileName);
void createFile(char* fileName);
void createFileUserInput();

//readFile.c
void readFromFile();

#endif