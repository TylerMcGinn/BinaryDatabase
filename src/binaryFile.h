#ifndef BINARYFILE
#define BINARYFILE
#include <stdbool.h>
#include "sharedData.h"


State state = { noSelection , "", "", -1 };


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
int entryCount();
Student* copyEntries();
Student getStudentData();
void listEntries();


//createFile.c
bool fileExists(char* fileName);
void newFile(char* fileName);
void createFile(char* fileName);
void createFileUserInput();


//deleteEntry.c
void deleteEntry();
void overwriteFile_Delete(Student* entries);


//readEntries.c
void readFromFile();


//updateEntry.c
void overwriteFile_Update(Student* entries, Student updatedStudent);
void updateEntry();
void newEntry();


//queryEntries.c
void queryEntries();


#endif