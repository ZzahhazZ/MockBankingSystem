#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void EncryptData(char *data){
    int i;
    size_t length = strlen(data);
    for (i = 0; i < length; i++){
        data[i] += 4;
    }
}

void EncryptInt(int *data){

    *data += 64;
    data = (int*) malloc(sizeof(int));
}



void DecryptData(char *data){
     int i;
    size_t length = strlen(data);
    for (i = 0; i < length; i++){
        data[i] -= 4;
    }
}


void DecryptInt(int *data){
    *data -= 64;
    data = (int*) malloc(sizeof(int));
}
int CheckCredentials();