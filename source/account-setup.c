#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "security.h"
#include "globals.h"

void RegisterUser(){
    char fName[30];
    char lName[30]; 
    char addressSt[30];
    char password[30];
    int addressNo;
    int postCode;
    int dDOB;
    int mDOB;
    int yDOB;
    char *format = ".txt";

    printf("First name: ");
    scanf(" %s", fName);

    printf("Last name: ");
    scanf(" %s", lName);

    printf("Date of birth (dd/mm/yy): ");
    scanf(" %d%*/%d%*/%d", &dDOB, &mDOB, &yDOB);

    printf("Residential address No.: ");
    scanf(" %d", &addressNo);

    printf("Residential address street name: ");
    scanf(" %s", addressSt);

    printf("Postcode/ZIP code: ");
    scanf(" %d", &postCode);

    printf("Password: ");
    scanf(" %s", password);

    /*Changes the last character to an underscore and then concatenates 
    the first name with the last name and then also with the format type
    to create a filename in the format LastName_FirstName.format*/
    size_t lNameLen = strlen(lName);
    lName[lNameLen] = '_';
    lName[lNameLen+1] = '\0';
    
    strcat(lName, fName);
    strcat(lName, format);
    
    char *filename = lName;
    
    //changes directory to where the customer files are saved to
    chdir("W:/CPrograms/Banking System/Source Code/customers");
    FILE *customerInfo = fopen(filename, "w");

    //resets the names back to their original form for encryption
    lName[15] = '\0';
    sscanf(lName, "%[^_]_ %s", lName, fName);

    

    EncryptInt(&dDOB);
    EncryptInt(&mDOB);
    EncryptInt(&yDOB);
    EncryptInt(&addressNo);
    EncryptInt(&postCode);

    EncryptData(fName);
    EncryptData(lName);
    EncryptData(addressSt);
    EncryptData(password);

    fprintf(customerInfo, "%s %s %d %d %d %d %s %d %s", fName, lName, dDOB, mDOB, 
   yDOB, addressNo , addressSt, postCode, password);

    fclose(customerInfo);

    printf("Account Created, welcome to MockBank!");

}
void CreateUserFiles();
