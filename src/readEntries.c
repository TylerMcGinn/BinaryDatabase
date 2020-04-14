#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "sharedDataStructures.h"


void listEntries(FILE* file){
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


void readFromFile(){
    char uri[50];
    LIST_DIR;
    printf("\nEnter File to display:");
    scanf("%s",&uri);
    fflush(stdin);
    FILE* file = fopen(uri, "rb");
    if(file != NULL){
        CLEAR;
        listEntries(file);
        fclose(file); 
        PAUSE;
    }
    else
    {
        printf("Error reading from: %s\n", uri);
        PAUSE;
    }
}