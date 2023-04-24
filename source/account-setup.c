#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "security.h"
#include "globals.h"

void RegisterUser(){
    char fName[10];
    char lName[15]; 
    char addressSt[15];
    char password[30];
    int addressNo;
    int postCode;
    int dDOB;
    int mDOB;
    int yDOB;

    printf("First name: ");
    scanf(" %s", fName);

    printf("Last name: ");
    scanf(" %s", lName);

    printf("Date of birth (dd/mm/yyyy): ");
    scanf(" %d%*/%d%*/%d", &dDOB, &mDOB, &yDOB);

    printf("Residential address No.: ");
    scanf(" %d", &addressNo);

    printf("Residential address street name: ");
    scanf(" %s", addressSt);

    printf("Postcode/ZIP code: ");
    scanf(" %d", &postCode);

    printf("Password: ");
    scanf(" %s", password);

    //Changes the last character to an underscore and then concatenates the first name with the last name to create a filename
    size_t lNameLen = strlen(lName);
    lName[lNameLen] = '_';
    lName[lNameLen+1] = '\0';
    strcat(lName, fName);

    char *filename = lName;
    
    chdir("W:/CPrograms/Banking System/Source Code/customers");
    FILE *customerInfo = fopen(filename, "w");

    //resets the names back to their original form for writing to the file
    sscanf(lName, "%[^_]_ %s", lName, fName);

    char dDOBConverted = ConvertIntToChar(dDOB);
    char mDOBConverted = ConvertIntToChar(mDOB);
    char yDOBConverted = ConvertIntToChar(yDOB);
    char addressNoConverted = ConvertIntToChar(addressNo);
    char postCodeConverted = ConvertIntToChar(postCode);

    

    EncryptData(password);
    EncryptData(fName);
    EncryptData(lName);
    EncryptData(&dDOBConverted);
    EncryptData(&mDOBConverted);
    EncryptData(&yDOBConverted);
    EncryptData(&addressNoConverted);
    EncryptData(addressSt);
    EncryptData(&postCodeConverted);

    

    
    






    
     

}
void CreateUserFiles();
