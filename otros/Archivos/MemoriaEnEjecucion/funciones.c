#include <stdio.h>
#include "prot_memoria.h"

int obtenerMemoria(int **vec)
{
    printf("Obteniendo memoria.....\n");
    *vec = (int) malloc(sizeof(int)*5);
    if(!*vec)
    {
        fprintf(stderr,"Error - Sin memoria\n");
        return 0;
    }

    return 1;
}

void cargaVector(int **vec)
{
    int i = 0;
    printf("\t\t\t\t\t\t\tIngrese valores al vector\n");

    for(i ;i < sizeof(*vec) ;i ++)
    {
        fflush(stdin);
        scanf("%d",&**vec);
    }
}
