#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sharedData.h"



void overWriteFile(Student* entries){
    int len = entriesLen();
    if(entryIndex >= 0 && entryIndex <= (len - 1)){
        FILE* file = fopen(fileUri, "wb");
        if(file != NULL){
            for(int i=0; i < len; i++){
                if(i != entryIndex){
                    char* studentStr = studentToString(entries[i]);
                    fwrite(studentStr, sizeof(char), strlen(studentStr), file);
                }
            }
            fclose(file);
            printf("file overwritten: %s\n", fileUri);
        }
    }
    else
        printf("deletion index out of range\n");
}


void deleteEntry(){
    if(getUri()){
        getIndex();
        Student* students = copyFile();
        overWriteFile(students); 
    }
    else
        printf("Invalid URI: %s\n", fileUri);
    PAUSE;
}