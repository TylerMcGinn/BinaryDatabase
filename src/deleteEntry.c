#include <stdlib.h>
#include <stdio.h>
#include <string.h>
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
    return objectCount;
}


Student* copyFile(){
    Student student;
    Student* studentEntries = (Student*)malloc(objectLen() * sizeof(Student));
    int index = 0;
    FILE* file = fopen(fileUri, "rb");
    if(file != NULL){
        while(fscanf(file, "{%[^,],%[^,],%[^,],%[^,],%[^}]}", &student.id, &student.name, &student.email, &student.course, &student.grade) != EOF){
            studentEntries[index] = student;
            index++;
        }
        fclose(file);
        printf("File Copied: %s\n", fileUri);
        return studentEntries;
    }
}


void overWriteFile(Student* entries){
    int len = objectLen();
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