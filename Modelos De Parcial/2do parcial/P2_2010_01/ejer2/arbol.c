#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"

void crearArbol(t_arbol* arbol){

    *arbol =NULL;
}

int altura(const t_arbol* arbol){

    if(*arbol){

    int hi = altura(&(*arbol)->izq),
        hd = altura(&(*arbol)->der);

    return (hi>=hd)? hi+1:hd+1;
    }
    return 0;

}

int arbolCompleto(const t_arbol* arbol){

    return esCompleto(arbol,altura(arbol));

}

int esCompleto(const t_arbol* arbol,int h){

    if(*arbol)
        return esCompleto(&(*arbol)->izq,h-1) && esCompleto(&(*arbol)->der,h-1);
    return h == 0;

}
int arbolAVL(const t_arbol* arbol){

    return esAVL(arbol,altura(arbol));

}

int esAVL(const t_arbol* arbol,int h){

    if(*arbol)
        return esAVL(&(*arbol)->izq,h-1) && esAVL(&(*arbol)->der,h-1);
    return h <= 1;

}

