#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "globals.h"
#include "account-setup.h"
#include "security.h"

int LoginScreen(){
    int userchoice;
    char clientNum[10];
    int looper = 0;
    printf("Welcome to Mock Bank, are you a returning customer (1) or a new one (0)? ");
    scanf(" %d", &userchoice);
    if (!userchoice){
        RegisterUser();
    }
    printf("What is your Client Number?: ");
    scanf(" %s", clientNum);

    char *filename = strcat(clientNum, FILE_EXT);

    chdir(CUSTOMER_STORAGE);

    FILE *customerFile = fopen(filename, "r");

    if(customerFile == NULL){
        printf("there was an issue accessing your file, exiting program.");
        return 1;
    }

    while(!looper)
    {
        looper = CheckCredentials(customerFile);
    }





}
void GreetUser();
int MainMenu();
int DisplayBalance(); 
int DisplayTXHistory();