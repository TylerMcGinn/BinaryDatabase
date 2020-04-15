#ifndef BINARYFILE
#define BINARYFILE
#include <stdbool.h>
#include "sharedData.h"

State state = { noSelection };

//studentParser.c
int studentStrLen(Student s);
char* studentToString(Student s);
Student parseStudent(char* student);

//menu.c
void menuSelection();
void executeMenuSelection();
void mainMenu();
bool getUri();
void getIndex();
bool validateUri();

//createFile.c
bool fileExists(char* fileName);
void newFile(char* fileName);
void createFile(char* fileName);
void createFileUserInput();

//deleteEntry.c
int objectLen();
Student* copyFile();
void deleteEntry();
void overWriteFile(Student* entries);

//readEntries.c
void listEntries();
void readFromFile();

//updateEntry.c
void writeToFile(Student student);

#endif