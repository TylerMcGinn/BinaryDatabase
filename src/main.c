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


// void read(){
//     FILE* file = fopen("t.bin", "rb");
//     if(file != NULL){
//         Student student;
//         fscanf(file, "%d%s", &student.id, &student.name);
//         fclose(file);
//         printf("%d\n",student.id);
//     }
//     else
//     {
//         printf("error\n");
//     }
// }


// int dataSize(){
//     char c;
//     int count = 0;
//     FILE* file = fopen("t.bin", "rb");
//     if(file != NULL){
//         while((fgetc(file)) != '\0'){
//             // printf("%c\n",c);
//             count++;
//         }
//     }
//     else{
//         printf("error\n");
//     }
//     return count;
// }


// void readFile(){
//     int i=0;
//     char c;
//     char* str = (char*)malloc(sizeof(char) * (dataSize()+1));
//     FILE* file = fopen("t.bin", "rb");
//     while((c = fgetc(file)) != '\0'){
//         str[i++] = c;
//     }
//     str[i] = '\0';
//     printf("%s\n", str);
// }


void writeToFile(Student student){
    FILE* file = fopen("t.bin","ab");
    if(file != NULL){
        // , student.email, student.course,student.grade
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
    // createFileUserInput();
    printf("end\n");
    system("pause");
    return 0;
}