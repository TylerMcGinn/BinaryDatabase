#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "sharedDataStructures.h"

//clean this up later//////////////////////
void executeMenuSelection();
void createFileUserInput();
////////////////////////////////////////////


void menuSelection(){
    MenuOption selectedOption;
    scanf("%d", &selectedOption);
    menuState.selected = selectedOption;
    fflush(stdin);
}


void mainMenu(){
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
    switch (menuState.selected)
    {
    case noSelection:
        mainMenu();
        break;
    case createNewFile:
        createFileUserInput();
        menuState.selected = noSelection;
        break;
    // case noSe:
    //     return;
    //     break;
    // case noSelection:
    //     return;
    //     break;
    // readFile,
    // queryFile,
    // updateFile, 
    // deleteFile,
    // exitMenu
    default:
        menuState.selected = noSelection;
        printf("invalid Selection\n");
        break;
    }
}



