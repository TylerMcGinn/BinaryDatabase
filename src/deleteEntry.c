#include <stdlib.h>
#include <stdio.h>
#include "sharedData.h"
char* getUri();

void overWrite(FILE* file){
    Student student;
    int index = 0;
    while(fscanf(file, "{ %d,%[^,],%[^,],%[^,],%d }", &student.id, &student.name, &student.email, &student.course, &student.grade) != EOF){
        printf("index: %d {\n",index);
        printf("  Student Id: %d\n", student.id);
        printf("  Name: %s\n",student.name);
        printf("  Email: %s\n",student.email);
        printf("  Course: %s\n",student.course);
        printf("  Grade: %d\n}\n\n",student.grade);
        index++;
    }
}


void deleteEntry(int index){
    char* uri = getUri();
    FILE* file = fopen(uri, "wb");
    if(file != NULL){

    }
}