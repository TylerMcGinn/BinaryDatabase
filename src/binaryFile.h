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
void query();
bool validateUri();
int entriesLen();
Student* copyFile();


//createFile.c
bool fileExists(char* fileName);
void newFile(char* fileName);
void createFile(char* fileName);
void createFileUserInput();

//deleteEntry.c
void deleteEntry();
void overWriteFile(Student* entries);

//readEntries.c
void listEntries();
void readFromFile();

//updateEntry.c
void newEntry(Student student);

//queryEntries.c
void queryEntries();

#endif