#ifndef BINARYFILE
#define BINARYFILE
#include <stdbool.h>
#include "sharedDataStructures.h"

State state = { noSelection, NULL };

//menu.c
void menuSelection();
void executeMenuSelection();
void mainMenu();


//createFile.c
bool fileExists();
void newFile();
void createFile();
void createFileUserInput();


#endif