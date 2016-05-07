#include <stdio.h>
#include <stdlib.h>
#include "protMenu.h"

int main()
{
    char option;
    printf("\t\t\t\t\t Funcion menu\n");
    option = menuOption("Ingrese la opcion requerida\n"
               "A-alta\n"
               "B-baja\n"
               "C-cancelar\n"
               "D-eliminar\n"
               "E-salir\n"
               "Opcion: ","ABCDE");
    printf("\n La opcion es: %c",option);
    return 0;
}
