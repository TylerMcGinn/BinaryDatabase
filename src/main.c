#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// #include "binaryFile.h"


void writeFile(){
    // char *c;
    char* data = "hello tyler";
    FILE* file = fopen("t.bin", "ab");
    if(file != NULL){

        fwrite(data, sizeof(data), strlen(data), file);
        // while(*data != '\0'){
        //     fwri
        //     *data++;
        // }
        fclose(file);
        printf("data writen to: %s\n", "t.bin");
    }
    else{
        printf("error writing file\n");
    }
}

int dataSize(){
    char c;
    int count = 0;
    FILE* file = fopen("t.bin", "rb");
    if(file != NULL){
        while((fgetc(file)) != '\0'){
            // printf("%c\n",c);
            count++;
        }
    }
    else{
        printf("error\n");
    }
    return count;
}

void readFile(){
    char* str = (char*)malloc(sizeof(char) * (dataSize()+2));
    char c;
    // str = "hello tyler";
    int count = 0;
    FILE* file = fopen("t.bin", "rb");
    // while((c = fgetc(file)) != '\0'){
    //     str = c;
    //     str++;
    //     count++;
    //     // *str++;
    //     // printf("%c\n",c);
    // }
    // str[11] = '\0';
    // *str = fgetc()
    while((*str++ = fgetc(file)) != '\0');
    *str++ = '\0';
    printf("%s\n", str);

}




int main(){
    // writeFile();
    // while(state.menuCommand != exitMenu){
    //     mainMenu();
        
    // }   
    // printf("%d\n",dataSize()); 
    readFile();
    printf("end\n");
    system("pause");
    return 0;
}