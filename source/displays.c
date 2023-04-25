#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "globals.h"
#include "account-setup.h"
#include "security.h"

void LoginScreen(){
    int userchoice;
    int clientNum;
    int looper = 0;
    printf("Welcome to Mock Bank, are you a returning customer (1) or a new one (0)? ");
    scanf(" %d", &userchoice);
    if (!userchoice){
        RegisterUser();
    }
    printf("What is your Client Number?: ");
    scanf(" %d", &clientNum);

    int length = snprintf(NULL, 0, "%d", clientNum);
    char strClientNum[length + 1];
    snprintf(strClientNum, length + 1, "%d", clientNum);

    strcat(strClientNum, FILE_EXT);

    char *filename = strClientNum;

    chdir(CUSTOMER_STORAGE);

    FILE *customerFile = fopen(filename, "r");

    if(customerFile == NULL){
        printf("there was an issue accessing your file, exiting program.");
    }

    while(!looper)
    {
        looper = CheckCredentials(customerFile);
    }

}
void GreetUser(FILE *customerFile);
int MainMenu(FILE *customerFile);
int DisplayBalance(); 
int DisplayTXHistory();