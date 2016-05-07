#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"
#define CON_SIN 1

int main()
{
    FILE *fp;
    printf("\t\t\t\t\t\tProbando funcion abrir Archivo\n");
    if(!abrirArchivo(&fp,"rb",Archivo,CON_SIN))
    {
        printf("exit");
        exit(1);
    }

    /*
    sigo con la ejecucion
    */
    return 0;
}
