#ifndef SHAREDDATA
#define SHAREDDATA


typedef struct{
    int id;
    char name[40];
    char email[40];
    char course[10];
    int grade;
}Student;


typedef enum{
    noSelection,
    createNewFile,
    readFile,
    queryFile,
    updateFile, 
    deleteFile,
    exitMenu
}MenuOption;


typedef struct{
    MenuOption menuCommand;
    char* fileUri;
}State;


State state;


#endif