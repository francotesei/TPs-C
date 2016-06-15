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

typedef struct
{
    t_nodo *pri;
    t_nodo *ult;
} t_cola;

void CrearCola(t_cola*);
void VaciarCola(t_cola*);
int ColaVacia(const t_cola*);
int ColaLlena(const t_cola*);
int Acolar(t_cola*,const t_info*);
int Desacolar(t_cola*,t_info*);
int VerPri(const t_cola*,t_info*);


void main()
{
    t_cola cola;
    t_info dato;
    int op;
    FILE *pf;
    CrearCola(&cola);
    do
    {
        printf("\n\n---------------------------------------------------------------------");
        printf("\n1- Acolar dato");
        printf("\n2- Desacolar dato");
        printf("\n3- Vaciar cola");
        printf("\n4- Chequear si esta vacia");
        printf("\n5- Chequear si esta llena");
        printf("\n6- Ver primero");
        printf("\n7- Guardar cola en archivo");
        printf("\n8- Vaciar cola actual y cargar la del archivo");
        printf("\n9- Salir");
        printf("\nIngrese opcion: ");
        scanf("%d",&op);

        switch (op)
        {
        case 1:
            if(!ColaLlena(&cola))
            {
                printf("\nIngrese nombre: ");
                scanf("%s",&dato.nombre);
                printf("\nIngrese dni: ");
                scanf("%d",&dato.dni);
                Acolar(&cola,&dato);
                printf("\nDato acolado correctamente.");
            }
            else
                printf("\nLa cola esta llena y no se puede agregar nada");
            break;
        case 2:
            if(Desacolar(&cola,&dato))
                printf("\nDato desacolado correctamente: Nombre %s  DNI: %d",dato.nombre,dato.dni);
            else
                printf("\nLa cola esta vacia");
            break;
        case 3:
            if(!ColaVacia(&cola))
            {
                VaciarCola(&cola);
                printf("\nSe vacio la cola correctamente");
            }
            else
                printf("\nLa cola ya esta vacia");
            break;
        case 4:
            if(ColaVacia(&cola))
                printf("\nLa cola esta vacia");
            else
                printf("\nLa cola no esta vacia");
            break;
        case 5:
            if(ColaLlena(&cola))
                printf("\nLa cola esta llena");
            else
                printf("\nLa cola no esta llena");
            break;
        case 6:
            if(VerPri(&cola,&dato))
                printf("\nEl primero es: Nombre: %s  DNI: %d",dato.nombre,dato.dni);
            else
                printf("\nLa cola esta vacia");
            break;
        case 7:
            if(ColaVacia(&cola))
                printf("\nNo se puede guardar porque la cola esta vacia");
            else
            {
                if(!(pf=fopen("cola.dat","wb")))
                    printf("\nNo se puede crear el archivo");
                else
                {
                    while(Desacolar(&cola,&dato))
                        fwrite(&dato,sizeof(t_info),1,pf);
                    printf("\nCola guardada correctamente en el archivo");
                    fclose(pf);
                }
            }
            break;
        case 8:
            if(!(pf=fopen("cola.dat","rb")))
                printf("\nNo se puede abrir el archivo");
            else
            {
                VaciarCola(&cola);
                fread(&dato,sizeof(t_info),1,pf);
                while(!feof(pf))
                {
                    Acolar(&cola,&dato);
                    fread(&dato,sizeof(t_info),1,pf);
                }
                fclose(pf);
                printf("\nCola cargada de archivo correctamente");
            }
            break;
        }
    }
    while(op!=9);

    printf("\n\nChau :-D");
    getch();
}

void CrearCola(t_cola *pc)
{
    pc->pri =NULL;
    pc->ult=NULL;
}

void VaciarCola(t_cola *pc)
{
    t_nodo *aux;
    while(pc->pri)
    {
        aux=pc->pri;
        pc->pri=aux->sig;
        free(aux);
    }
    pc->ult=NULL;
}

int ColaVacia(const t_cola *pc)
{
    return pc->pri==NULL;
}

int ColaLlena(const t_cola *pc)
{
    t_nodo *nue;
    nue=(t_nodo*)malloc(sizeof(t_nodo));
    free(nue);
    return nue==NULL;
}

int Acolar(t_cola *pc,const t_info *d)
{
    t_nodo *aux;
    aux=(t_nodo*)malloc(sizeof(t_nodo));
    if(!aux)
        return 0;
    aux->dato=*d;
    aux->sig=NULL;
    if(pc->pri==NULL)
        pc->pri=aux;
    else
        pc->ult->sig=aux;
    pc->ult=aux;
    return 1;
}

int Desacolar(t_cola *pc,t_info *d)
{
    t_nodo *aux;
    if(!pc->pri)
        return 0;
    aux=(t_nodo*)malloc(sizeof(t_nodo));
    aux=pc->pri;
    *d=aux->dato;
    pc->pri=aux->sig;
    free(aux);
    if(!pc->pri)
        pc->ult=NULL;
    return 1;
}

int VerPri(const t_cola *pc,t_info *d)
{
    if(!pc->pri)
        return 0;
    *d=pc->pri->dato;
    return 1;
}
