#include "my.h"
#include <stdlib.h>
#include <stdio.h>

int numberOfZeros(int n)
{
    int i = 0;
    double tmp = (double)n;
    while(tmp > 1)
    {
        tmp /= 10.0;
        i++;
    }
    return i;
}

char* fromMinutesToHeures(int minutes)
{
    int retHeures,retMinutes;
    retHeures = minutes/60;
    retMinutes = minutes%60;
    
    int totalSize = numberOfZeros(retHeures)+numberOfZeros(retMinutes)+2;
    
    char* str = (char*)malloc(sizeof(char)*totalSize);
    for(int i = 0; i < totalSize; i++)
        str[i] = '\0';
    
    sprintf(str, "%d", retHeures);
    sprintf(&(str[getStrLength(str)]), "%s", "h");
    
    if(retMinutes < 10)
        sprintf(&(str[getStrLength(str)]), "%d", 0);
    
    sprintf(&(str[getStrLength(str)]), "%d", retMinutes);
    
    return str;
}