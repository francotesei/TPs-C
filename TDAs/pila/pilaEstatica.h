#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#define TAM_PILA 10


typedef struct{
    long int dni;
    char nom[50];
}t_info;

typedef struct{
    t_info pila[TAM_PILA];
    int tope;
}t_pila;

void    crearPila(t_pila*);
int     apilar(t_pila*,const t_info*);
int     desapilar(t_pila*,t_info*);
int     verTope(const t_pila*,t_info*);
int     pilaLlena(const t_pila*);
int     pilaVacia(const t_pila*);
void    vaciarPila(t_pila*);


void crearPila(t_pila *p){

    p->tope = 0;
}
int apilar(t_pila *p,const t_info *info){


    if(p->tope == TAM_PILA)
        return 0;
    p->pila[p->tope] = *info;
    p->tope++;
    return 1;
}
int desapilar(t_pila *p,t_info *info){


    if(p->tope == 0)
        return 0;
    p->tope--;
    *info = p->pila[p->tope];
    return 1;
}
int verTope(const t_pila *p,t_info *info){

    if(p->tope == 0)
        return 0;
    *info = p->pila[p->tope-1];
    return 1;
}

int pilaLlena(const t_pila *p){


    return (p->tope == TAM_PILA)?1:0;
}
int pilaVacia(const t_pila *p){


    return (p->tope == 0)?1:0;
}
void vaciarPila(t_pila *p){

    p->tope == 0;
}






#endif // PILA_H_INCLUDED
