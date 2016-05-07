#include <stdio.h>
#include <stdlib.h>
#include "prototipos.h"

int main()
{
    char cad[31];

    printf("Ingrese cadena\n");
    gets(cad);
    printf("El tamaño de la mayor palabra es: %d",tamMayorPalabra(cad));
    puts("");
    palMayor(cad,tamMayorPalabra(cad));

    return 0;
}
