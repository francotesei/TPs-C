#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"




int main()
{
    t_arbol arbol;

    arbolAVL(&arbol);
    arbolCompleto(&arbol);


    printf("\n");
    return 0;
}
