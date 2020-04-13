#ifndef BINARYFILE
#define BINARYFILE
#include <stdbool.h>
#include "sharedDataStructures.h"

// MenuState menuState = { noSelection };
MenuState menuState = {noSelection};



//menu.c
void menuSelection();
void executeMenuSelection();
void mainMenu();


//createFile.c
bool fileExists(char** fileName);
void newFile(char** fileName);
void createFile(char** fileName);
void createFileUserInput();


#endif