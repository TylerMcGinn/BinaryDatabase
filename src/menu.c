#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "sharedDataStructures.h"




MenuOption menuSelection(){
    MenuOption selectedOption;
    scanf("%d", &selectedOption);
    menuState.selected = selectedOption;
    return selectedOption;
}

void mainMenu(){
    char* title = "MAIN MENU";
    char* new = "1: Create New File";
    char* read = "2: Show All Entries";
    char* query = "3: Query Entries";
    char* update = "4: New Entry";
    char* delete = "5: Delete Entry";
    char* quit = "6: Exit";
    char* userPrompt = "Please Enter An Option...";
    printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n", title, new, read, query, update, delete, quit, userPrompt);
    menuSelection();
}

