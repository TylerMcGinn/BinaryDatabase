#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "sharedData.h"

//clean this up later//////////////////////
void executeMenuSelection();
void createFileUserInput();
void readFromFile();
////////////////////////////////////////////


void menuSelection(){
    MenuOption selectedOption;
    scanf("%d", &selectedOption);
    state.menuCommand = selectedOption;
    fflush(stdin);
}


void mainMenu(){
    CLEAR;
    char* title = "MAIN MENU";
    char* new = "1: Create New File";
    char* read = "2: Show All Entries";
    char* query = "3: Query Entries";
    char* update = "4: New Entry";
    char* delete = "5: Delete Entry";
    char* quit = "6: Exit";
    char* userPrompt = "Please Enter An Option: ";
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s", title, new, read, query, update, delete, quit, userPrompt);
    menuSelection();
    executeMenuSelection();
}


void executeMenuSelection(){
    switch (state.menuCommand)
    {
    case noSelection:
        mainMenu();
        break;
    case createNewFile:
        CLEAR;
        createFileUserInput();
        state.menuCommand = noSelection;
        break;
    // case noSe:
    //     return;
    //     break;
    // case noSelection:
    //     return;
    //     break;
    case readFile:
        CLEAR;
        readFromFile();
        state.menuCommand = noSelection;
        break;
    // queryFile,
    // updateFile, 
    case deleteFile:
        CLEAR;
        deleteEntry();
        state.menuCommand = noSelection;
        break;
    case exitMenu:
        state.menuCommand = exitMenu;
        break;
    default:
        state.menuCommand = noSelection;
        printf("invalid Selection\n");
        break;
    }
}


bool getUri(){
    printf("\nEnter filename:");
    scanf("%s", &fileUri);
    fflush(stdin);
    return validateUri();
}


void getIndex(){
    printf("\nEnter index:");
    scanf("%d", &entryIndex);
    fflush(stdin);
}


bool validateUri(){
    FILE* file = fopen(fileUri, "rb");
    if(file != NULL){
        fclose(file);
        return true;
    }
    else    
        return false;
}


void query(){
    printf("\nEnter Search Parameter: ");
    scanf("%s", &userQuery);
    fflush(stdin);
}


int entriesLen(){
    char c;
    FILE* file = fopen(fileUri, "rb");
    int objectCount = 0;
    if(file != NULL){
        while((c = fgetc(file)) != EOF)
        {
            if(c == '}')
                objectCount++;
        }
        fclose(file);
    }
    return objectCount;
}


Student* copyFile(){
    Student student;
    Student* studentEntries = (Student*)malloc(entriesLen() * sizeof(Student));
    int index = 0;
    FILE* file = fopen(fileUri, "rb");
    if(file != NULL){
        while(fscanf(file, "{%[^,],%[^,],%[^,],%[^,],%[^}]}", &student.id, &student.name, &student.email, &student.course, &student.grade) != EOF){
            studentEntries[index] = student;
            index++;
        }
        fclose(file);
        return studentEntries;
    }
}