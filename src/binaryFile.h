#ifndef BINARYFILE
#define BINARYFILE
#include <stdbool.h>
#include "sharedData.h"

State state = { noSelection };

//studentParser.c
int studentStrLen(Student s);
char* studentToString(Student s);
void parseStudent(char* student);

//menu.c
void menuSelection();
void executeMenuSelection();
void mainMenu();
void getUri();
void getIndex();

//createFile.c
bool fileExists(char* fileName);
void newFile(char* fileName);
void createFile(char* fileName);
void createFileUserInput();

//deleteEntry.c
int objectLen();
Student* copyFile(FILE* file);
void deleteEntry();
void overWriteFile(Student* entries);

//readEntries.c
void listEntries(FILE* file);
void readFromFile();

#endif