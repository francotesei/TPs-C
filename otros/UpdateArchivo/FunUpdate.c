#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ProUpdate.h"

int getIntoPerson(person *reg)
{
       if(menuOption("Desea ingresar datos?","Y"))
        {
            fflush(stdin);
            scanf("%ld %s %s %c %d/%d/%d %.2f", reg->dni,reg->nom,reg->ape,reg->sex,reg->day,reg->month,reg->year,reg->salary);

            return 1;
        }

       return 0;
}

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
