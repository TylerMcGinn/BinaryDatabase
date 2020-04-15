#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "sharedData.h"


void listEntries(){
    FILE* file = fopen(fileUri, "rb");
    if(file != NULL){
        Student student;
        int index = 0;
        while(fscanf(file, "{%[^,],%[^,],%[^,],%[^,],%[^}]}", &student.id, &student.name, &student.email, &student.course, &student.grade) != EOF){
            printf("index: %d {\n",index);
            printf("  Student Id: %s\n", student.id);
            printf("  Name: %s\n",student.name);
            printf("  Email: %s\n",student.email);
            printf("  Course: %s\n",student.course);
            printf("  Grade: %s\n}\n\n",student.grade);
            index++;
        }
    }
    fclose(file);
}


void readFromFile(){
    LIST_DIR;
    if(getUri()){
        CLEAR;
        listEntries();
    }
    else
        printf("Invalid URI: %s\n", fileUri);
    PAUSE;
}