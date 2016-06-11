#include <stdio.h>
#include <stdlib.h>
#define TAM 10
typedef struct
{
    int dd;
    int mm;
    int aa;
}t_fecha;

typedef struct
{
    long int dni;
    char ape_nom[50];
    t_fecha fec_naci;

}t_info;
typedef struct
{
    t_info pila[TAM];
    int tope;
} t_pila; // el tipo de pila


void crearPila(t_pila *pila)
{
    pila->tope=0;

}
int pilaLlena(const t_pila *pila)
{
    if(pila->tope==TAM)
        return 1;
    return 0;
}

int apilar(t_pila *pila,const t_info *info)
{
    if(pila->tope==TAM)
        return 0;
    pila->pila[pila->tope]=*info;
    pila->tope++;
    return 1;
}
int pilaVacia(t_pila *pila)
{
    pila->tope=0;
    return 1;
}
int verTope(const t_pila *pila,t_info *info)
{
    if(pila->tope==0)
        return 0;


    *info=pila->pila[pila->tope-1];
    return 1;

}

int desapilar(t_pila *pila,t_info *info)
{
    if(pila->tope==0)
        return 0;
    pila->tope--;
    *info=pila->pila[pila->tope];
    return 1;


}




   int main()
{
    t_info info1;
    t_info info2={39486104,"Tesei Franco",{14,03,1996}};
    t_pila pila;

    crearPila(&pila);

    apilar(&pila,&info2);
    verTope(&pila,&info1);
    printf("%ld",info1.dni);








printf("\n");
    return 0;
}
