#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sharedData.h"


void writeToFile(Student student){
    getUri();
    FILE* file = fopen(fileUri,"ab");
    if(file != NULL){
        char* studentStr = studentToString(student);
        fwrite(studentStr, sizeof(char), strlen(studentStr), file);
        printf("Student Written to: %s\n", fileUri);
        fclose(file);
    }
    else 
        printf("Error Opening File: %s\n", fileUri);
}