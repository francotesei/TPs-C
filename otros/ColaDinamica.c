#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int info;
}t_info;
typedef struct s_nodo
{
    t_info info;
    struct s_nodo *sig;
}t_nodo;
typedef struct
{
    t_nodo *pri,*ult;
}t_cola;
void crearCola(t_cola *cola)
{
    cola->pri==NULL;
    cola->ult==NULL;

}
int colaVacia(const t_cola *cola)
{
    return cola->pri==NULL;
}
int colaLlena(const t_cola *cola)
{
    void *aux=malloc(sizeof(t_nodo));

    if(!(aux))
        return 1;
    free(aux);
    return 0;
}
int acolar(t_cola *cola,t_info *info)
{
    t_nodo *nue=(t_nodo*)malloc(sizeof(t_nodo));

    if(nue==NULL)
        return 0;
    nue->info=*info;
    nue->sig=NULL;
    if(cola->pri==NULL)
        cola->pri=nue;
    else
        cola->ult->sig=nue;

        cola->ult=nue;
    return 1;

}
int verPrimero(const t_cola *cola,t_info *info)
{
    if(cola->pri==NULL)
        return 0;

        *info=(cola->pri->info);

        return 1;

}
int desAcolar(t_cola *cola,t_info *info)
{
    t_nodo *aux;

    if(cola->pri==NULL)
        return 0;
    *info=cola->pri->info;
	aux=cola->pri;

    if(cola->pri==cola->ult)
        cola->ult=NULL;

    cola->pri=aux->sig;
    free(aux);
    return 1;
}
void vaciarCola(t_cola *cola)
{
    t_nodo *aux;

    while(cola->pri)
    {
        aux=cola->pri;
        cola->pri=aux->sig;
        free(aux);
    }
    cola->ult=NULL;
}

int main()
{
    printf("\n");
    return 0;
}
