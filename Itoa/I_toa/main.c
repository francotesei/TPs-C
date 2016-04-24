#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main()
{
    int n,base;
    char vec[31];
    printf("\t\t\tFuncion i_toa\n");

    printf("Ingrese entero a transformar y base : ");
    scanf("%d",&n);
    fflush(stdin);
    printf("\n");
    scanf("%d",&base);
    puts(i_toa(n,vec,base));

    return 0;
}
