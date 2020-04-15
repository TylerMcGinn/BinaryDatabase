#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sharedData.h"


void overwriteFile_Delete(Student* entries){
    
    int len = entryCount();
    if(state.entryIndex >= 0 && state.entryIndex <= (len - 1)){
        FILE* file = fopen(state.fileUri, "wb");
        if(file != NULL){
            for(int i=0; i < len; i++){
                if(i != state.entryIndex){
                    char* studentStr = studentToString(entries[i]);
                    fwrite(studentStr, sizeof(char), strlen(studentStr), file);
                }
            }
            fclose(file);
            printf("File Overwritten: %s\n\n", state.fileUri);
        }
    }
    else
        printf("Deletion Index Out Of Range\n\n");
}


void deleteEntry(){
    LIST_DIR;
    if(getUri()){
        CLEAR;
        listEntries();
        printf("DElETE ENTRY\n");
        getIndex();
        CLEAR;
        Student* students = copyEntries();
        overwriteFile_Delete(students); 
        listEntries();
    }
    else
        printf("Invalid URI: %s\n", state.fileUri);
    PAUSE;
}