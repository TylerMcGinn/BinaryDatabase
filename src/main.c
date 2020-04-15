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
    parseStudent(studentToString(student1));
    // studentToString(student1);
    printf("end\n");
    PAUSE;
    return 0;
}