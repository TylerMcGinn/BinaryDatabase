#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "binaryFile.h"
#include "sharedData.h"



// void listQueryEntry(int targetIndex){
//     FILE* file = fopen(fileUri, "rb");
//     if(file != NULL){
//         Student student;
//         int index = 0;
//         while(fscanf(file, "{%[^,],%[^,],%[^,],%[^,],%[^}]}", &student.id, &student.name, &student.email, &student.course, &student.grade) != EOF){
//             if(index == targetIndex){
//                 printf("index: %d {\n",index);
//                 printf("  Student Id: %s\n", student.id);
//                 printf("  Name: %s\n",student.name);
//                 printf("  Email: %s\n",student.email);
//                 printf("  Course: %s\n",student.course);
//                 printf("  Grade: %s\n}\n\n",student.grade);
//             }
//             index++;
//         }
//     }
//     fclose(file);
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

    // newEntry(student1);
    // newEntry(student2);
    // newEntry(student1);
    // newEntry(student2);
    
    // while(state.menuCommand != exitMenu){
    //     mainMenu();
    // }
   
    queryEntries();
    printf("end\n");
    PAUSE;
    return 0;
}