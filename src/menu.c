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
    FLUSH;
}


void mainMenu(){
    CLEAR;
    char* title = "MAIN MENU";
    char* new = "1: Create New File";
    char* read = "2: Show All Entries";
    char* query = "3: Query Entries";
    char* newStudent = "4: New Entry";
    char* update = "5: Update Entry";
    char* delete = "6: Delete Entry";
    char* quit = "7: Exit";
    char* userPrompt = "Please Enter An Option: ";
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s", title, new, read, query, newStudent,update, delete, quit, userPrompt);
    menuSelection();
    executeMenuSelection();
}


void executeMenuSelection(){
    switch (state.menuCommand)
    {
    case noSelection:
        CLEAR;
        mainMenu();
        break;
    case createNewFile:
        CLEAR;
        createFileUserInput();
        state.menuCommand = noSelection;
        break;
    case listAllData:
        CLEAR;
        readFromFile();
        state.menuCommand = noSelection;
        break;
    case queryData:
        CLEAR;
        queryEntries();
        state.menuCommand = noSelection;
        break;
    case newData:
        CLEAR;
        newEntry();
        state.menuCommand = noSelection;
        break;
    case updateData:
        CLEAR;
        updateEntry();
        state.menuCommand = noSelection;
        break; 
    case deleteData:
        CLEAR;
        deleteEntry();
        state.menuCommand = noSelection;
        break;
    case exitMenu:
        state.menuCommand = exitMenu;
        break;
    default:
        state.menuCommand = noSelection;
        printf("Invalid Selection\n");
        break;
    }
}


//shared utility functions
bool getUri(){
    printf("\nEnter Filename:");
    scanf("%s", &state.fileUri);
    FLUSH;
    return validateUri();
}


void getIndex(){
    printf("\nEnter Index To Overwrite:");
    scanf("%d", &state.entryIndex);
    FLUSH;
}


bool validateUri(){
    FILE* file = fopen(state.fileUri, "rb");
    if(file != NULL){
        fclose(file);
        return true;
    }
    else    
        return false;
}


void query(){
    printf("\nEnter Search Parameter: ");
    scanf("%s", &state.userQuery);
    FLUSH;
}


int entryCount(){
    char c;
    FILE* file = fopen(state.fileUri, "rb");
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


Student* copyEntries(){
    int index = 0;
    Student student;
    Student* studentEntries = (Student*)malloc(entryCount() * sizeof(Student));
    FILE* file = fopen(state.fileUri, "rb");
    if(file != NULL){
        while(fscanf(file, "{%[^,],%[^,],%[^,],%[^,],%[^}]}", &student.id, &student.name, &student.email, &student.course, &student.grade) != EOF){
            studentEntries[index] = student;
            index++;
        }
        fclose(file);
        return studentEntries;
    }
}


Student getStudentData(){
    Student newStudent;
    printf("Enter Student Id: ");
    scanf("%s", newStudent.id);
    FLUSH;
    printf("Enter Name: ");
    scanf("%[^\n]", newStudent.name);
    FLUSH;
    printf("Enter Email: ");
    scanf("%s", newStudent.email);
    FLUSH;
    printf("Enter Course: ");
    scanf("%[^\n]", newStudent.course);
    FLUSH;
    printf("Enter Grade: ");
    scanf("%s", newStudent.grade);
    FLUSH;
    CLEAR;
    return newStudent;
}


void listEntries(){
    if(entryCount() > 0){
        FILE* file = fopen(state.fileUri, "rb");
        if(file != NULL){
            Student student;
            int index = 0;
            while(fscanf(file, "{%[^,],%[^,],%[^,],%[^,],%[^}]}", &student.id, &student.name, &student.email, &student.course, &student.grade) != EOF){
                printf("index: %d {\n",index);
                printf("  Student Id: %s\n", student.id);
                printf("  Name: %s\n",student.name);
                printf("  Email: %s\n",student.email);
                printf("  Course: %s\n",student.course);
                printf("  Grade: %s\n}\n\n",student.grade);
                index++;
            }
            fclose(file);
        }
    }
    else 
        printf("No Entries!\n");
}