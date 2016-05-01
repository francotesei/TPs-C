#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "protMenu.h"

char menuOption(const char *msj,const char *option)
{
    char op;
    puts(msj);
    do{
    fflush(stdin);
    scanf("%c",&op);
    }while(!strchr(option,toupper(op)));

    return *strchr(option,toupper(op));
}
