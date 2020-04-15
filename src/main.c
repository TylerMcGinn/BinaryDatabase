#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "binaryFile.h"
#include "sharedData.h"



// void writeToFile(Student student){
//     FILE* file = fopen("t.bin","ab");
//     if(file != NULL){
//         fprintf(file,"{ %d,%s,%s,%s,%d }", student.id, student.name, student.email,student.course, student.grade);
//         fclose(file);
//         printf("success\n");
//     }
//     else{
//         printf("error\n");
//     }
// }

int studentStrLen(Student s){
    int sum = 0;
    sum += strlen(s.id);
    sum += strlen(s.name);
    sum += strlen(s.email);
    sum += strlen(s.course);
    sum += strlen(s.grade);
    return sum;
}


char* studentToString(Student s){
    char* studentStr = (char*)malloc(sizeof(char) * (studentStrLen(s) + 7));
    sprintf(studentStr, "{%s,%s,%s,%s,%s}", s.id, s.name, s.email, s.course, s.grade);
    return studentStr;
}


void parseStudentString(char* stude){
    Student s1;
    sscanf(stude, "{%[^,],%[^,],%[^,],%[^,],%[^}]}", &s1.id, &s1.name, &s1.email, &s1.grade, &s1.grade);
    printf("%s\n",s1.id);
}


int main(){
    Student student1 = {
        "12",
        "tyler mcginn",
        "systematyler@gmail.com",
        "COMP 2131",
        "85"
    };

    Student student2 = {
        "113",
        "max tougas",
        "max@gmail.com",
        "GIS 2131",
        "70"
    };

    // while(state.menuCommand != exitMenu){
    //     mainMenu();
    // }
    // writeToFile(student1);
    // writeToFile(student2);
    // writeToFile(student1);
    // writeToFile(student2);
    // deleteEntry();
    // readFromFile();
    // printf("%d\n", studentObjLen(student1));
    parseStudentString(studentToString(student1));
    // studentToString(student1);
    printf("end\n");
    PAUSE;
    return 0;
}