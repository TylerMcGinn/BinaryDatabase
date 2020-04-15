#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


#ifdef _WIN32
#define PAUSE system("pause")
#define CLEAR system("cls")
#define LIST_DIR system("dir")
#define FLUSH fflush(stdin)
#else
#define PAUSE printf("Press any key to continue...");fget(stdin)
#define CLEAR system("cls")
#define LIST_DIR system("dir")
#define FLUSH fflush(stdin)
#endif


#ifndef SHAREDDATA
#define SHAREDDATA


typedef struct{
    char id[10];
    char name[40];
    char email[40];
    char course[10];
    char grade[4];
}Student;


typedef enum{
    noSelection,
    createNewFile,
    listAllData,
    queryData,
    newData,
    updateData, 
    deleteData,
    exitMenu
}MenuOption;


typedef struct{
    MenuOption menuCommand;
    char fileUri[50];
    char userQuery[50];
    int entryIndex;
}State;


State state;


//clean up later///////////////////
void executeMenuSelection();
void createFileUserInput();
void readFromFile();
bool getUri();
void getIndex();
void query();
bool validateUri();
void deleteEntry();
int entryCount();
Student* copyEntries();
void queryEntries();
void listEntries();


int studentStrLen(Student s);
char* studentToString(Student s);
Student parseStudent(char* student);


Student getStudentData();
void newEntry();
void updateEntry();
//////////////////////////////////


#endif