#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
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
    int customerNumber;

    printf("First name: ");
    scanf(" %s", fName);

    printf("Last name: ");
    scanf(" %s", lName);

    printf("Date of birth (dd/mm/yy): ");
    scanf(" %d %*/ %d %*/ %d", &dDOB, &mDOB, &yDOB);

    printf("Residential address No.: ");
    scanf(" %d", &addressNo);

    printf("Residential address street name: ");
    scanf(" %s", addressSt);

    printf("Postcode/ZIP code: ");
    scanf(" %d", &postCode);

    printf("Password: ");
    scanf(" %s", password);


    //sets a random value for the customer number then formats to a string to be passed as a file name.
    srand(time(NULL));
    customerNumber = rand();
    int length = snprintf(NULL, 0, "%d", customerNumber);
    char customerNumberStr[length+1];
    snprintf(customerNumberStr, length+1, "%d", customerNumber);
    
    strcat(customerNumberStr, FILE_EXT);
    
    char *filename = customerNumberStr;
    
    //changes directory to where the customer files are saved to
    chdir(CUSTOMER_STORAGE);
    FILE *customerInfo = fopen(filename, "w");

    //resets the names back to their original form for encryption
    customerNumberStr[strlen(customerNumberStr) - 4] = '\0';

    
    EncryptInt(&dDOB);
    EncryptInt(&mDOB);
    EncryptInt(&yDOB);
    EncryptInt(&addressNo);
    EncryptInt(&postCode);

    EncryptData(fName);
    EncryptData(lName);
    EncryptData(addressSt);
    EncryptData(password);

    fprintf(customerInfo, "%s %s %02d %02d %02d %d %s %d %s", fName, lName, dDOB, mDOB, 
   yDOB, addressNo , addressSt, postCode, password);

    fclose(customerInfo);

    printf("Account Created, your customer number for logging in is: %d \nwelcome to MockBank!", customerNumber);

}
void CreateUserFiles();
