#ifndef BINARYFILE
#define BINARYFILE
#include <stdbool.h>
#include "sharedData.h"



//menu.c
void menuSelection();
void executeMenuSelection();
void mainMenu();


//createFile.c
bool fileExists(char* fileName);
void newFile(char* fileName);
void createFile(char* fileName);
void createFileUserInput();

//deleteEntry.c
void deleteEntry(int index);

//readEntries.c
void listEntries(FILE* file);
void readFromFile();

#endif