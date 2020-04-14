#ifndef BINARYFILE
#define BINARYFILE
#include <stdbool.h>
#include "sharedDataStructures.h"

State state = { noSelection };

//menu.c
void menuSelection();
void executeMenuSelection();
void mainMenu();


//createFile.c
bool fileExists(char* fileName);
void newFile(char* fileName);
void createFile(char* fileName);
void createFileUserInput();

//deleteFile.c


//readFile.c
void listEntries(FILE* file);
void readFromFile();

#endif