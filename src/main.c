#include "binaryDatabase.h"


int main(){
    char* message = "hello world, this is a binary file!";
    // char c;
    // FILE* fp;
    // fp = fopen("./data.bin", "wb");
    int count = 0;
    while(*message++ != '\0'){
        count++;
    
    }
    printf("%d\n",count);
    // printf("%d\n",strlen(message));
    system("pause");
    return 0;
}