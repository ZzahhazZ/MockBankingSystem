#include "globals.h"



char ConvertIntToChar(int toBeConverted){
    char converted = toBeConverted + '0';
    return converted;
}

int ConvertCharToInt(char toBeConverted){
    int converted = toBeConverted - '0';
    return converted;
}