#include <stdio.h>
#include <unistd.h>
#include "account-setup.h"
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

   fscanf(customerFile, "%s %s %d %d %d %d %s %d %s", fName, lName, &dDOB, &mDOB, 
   &yDOB, &addressNo , addressSt, &postCode, password);
   

   printf("%s\n%s\n%s\n%s\n", fName, lName, addressSt, postCode, password);
   printf("%d %d %d\n%d\n", dDOB, mDOB, yDOB)

   fclose(customerFile);

   
}