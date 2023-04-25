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

}
int CheckCredentials(FILE *customerFile){
    char fName[30];
    char lName[30];
    int dDOB;
    int mDOB;
    int yDOB;
    int addressNo;
    char addressSt[15];
    int postCode;
    char password[30];
    char inputPassword[30];

    fscanf(customerFile, "%s %s %d %d %d %d %s %d %s",  fName, lName, &dDOB, &mDOB, 
   &yDOB, &addressNo , addressSt, &postCode, password);

    printf("What is your password?: ");
    scanf(" %s", inputPassword);

    DecryptData(password);

    size_t size = sizeof(password) / sizeof(password[0]);
    if(!strncmp(password, inputPassword, size))
    {
        return 1;
    }

    return 0;



}