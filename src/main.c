#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "binaryFile.h"
#include "sharedDataStructures.h"


// void writeFile(){
//     // char *c;

//     Student student;
//     printf("id: ");
//     scanf("%d", &student.id);
//     fflush(stdin);
//     printf("name: ");
//     scanf("%s", &student.name);
//     fflush(stdin);
//     FILE* file = fopen("t.bin", "wb");
//     if(file != NULL){
//         // fwrite(student, sizeof student, 1,file);
//         // fwrite(student.name, sizeof(char)*strlen(student.name), 1, file);
//         char* str = tostring(10);
        
//         // fwrite(student, sizeof(data), strlen(data), file);
//         // // while(*data != '\0'){
//         // //     fwri
//         // //     *data++;
//         // // }
//         fclose(file);
//         printf("data writen to: %s\n", "t.bin");
//     }
//     else{
//         printf("error writing file\n");
//     }
// }




void writeToFile(Student student){
    FILE* file = fopen("t.bin","ab");
    if(file != NULL){
        fprintf(file,"{ %d,%s,%s,%s,%d }", student.id, student.name, student.email,student.course, student.grade);
        fclose(file);
        printf("success\n");
    }
    else{
        printf("error\n");
    }
}


int main(){
    Student student1 = {
        12,
        "tyler mcginn",
        "systematyler@gmail.com",
        "COMP 2131",
        85
    };

    Student student2 = {
        113,
        "max tougas",
        "max@gmail.com",
        "GIS 2131",
        70
    };

    while(state.menuCommand != exitMenu){
        mainMenu();
    }
    printf("end\n");
    PAUSE;
    return 0;
}