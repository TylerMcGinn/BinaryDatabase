#include <stdio.h>


typedef enum{
    none,
    new,
    read,
    query,
    update, 
    delete,
    exit
}menuOption;


struct{
    menuOption selected;
}state = {
    none
};


void mainMenu(){
    char* title = "MAIN MENU";
    char* new = "1: Create New File";
    char* read = "2: Show All Entries";
    char* query = "3: Query Entries";
    char* update = "4: New Entry";
    char* delete = "5: Delete Entry";
    char* exit = "6: Exit";
    char* userPrompt = "Please Enter An Option...";
    printf("%s\n%s\n%s\n%s\n%s\n%s\n", title, new, read, query, update, delete, exit, userPrompt);

}


menuOption menuSelection(){
    menuOption selectedOption;
    scanf("%d", &selectedOption);
    return selectedOption;
}