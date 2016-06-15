#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int num;
} t_dato;

typedef struct s_nodo
{
    struct s_nodo*izq;
    t_dato dato;
    struct s_nodo*der;
} t_nodo;
typedef t_nodo * t_arbol;
void crearArbol(t_arbol*p)
{
    *p=NULL;
}
int cargarArbol(t_arbol *p,t_dato *d)
{
    int cmp;
    if(*p)
    {
        cmp=comparar(d,&(*p)->dato);
        if(cmp==0)
            return 0;
        if(cmp<0)
            cargarArbol(&(*p)->izq,d);
        else
            cargarArbol(&(*p)->der,d);
    }
    else
    {
        *p=(t_nodo*)malloc(sizeof(t_nodo));
        if(!*p)
            return 0;
        (*p)->dato=*d;
        (*p)->der=(*p)->izq=NULL;
        return 1;
    }
}
int comparar(t_dato*d1,t_dato*d2)
{
    return (d1->num)-(d2->num);
}
int buscar(t_arbol *p,t_dato *d)
{
    int cmp;
    if(*p)
    {
        cmp=comparar(d,&(*p)->dato);
        if(cmp==0)
            return 1;
        if(cmp>0)
            buscar(&(*p)->der,d);
        if(cmp<0)
            buscar(&(*p)->izq,d);
    }
    else
        return 0;
}
void inorden(t_arbol *p)
{
    t_dato n;
    if(*p)
    {
        inorden(&(*p)->izq);
        n=(*p)->dato;
        printf("\n Numero: %d",n.num);
        inorden(&(*p)->der);
    }
}
void preOrden(t_arbol *p)
{
    t_dato n;
    if(*p)
    {
        n=(*p)->dato;
        printf("\n Numero: %d",n.num);
        preOrden(&(*p)->izq);
        preOrden(&(*p)->der);
    }
}
void posOrden(t_arbol *p)
{
    t_dato n;
    if(*p)
    {
        posOrden(&(*p)->izq);
        posOrden(&(*p)->der);
        n=(*p)->dato;
        printf("\n Numero: %d",n.num);
    }
}
void grabarArchivo(t_arbol *p, FILE *pf)
{
    t_dato num;
    if(*p)
    {
        num=(*p)->dato;
        fwrite(&num,sizeof(t_dato),1,pf);
        if((*p)->izq)
            grabarArchivo(&(*p)->izq,pf);
        if((*p)->der)
            grabarArchivo(&(*p)->der,pf);
    }

}
void leerArchivo(t_arbol *p, FILE *pf)
{
    t_dato num;
    if(*p)
    {
        num=(*p)->dato;
        fread(&num,sizeof(t_dato),1,pf);
        if((*p)->izq)
            leerArchivo(&(*p)->izq,pf);
        if((*p)->der)
            leerArchivo(&(*p)->der,pf);
    }

}
int contarIzquierda (t_arbol *p)
{
    if (*p)
        return contarNodos(&(*p)->izq)+1;
    return 0;
}
int contarDerecha (t_arbol *p)
{
    if (*p)
        return contarNodos(&(*p)->der)+1;
    return 0;
}
int contarNodos (t_arbol *p)
{
    if (*p)
        return contarNodos(&(*p)->izq)+contarNodos(&(*p)->der)+1;
    return 0;
}
int contarHojas (t_arbol*p)
{
    if(*p)
    {
        if ((*p)->izq==NULL&&(*p)->der==NULL)
            return 1;
        else
            return contarHojas(&(*p)->izq)+contarHojas(&(*p)->der);
    }
    return 0;
}
int contarNOHojas (t_arbol *p)
{
    if(*p)
    {
        if ((*p)->izq!=NULL||(*p)->der!=NULL)
            return 1;
        return contarNOHojas(&(*p)->izq)+contarNOHojas(&(*p)->der);
    }
    return 0;
}
int promRH (t_arbol *p,int *cont, float *suma)
{
    if(*p)
    {
        *suma+=(*p)->dato.num;
        (*cont)+=1;
        return promRH(&(*p)->izq,cont,suma)+promRH(&(*p)->der,cont,suma)+1;
    }
    return 0;
}
float promH (t_arbol *p)
{
    int cont=0;
    float suma=0;
    cont=promRH (p,&cont,&suma);
    return (cont==0)?-1:suma/cont;
}
int cortarYContarHojas (t_arbol *p)
{
    if(*p)
    {
        if ((*p)->izq==NULL&&(*p)->der==NULL)
        {
            free (*p);
            *p=NULL;
            return 1;
        }
        return cortarycontarH(&(*p)->izq)+cortarycontarH(&(*p)->der);
    }
    return 0;
}
int eliminarArbol (t_arbol *p) /*POST ORDEN SIEMPRE*/
{
    if(*p)
    {
        if((*p)->izq)
            eliminarArbol(&(*p)->izq);
        if((*p)->der)
            eliminarArbol(&(*p)->der);
        free (*p);
    }
    else return 0;
    *p=NULL;
    return 1;
}
int altura (t_arbol *p)
{
    int hd,hi; //porque no hablo ingles y altura empieza con a
    if (*p)
    {
        hd=altura(&(*p)->der);
        hi=altura(&(*p)->izq);
        return (hd>hi)?hd+1:hi+1;
    }
    return 0;
}
void enAltura (t_arbol *p, int altura)
{
    t_dato dato;
    if (*p)
    {
        if ((altura-1)==0)
        {
            dato=(*p)->dato;
            printf("\n Numero: %d",dato.num);
        }
        else
        {
            enAltura (&(*p)->izq,altura-1);
            enAltura (&(*p)->der,altura-1);
        }
    }
}
void hastaAltura (t_arbol *p, int altura)
{
    t_dato dato;
    if (*p && altura>0)
    {
        dato=(*p)->dato;
        printf("\n Numero: %d",dato.num);
        hastaAltura (&(*p)->izq,altura-1);
        hastaAltura (&(*p)->der,altura-1);
    }
}
void desdeAltura (t_arbol *p, int altura)
{
    t_dato dato;
    if (*p)
    {
        if (altura<=0)
        {
            dato=(*p)->dato;
            printf("\n Numero: %d",dato.num);
        }
        desdeAltura (&(*p)->izq,altura-1);
        desdeAltura (&(*p)->der,altura-1);
    }
}
/*
void reemplazar(t_arbol *p, t_arbol **aux)
{
  if ((*p)->der == NULL)
  {
    (*aux)->dato = (*p)->dato;
    *aux = *p;
    *p = (*p)->izq;
  }
  else
    reemplazar(&(*p)->der, aux);
}

void borrar(t_arbol *p, int numero)
{
  t_arbol *aux;

  if (*p == NULL)
    return;

  if ((*p)->dato.num < numero)
    borrar(&(*p)->der, numero);
  else if ((*p)->dato.num  > numero)
    borrar(&(*p)->izq, numero);
  else if ((*p)->dato.num  == numero)
  {
     aux = *p;
    if ((*p)->izq == NULL)
      *p = (*p)->der;
    else if ((*p)->der == NULL)
      *p = (*p)->izq;
    else
      reemplazar(&(*p)->izq, &aux);

    free(aux);
  }
}
*/
void main()
{
    int opc;
    t_arbol arbol;
    t_dato numero;
    FILE*pf;

    printf("-------------MENU----------");
    printf("\n 1- Crear arbol");
    printf("\n 2- Cargar dato en arbol");
    printf("\n 3- Buscar dato");
    printf("\n 4- Mostrar arbol");
    printf("\n 5- Guardar en archivo");
    printf("\n 6- Cargar desde archivo");
    printf("\n 7- Contar nodos");
    printf("\n 8- Contar nodos del subarblo derecho");
    printf("\n 9- Contar nodos del subarbol izquierdo");
    printf("\n 10- Contar hojas");
    printf("\n 11- Contar NO hojas");
    printf("\n 12- Promedio del arbol");
    printf("\n 13- Cortar y contar hojas");
    printf("\n 14- Eliminar arbol");
    printf("\n 15- Altura arbol");
    printf("\n 16- Nivel arbol");
    printf("\n 0- SALIR");
    printf("\n-------------------------");
    do
    {
        printf("\n elegir opcion: ");
        scanf("%d",&opc);
        switch(opc)
        {
        case 1:
            crearArbol(&arbol);
            break;
        case 2:
        {
            printf("\n Ingrese dato: ");
            scanf("%d",&numero.num);
            if(cargarArbol(&arbol,&numero)==0)
                printf("\n ERROR");
        }
        break;

        case 3:
            printf("\n Ingrese el dato a buscar: ");
            scanf("%d",&numero.num);
            if(buscar(&arbol,&numero)==0)
                printf("\n DATO NO ENCONTRADO");
            else printf("\n DATO ENCONTRADO");
            break;
        case 4:
            printf("\nARBOL (ignore el 0)");
            inorden(&arbol);
            break;
        case 5:
            pf=fopen("arbol.txt","w+b");
            if(!pf) printf("\n ERROR ARCHIVO");
            grabarArchivo(&arbol,pf);
            fclose(pf);

            break;
        case 6:
            pf=fopen("arbol.txt","rb");
            if(!pf) printf("\n ERROR ARCHIVO");
            fread(&numero,sizeof(t_dato),1,pf);
            while(!feof(pf))
            {
                cargarArbol(&arbol,&numero);
                fread(&numero,sizeof(t_dato),1,pf);
            }

            fclose(pf);

            break;
        case 7:
            printf ("\nel arblo tiene %d nodos",contarNodos(&arbol));
            break;
        case 8:
            printf ("\nel arblo tiene %d nodos por derecha",contarNodos(&arbol->der));
            break;
        case 9:
            printf ("\nel arblo tiene %d nodos por izquierda",contarNodos(&arbol->izq));
            break;
        case 10:
            printf ("\nel arblo tiene %d hojas", contarHojas(&arbol));
            break;
        case 11:
            //printf ("\nel arblo tiene %d NO hojas", contarNOHojas(&arbol));
            break;
        case 12:
            printf ("\nel promedio del arbol es %f", promH(&arbol));
            break;
        case 13:
            printf ("\nel arblo perdio %d hojas", cortarycontarH(&arbol));
            break;
        case 14:
            eliminarArbol(&arbol);
            break;
        case 15:
            printf ("\nla altura del arbol es %d", altura(&arbol));
            break;
        case 16:
            printf ("\nel nivel del arbol es %d", altura(&arbol)-1);
            break;

        }
    }
    while(opc!=0);
}
