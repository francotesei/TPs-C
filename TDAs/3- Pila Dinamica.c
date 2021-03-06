#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct
{
    char nombre[10];
    int dni;
} t_info;

typedef struct s_nodo
{
    t_info dato;
    struct s_nodo *sig;
} t_nodo;

typedef t_nodo* t_pila;

void CrearPila(t_pila*);
void VaciarPila(t_pila*);
int PilaVacia(const t_pila*);
int PilaLlena(const t_pila*);
int VerTope(const t_pila*,t_info*);
int Apilar(t_pila*,const t_info*);
int Desapilar(t_pila*,t_info*);

void main()
{
    t_pila pila;
    t_info dato;
    int op,cant,i;
    FILE *pf;
    CrearPila(&pila);
    do
    {
        printf("\n\n---------------------------------------------------------------------");
        printf("\n1- Apilar dato");
        printf("\n2- Desapilar dato");
        printf("\n3- Vaciar Pila");
        printf("\n4- Chequear si esta vacia");
        printf("\n5- Chequear si esta llena");
        printf("\n6- Ver tope");
        printf("\n7- Guardar en archivo");
        printf("\n8- Vaciar pila actual y cargar la del archivo");
        printf("\n9- Salir");
        printf("\nIngrese opcion: ");
        scanf("%d",&op);

        switch (op)
        {
        case 1:
            if(!PilaLlena(&pila))
            {
                printf("\nIngrese nombre: ");
                scanf("%s",&dato.nombre);
                printf("\nIngrese DNI: ");
                scanf("%d",&dato.dni);
                Apilar(&pila,&dato);
                printf("\nDato apilado correctamente");
            }
            else
                printf("\nLa pila esta llena.");
            break;
        case 2:
            if(Desapilar(&pila,&dato))
            {
                printf("\nDato desapilado correctamente. ");
                printf("Nombre: %s  DNI: %d",dato.nombre,dato.dni);
            }
            else
                printf("\nLa pila esta vacia.");
            break;
        case 3:
            if(!PilaVacia(&pila))
            {
                VaciarPila(&pila);
                printf("\nSe vacio correctamente la pila");
            }
            else
                printf("\nLa pila ya esta vacia");
            break;
        case 4:
            if(PilaVacia(&pila))
                printf("\nLa pila esta vacia");
            else
                printf("\nLa pila no esta vacia");
            break;
        case 5:
            if(PilaLlena(&pila))
                printf("\nLa pila esta llena");
            else
                printf("\nLa pila no esta llena");
            break;
        case 6:
            if(VerTope(&pila,&dato))
                printf("\nNombre: %s   DNI: %d",dato.nombre,dato.dni);
            else
                printf("\nLa pila esta vacia");
            break;
        case 7:
            if(!PilaVacia(&pila))
            {
                if(!(pf=fopen("pila.dat","wb")))
                    printf("\nNo se pudo cargar el archivo");
                else
                {
                    while(Desapilar(&pila,&dato))
                        fwrite(&dato,sizeof(t_info),1,pf);
                    printf("\nPila correctamente guardada en el archivo");
                    fclose(pf);
                }
            }
            break;
        case 8:
            if(!(pf=fopen("pila.dat","rb")))
            {
                printf("\nNo se encuentra el archivo pila.dat o no es accesible en este momento.");
                printf("\nLa pila no se vacio");
            }
            else
            {
                VaciarPila(&pila);
                fseek(pf,0,2);
                cant=ftell(pf)/sizeof(t_info);
                for(i=1; i<=cant; i++)
                {
                    fseek(pf,-sizeof(t_info)*i,2);
                    fread(&dato,sizeof(t_info),1,pf);
                    Apilar(&pila,&dato);
                }
                printf("\nPila cargada de archivo correctamente");
                fclose(pf);
            }
            break;
        }
    }
    while (op!=9);

    printf("\n\nChau :-D");
    getch();
}

void CrearPila(t_pila *pp)
{
    *pp=NULL;
}

void VaciarPila(t_pila *pp)
{
    t_nodo *aux;
    while(*pp)
    {
        aux=*pp;
        *pp=aux->sig;
        free(aux);
    }
}

int PilaVacia(const t_pila *pp)
{
    return *pp==NULL;
}

int PilaLlena(const t_pila *pp)
{
    t_nodo *nue;
    nue=(t_nodo*)malloc(sizeof(t_nodo));
    free(nue);
    return nue==NULL;
}

int VerTope(const t_pila *pp,t_info *d)
{
    if(!*pp)
        return 0;
    *d=(*pp)->dato;
    return 1;
}

int Apilar(t_pila *pp,const t_info *d)
{
    t_nodo *nue;
    nue=(t_nodo*)malloc(sizeof(t_nodo));
    if(!nue)
        return 0;
    nue->dato=*d;
    nue->sig=*pp;
    *pp=nue;
    return 1;
}

int Desapilar(t_pila *pp,t_info *d)
{
    t_nodo *aux;
    if(!*pp)
        return 0;
    *d=(*pp)->dato;
    aux=*pp;
    *pp=aux->sig;
    free(aux);
    return 1;
}
