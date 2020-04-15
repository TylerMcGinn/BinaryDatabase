#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sharedData.h"


void overwriteFile_Update(Student* entries, Student updatedStudent){
    int len = entryCount();
    if(state.entryIndex >= 0 && state.entryIndex <= (len - 1)){
        FILE* file = fopen(state.fileUri, "wb");
        if(file != NULL){
            for(int i=0; i < len; i++){
                if(i == state.entryIndex){
                    char* studentStr = studentToString(updatedStudent);
                    fwrite(studentStr, sizeof(char), strlen(studentStr), file);
                }
                else{
                    char* studentStr = studentToString(entries[i]);
                    fwrite(studentStr, sizeof(char), strlen(studentStr), file);
                }
            }
            fclose(file);
            printf("File Overwritten: %s\n\n", state.fileUri);
        }
    }
    else
        printf("deletion index out of range\n");
}


void updateEntry(){
    LIST_DIR;
    if(getUri()){
        CLEAR;
        listEntries();
        printf("UPDATE ENTRY\n");
        getIndex();
        Student updatedStudent = getStudentData();
        Student* students = copyEntries();
        overwriteFile_Update(students, updatedStudent);
        listEntries();
    }
    else 
        printf("Invalid URI: %s\n", state.fileUri);
    PAUSE;
}


void newEntry(){
    LIST_DIR;
    if(getUri()){
        CLEAR;
        listEntries();
        printf("NEW ENTRY\n");
        Student newStudent = getStudentData();
        FILE* file = fopen(state.fileUri,"ab");
        if(file != NULL){
            char* studentStr = studentToString(newStudent);
            fwrite(studentStr, sizeof(char), strlen(studentStr), file);
            printf("Student Written to: %s\n\n", state.fileUri);
            fclose(file);
        }
        listEntries();
    }
    else 
        printf("Invalid URI: %s\n", state.fileUri);
    PAUSE;
}