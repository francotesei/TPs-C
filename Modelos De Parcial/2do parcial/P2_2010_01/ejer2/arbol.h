#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

typedef struct{
    int x;
}t_info;

typedef struct s_nodo{
    t_info info;
    struct s_nodo *izq,
                  *der;
}t_nodo,*t_arbol;

void crearArbol          (t_arbol*);

int altura              (const t_arbol*);

int arbolCompleto       (const t_arbol*);
int esCompleto          (const t_arbol*,int);

int arbolAVL            (const t_arbol*);
int esAVL               (const t_arbol*,int);


#endif // ARBOL_H_INCLUDED
