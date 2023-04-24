#include <stdio.h>
#include <unistd.h>
#include "security.h"
#include "account-setup.h"
#include "globals.h"
#include <stdlib.h>

int main(){

   RegisterUser();
   char *filename = "W:/CPrograms/Banking System/Source Code/customers/Coulson_Aaron.txt";

   FILE *customerFile = fopen(filename, "r");

   char fName[15];
    char lName[15]; 
    char addressSt[15];
    char password[30];
    int addressNo;
    int postCode;
    int dDOB;
    int mDOB;
    int yDOB;

   fscanf(customerFile, "%s %s %c%c%c %c %s %c %s", fName, lName, &dDOB, &mDOB, 
   &yDOB, &addressNo , addressSt, &postCode, password);
   
   DecryptData(fName);
   DecryptData(lName);
   DecryptData(addressSt);
   DecryptData(password);

   DecryptInt(&dDOB);
   DecryptInt(&mDOB);
   DecryptInt(&yDOB);
   DecryptInt(&addressNo);
   DecryptInt(&postCode);


  

   printf("%s\n%s\n%s\n%d/%d/%d\n%d\n%d\n %s", fName, lName, addressSt, dDOB, mDOB, yDOB, addressNo, postCode, password);

   free(&dDOB);
    free(&mDOB);
    free(&yDOB);
    free(&addressNo);
    free(&postCode);
    fclose(customerFile);
    

   
}