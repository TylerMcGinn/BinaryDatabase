#include <stdlib.h>
#include <stdio.h>
#include "sharedData.h"


int objectLen(){
    char c;
    FILE* file = fopen(fileUri, "rb");
    int objectCount = 0;
    if(file != NULL){
        while((c = fgetc(file)) != EOF)
        {
            if(c == '}')
                objectCount++;
        }
        fclose(file);
    }
    else
        printf("Error reading file: %s\n", fileUri);
    return objectCount;
}


Student* copyFile(FILE* file){
    Student student;
    Student* studentEntries = (Student*)malloc(objectLen() * sizeof(Student));
    int index = 0;
    while(fscanf(file, "{ %d,%[^,],%[^,],%[^,],%d }", &student.id, &student.name, &student.email, &student.course, &student.grade) != EOF){
        studentEntries[index] = student;
        index++;
    }
    fclose(file);
    return studentEntries;
}


void overWriteFile(Student* entries){
    int len = objectLen();
    if(entryIndex > 0 && entryIndex < (len - 1)){
        FILE* file = fopen(fileUri, "wb");
        if(file != NULL){
            for(int i=0; i < len; i++){
                if(i != entryIndex)
                    fprintf(file, "{ %d,%s,%s,%s,%d }", entries[i].id, entries[i].name, entries[i].email, entries[i].course, entries[i].grade);
            }
            fclose(file);
            printf("file overwritten: %s\n", fileUri);
        }
        else{
            printf("overwrite error\n");
        }
    }
    else{
        printf("deletion index out of range\n");
    }
}


void deleteEntry(){
    getUri();
    getIndex();
    FILE* file = fopen(fileUri, "rb");
    if(file != NULL){
        Student* students = copyFile(file);
        overWriteFile(students); 
        PAUSE;
    }
    else{
        printf("error at deleteEntry\n");
        PAUSE;
    }
}