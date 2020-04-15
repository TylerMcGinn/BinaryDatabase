#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "sharedData.h"


void queryEntries(){
    bool matchFound = false;
    LIST_DIR;
    if(getUri()){
        CLEAR;
        listEntries();
        printf("QUERY ENTRIES\n");
        query();
        CLEAR;
        printf("MATCHES\n\n");
        Student* students = copyEntries();
        for (int i = 0; i < entryCount(); i++){
            char* sStr = studentToString(students[i]);
            char* match = strstr(sStr, state.userQuery);
            if(match != NULL){
                matchFound = true;
                printf("index: %d {\n", i);
                printf("  Student Id: %s\n", students[i].id);
                printf("  Name: %s\n",students[i].name);
                printf("  Email: %s\n",students[i].email);
                printf("  Course: %s\n",students[i].course);
                printf("  Grade: %s\n}\n\n",students[i].grade);
            }
        }
        if(!matchFound) 
            printf("No Matches Found.\n");
    }
    else 
        printf("Invalid URI: %s\n", state.fileUri);
    PAUSE;
}