#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SIN_MEMORIA 0
#define TODO_BIEN 1

typedef struct
{
    int dni;
} t_dato;

typedef struct s_nodo
{
    t_dato dato;
    struct s_nodo *ant;
    struct s_nodo *sig;
} t_nodo;

typedef t_nodo* t_lista;

void crearLista (t_lista *);
int insertarEnOrden(t_lista*,t_dato*);
int comparar(t_dato *, t_dato *);
void mostrar(t_lista*);
int eliminarDesordenada(t_lista *,t_dato *);
int eliminarordenada(t_lista *,t_dato *);

int main()
{
    t_lista lista;
    t_dato dat;
    int opc;

    crearLista(&lista);
    do
    {
        printf("inserte una dni: ");
        scanf("%d",&dat.dni);
        if(!insertarEnOrden(&lista,&dat))
            return 0;
        puts("\n desea agregar otro dato? 0 para terminar");
        scanf("%d",&opc);
    }
    while(opc);
    mostrar(&lista);

    puts("\ningrese dni a borrar");
    scanf("%d",&dat.dni);
    if(!eliminar(&lista,&dat))
        puts("\nDato no encontrado");
    mostrar(&lista);
    getch();

    return TODO_BIEN;
}

void crearLista(t_lista *p)
{
    *p=NULL;
}

int insertarEnOrden(t_lista *p,t_dato *d)
{
    t_nodo *ant,*act,*nue;

    act=*p;

    if(act==NULL)
        ant=NULL;
    else
        ant=act->ant;

    while(act && comparar(d,&act->dato)>0)
    {
        ant =act;
        act=act->sig;
    }
    while(ant && comparar (d, &ant->dato)<0)
    {
        act = ant;
        ant = ant->ant;
    }

    nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nue) return SIN_MEMORIA;
    nue->dato= *d;
    nue->sig = act;
    nue->ant = ant;

    if(act)
        act->ant =nue;
    if(ant)
        ant->sig =nue;
    *p=nue;
    return TODO_BIEN;
}

int comparar(t_dato *a, t_dato *b)
{
    return a->dni - b->dni;
}

void mostrar(t_lista *p)
{
    if(!*p)
        return;
    while((*p)->ant)
        p=&(*p)->ant;
    while(*p)
    {
        printf("%d    ",(*p)->dato);
        p=&(*p)->sig;
    }
}

int eliminarDesordenada(t_lista *p,t_dato *d)
{
    t_nodo *aux,*ant,*sig;
    if(!*p)
        return 0;
    while((*p)->ant)
        p=&(*p)->ant;
    while((*p)->sig && comparar(d,&(*p)->dato)!=0)
        p=&(*p)->sig;
    if(comparar(d,&(*p)->dato)==0)
    {
        aux=(*p);
        ant=aux->ant;
        sig=aux->sig;

        if(ant && sig)
        {
            ant->sig=sig;
            sig->ant=ant;
        }
        else if(ant)
        {
            ant->sig=NULL;
        }
        else if(sig)
            sig->ant=NULL;
        else
        {
            *p=NULL;
        }

        free(aux);
        return 1;
    }

    return 0;
}
int eliminarOrdenada (t_lista*p,t_dato*d)
{
    t_nodo *act;
    t_nodo *ant;
    t_nodo *aux;

    act=*p;
    if(act!=NULL)
        ant=act->ant;
    else
        ant=NULL;
    while(act&&comparar(d,&act->dato)>0)
    {
        ant=act;
        act=act->sig;
    }
    while(ant&&comparar(d,&ant->dato)<0)
    {
        act=ant;
        ant=ant->ant;
    }
    if(act&&comparar(d,&act->dato)==0)
    {
        ant=act;
    }
    if(ant&&comparar(d,&ant->dato)==0)
    {
        aux=ant;
        if(ant)
            ant->ant->sig=ant->sig;
        if(act)
            ant->sig->ant=ant->ant;
        *d=ant->dato;
        free(ant);
        return TODO_BIEN;
    }
    return 0;
}
