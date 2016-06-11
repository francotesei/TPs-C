#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int num;
} t_info; // DEFINO EL TIPO INFO QUE VOY A UTILIZAR

typedef struct s_nodo
{
    t_info info;

    struct s_nodo *sig;
} t_nodo; // defino el nodo

typedef t_nodo * t_pila; // defino mi tipo pila

void crearPila(t_pila *pila)
{
    *pila=NULL;

}
int pilaVacia(const t_pila *pila)
{
    if(*pila==NULL)
        return 1;

    return 0;
}

int pilaLlena(const t_pila *pila)
{
    void *aux=malloc(sizeof(t_nodo));
    free(aux);
    if(!aux)
    return 1;
    return 0;

}
int apilar(t_pila *pila,const t_info *info)
{
    t_nodo *nue=(t_nodo*)malloc(sizeof(t_nodo));

    if(!nue)
    return 0;

    nue->info=*info;
    nue->sig=*pila;
    *pila=nue;

    return 1;
}
int verTope(const t_pila *pila,t_info *info)
{
    if(*pila==NULL)
    return 0;

    *info=(*pila)->info;

    return 1;
}
int desapilar( t_pila *pila,t_info *info)
{
    t_pila aux;

    if(*pila==NULL)
    return 0;

    *info=(*pila)->info;

    aux=*pila;
    *pila=aux->sig;
    free(aux);

    return 1;
}
void vaciarPila(t_pila *pila)
{
    t_nodo *aux;

    while(*pila!=NULL)
    {
        aux=*pila;
        *pila=aux->sig;
        free(aux);
    }
}


int main()
{
    t_info info;
    t_pila pila;




    printf("\n");
    return 0;
}
