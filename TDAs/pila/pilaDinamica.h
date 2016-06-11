#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED

typedef struct{
    long int dni;
    char nom[50];
}t_info;

typedef struct s_nodo{ /* s_nodo es el nombre de la estructura*/

    t_info info;
    struct s_nodo *sig; /*es un punturo a esta misma structura */

}t_nodo ,*t_pila; /*t_pila es un * a t_nodo */


void    crearPila(t_pila*);
int     apilar(t_pila*,const t_info*);
int     desapilar(t_pila*,t_info*);
int     verTope(const t_pila*,t_info*);
int     pilaLlena(const t_pila*);
int     pilaVacia(const t_pila*);
void    vaciarPila(t_pila*);

void crearPila(t_pila *p){

    *p = NULL;
};

int apilar(t_pila *p ,const t_info *info){

    t_nodo *nue =(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return 0;

    nue->info = *info;
    nue->sig =*p;
    *p = nue;
    return 1;
};

int desapilar(t_pila *p,t_info *info){

    t_pila aux;
    if(*p == NULL)
        return 0;
    *info = (*p)->info;
    aux = *p;
    *p = aux->sig;
    free(aux);
    return 1;
};

int verTope(const t_pila *p,t_info *info){

    if(*p == NULL)
        return 0;
    *info = (*p)->info;
    return 1;
};

int pilaLlena(const t_pila *p){

    void *aux = malloc(sizeof(t_nodo));
    free(aux);
    return (!aux)?1:0;
};

int pilaVacia(const t_pila *p){

    return (*p==NULL)?1:0;
};

void vaciarPila(t_pila *p){

    t_nodo *aux;
    while(*p != NULL){
        aux = *p;
        *p = aux->sig;
        free(aux);
    }
    *p = NULL;
};







#endif // PILADINAMICA_H_INCLUDED
