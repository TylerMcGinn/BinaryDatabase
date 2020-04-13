#ifndef BINARYFILE
#define BINARYFILE
#include <stdbool.h>
#include "sharedDataStructures.h"

MenuState menuState = { noSelection };


//menu.c
MenuOption menuSelection();
void mainMenu();


//createFile.c
bool fileExists(char* fileName);
void newFile(char* fileName);
void createFile(char* fileName);



#endif