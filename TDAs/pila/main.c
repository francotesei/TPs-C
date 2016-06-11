#include <stdio.h>
#include <stdlib.h>
#include "pilaDinamica.h"
#include <string.h>
int main(){

    t_info info;
    t_pila pila;

    crearPila(&pila);

    info.dni = 1111;

    strcpy(info.nom,"carlos");
    apilar(&pila,&info);

    if(!pilaVacia(&pila))
        printf("la pila no esta vacia\n");

    return 0;
}
