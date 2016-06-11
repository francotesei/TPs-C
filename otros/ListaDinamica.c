#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int num;
    char nom[50];
}t_info;

typedef struct s_nodo
{
    t_info infoNodo;
    struct s_nodo *sig;
}t_nodo;

typedef t_nodo *t_lista;
typedef (t_fcmp)(const void *,const void *);

void crearLista(t_lista *lista)
{
    *lista=NULL;
}
int insertarAlFinal(t_lista *lista,const t_info *info)
{


    while(*lista)
        lista=&(*lista)->sig;

        *lista=(t_nodo*)malloc(sizeof(t_nodo));

        if(!*lista)
            return 0;

        (*lista)->infoNodo=*info;
        (*lista)->sig=NULL;
        return 1;
}

int insertarEnOden(t_lista *lista,const t_info *info,const t_fcmp cmp)
{
    t_nodo *nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return 0;

    while(*lista!=NULL && cmp(info,&(*lista)->infoNodo)<0)
        lista=&(*lista)->sig;

    if(*lista && cmp(info,&(*lista)->infoNodo)==0)
    {
        printf("ClaveDuplicada\n\n");
        return 0;
    }

    nue->infoNodo=*info;
    nue->sig=*lista;
    *lista=nue;


    return 1;



}
int cmp(const void *dato1,const void *dato2)
{
    if(((t_info*)dato1)->num >((t_info*)dato2)->num)
        return 1;
    if(((t_info*)dato1)->num <((t_info*)dato2)->num)
        return -1;
        else
        return 0;
}

void mostrarLista(t_lista *lista,t_info *info)
{


    while(*lista)
    {
        MostrarInfoNodo(&(*lista)->infoNodo);
       lista=&(*lista)->sig;
    }
}
void MostrarInfoNodo(const t_info *info)
{
    if(info)
        printf("%d %s\n",info->num,info->nom);

}
int buscarDato(t_lista *lista,const t_info *info,const t_fcmp cmp )
{
    int i=1;

    while(*lista)
    {
        if(cmp(info,&(*lista)->infoNodo)==0)
        {
            return i;
        }
        lista=&(*lista)->sig;
        i++;
    }
    return 0;
}

int eliminarDeLista(t_lista *lista,const t_info *info,const t_fcmp cmp)
{
    t_nodo *aux;

    while(*lista && cmp(info,&(*lista)->infoNodo)>0)
        lista=&(*lista)->sig;

    if(*lista && cmp(info,&(*lista)->infoNodo)==0)
    {
        aux=*lista;
        *lista=aux->sig;
        free(aux);
    }
    return 1;
}
void VaciarLista(t_lista *lista)
{
    t_nodo *aux;

    while(*lista)
    {
        aux=*lista;
        *lista=aux->sig;
        free(aux);
    }
}
int listaLlena(const t_lista *lista)
{
    void *aux=malloc(sizeof(t_nodo));
    if(!aux)
        return 1;
    return 0;
}
int listaVacia(const t_lista *lista)
{
    if(*lista==NULL)
        return 1;
    return 0;
}



int main()
{
    t_info infoVec[4]={
                        {4,"franco"},
                        {1,"franco"},
                        {8,"franco"},
                        {2,"julio"},
                        };
    t_info info;
    t_lista lista;
    int i;

    crearLista(&lista);

    for(i=0;i<4;i++)
        if(!insertarEnOden(&lista,&infoVec[i],cmp))
            printf("No pude\n");


            mostrarLista(&lista,&info);



    printf("\n");
    return 0;
}
