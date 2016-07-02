#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x;
    char *y;

}t_info;

typedef struct s_nodo{
    t_info info;
    struct s_nodo *sig;

}t_nodo,*t_cola;

void    crearCola(t_cola*);
int     acolar(t_cola*,const t_info*);
int     desacolar(t_cola*,t_info*);
int     colaLlena(const t_cola*);
int     colaVacia(const t_cola*);
int     verPrimero(const t_cola*,t_info*);
void    vaciarCola(t_cola*);


int main()
{
    t_info info;
    t_cola cola;
    crearCola(&cola);
   // acolar(&cola,&info);

    printf("%d\n",colaVacia(&cola));
    return 0;
}


void crearCola(t_cola *c){

    *c = NULL;

}

int acolar(t_cola *c,const t_info *info){

    t_nodo *nue = (t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return 0;

    nue->info = *info;

    if(!(*c)){
        nue->sig = nue;

    }else{

        nue->sig = (*c)->sig;
        (*c)->sig = nue;
    }
    *c = nue;
    return 1;
}

int desacolar(t_cola *c,t_info *info){

    t_nodo *aux;

    if(!(*c))
        return 0;

    aux = (*c)->sig;
    *info = aux->info;
    (*c)->sig = aux->sig;
    free(aux);
    if(*c == aux)
        *c = NULL;

    return 1;
}
int colaLlena(const t_cola*c){

void * aux = malloc(sizeof(t_nodo));
free(aux);

return (!aux)? 1 : 0;

}

int colaVacia(const t_cola *c){

    return !(*c);

}

int verPrimero(const t_cola * c, t_info *info){

    if(!(*c))
        return 0;
    *info = (*c)->sig->info;
    return 1;
}

void vaciarCola(t_cola *c){

    t_nodo *aux;

    while(*c){

    aux = (*c)->sig;
    (*c)->sig = aux->sig;
    free(aux);
    if(aux == *c)
        *c = NULL;
    }


}











