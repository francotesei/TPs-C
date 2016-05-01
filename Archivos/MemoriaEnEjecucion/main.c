#include <stdio.h>
#include <stdlib.h>
#include "prot_memoria.h"

int main()
{
    int *valores;

    if(obtenerMemoria(&valores))
        cargaVector(&valores);
    else
        printf("Comprate una PC papa");

    return 0;
}
