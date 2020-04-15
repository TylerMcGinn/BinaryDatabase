#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sharedData.h"


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


Student parseStudent(char* student){
    Student s;
    sscanf(student, "{%[^,],%[^,],%[^,],%[^,],%[^}]}", &s.id, &s.name, &s.email, &s.grade, &s.grade);
    return s;
}