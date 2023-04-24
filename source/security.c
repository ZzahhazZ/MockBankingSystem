#include <stdio.h>
#include <string.h>

void EncryptData(char *data){
    int i;
    size_t length = strlen(data);
    for (i = 0; i < length; i++){
        data[i] += 4*16;
    }
}
void DecryptData(char *password){
     int i;
    size_t length = strlen(password);
    for (i = 0; i < length; i++){
        password[i] -= 4*16;
    }
}
int CheckCredentials();
