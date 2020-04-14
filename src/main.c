#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
// #include "binaryFile.h"
#include "sharedDataStructures.h"


void writeFile(){
    // char *c;

    Student student;
    printf("id: ");
    scanf("%d", &student.id);
    fflush(stdin);
    printf("name: ");
    scanf("%s", &student.name);
    fflush(stdin);
    FILE* file = fopen("t.bin", "wb");
    if(file != NULL){
        // fwrite(student, sizeof student, 1,file);
        // fwrite(student.name, sizeof(char)*strlen(student.name), 1, file);
        char* str = tostring(10);
        
        // fwrite(student, sizeof(data), strlen(data), file);
        // // while(*data != '\0'){
        // //     fwri
        // //     *data++;
        // // }
        fclose(file);
        printf("data writen to: %s\n", "t.bin");
    }
    else{
        printf("error writing file\n");
    }
}


void read(){
    FILE* file = fopen("t.bin", "rb");
    if(file != NULL){
        Student student;
        fscanf(file, "%d%s", &student.id, &student.name);
        fclose(file);
        printf("%d\n",student.id);
    }
    else
    {
        printf("error\n");
    }
    
}
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




int main(){
    writeFile();
    read();
    printf("end\n");
    system("pause");
    return 0;
}