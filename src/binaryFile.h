#ifndef BINARYFILE
#define BINARYFILE
#include <stdbool.h>
#include "sharedDataStructures.h"

State state = { noSelection, "t.bin" };

//menu.c
void menuSelection();
void executeMenuSelection();
void mainMenu();
void pauseMenu();


//listDirectory.c
void listDir();

//createFile.c
bool fileExists(char** fileName);
void newFile(char** fileName);
void createFile(char* fileName);
void createFileUserInput();

//readFile.c
void readFromFile();


#endif