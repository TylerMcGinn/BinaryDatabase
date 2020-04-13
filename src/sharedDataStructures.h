#ifndef SHAREDDATA
#define SHAREDDATA


typedef struct{
    int id;
    char* name;
    char* email;
    char* course;
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
    MenuOption selected;
}MenuState;


MenuState menuState;


#endif