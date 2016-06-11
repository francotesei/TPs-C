#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "protClientes.h"

void crearArchivoCli(FILE **fp)
{
    *fp = fopen(ARCH_CLI,"w+b");

    clientes vec[] = {{3358793,895.23},
                      {17852593,125.23},
                      {12396393,365.23},
                      {1231193,1235.23},
                      {12357893,195.23},
                      {12352363,875.23},
                      {12558793,355.23},
                      {9865893,455.23},
                      {77858793,695.23},
                      {1538793,2595.23}};

    if(*fp)
        fwrite(vec,1,sizeof(vec),*fp);
    fclose(*fp);
}
void crearArchivoInd(FILE **fp)
{
    *fp = fopen(ARCH_IND,"w+b");

    indices vec[] = {{1231193,3},
                     {12352363,5},
                     {12357893,4},
                     {12396393,2},
                     {12558793,6},
                     {1538793,9},
                     {17852593,1},
                     {3358793,0},
                     {77858793,8},
                     {9865893,7}};

    if(*fp)
        fwrite(vec,1,sizeof(vec),*fp);
    fclose(*fp);
}

void crearArchivoNov(FILE **fp)
{
    *fp = fopen(ARCH_NOV,"w+b");

    novedades vec[] = {{3358793,'P',7825.0},
                       {17852593,'P',3225.0},
                       {12396393,'V',8225.0},
                       {1231193,'V',1925.0},
                       {12357893,'V',1625.0},
                       {12352363,'P',225.0},
                       {12558793,'P',3225.0},
                       {9865893,'V',4225.0},
                       {77858793,'V',1525.0},
                       {1538793,'P',36225.0}};

    if(*fp)
        fwrite(vec,1,sizeof(vec),*fp);
    fclose(*fp);
}

int abrirArchivo(FILE **fp,const char *nombre,const char *modo,int CON_SIN)
{
    *fp = fopen(nombre,modo);

    if(!*fp)
    {
        if(CON_SIN)
            fprintf(stderr,"ERROR - Imposible abrir archivo /%s/ en modo %s",nombre,modo);
        return 0;
    }
    return 1;
}
void actualizarArch(FILE **cl,FILE **nov,Lista *p)
{
    clientes cli;
    novedades nved;
    Lista *aux;
    fread(&nved,1,sizeof(novedades),*nov);
    while(!feof(*nov))
    {
        aux = p;
        while(*aux && comparar(&(*aux)->info.nro_cli,&nved.nro_cli) != 0)
            aux = &(*aux)->sig;
        if(*aux)
        {
            fseek(*cl,(*aux)->info.reg * sizeof(clientes),SEEK_SET);
            fread(&cli,1,sizeof(clientes),*cl);
            if(nved.nov == 'P')
              cli.saldo /= 1.25;
            else
              cli.saldo *= 1.25;
            fseek(*cl,-1 * sizeof(clientes),SEEK_CUR);
            fwrite(&cli,1,sizeof(clientes),*cl);
            fseek(*cl,0,SEEK_CUR);
        }
        else
            printf("\nCliente nro. %u no existe",nved.nro_cli);

        fread(&nved,1,sizeof(novedades),*nov);
    }
}

void crearLista(Lista *p)
{
    *p = NULL;
}
int listaVacia(Lista *p)
{
    return *p == NULL;
}
int listaLlena(Lista *p)
{
    void *aux = malloc(sizeof(tNodo));
    free(aux);
    return aux == NULL;
}
int insertarEnOrden(Lista *p,const tInfo *d,int (*comparar)(const unsigned*,const unsigned*))
{
    tNodo *nue;
    while(*p && comparar(&(*p)->info.nro_cli,&d->nro_cli) < 0)
        p = &(*p)->sig;
    if(*p && comparar(&(*p)->info.nro_cli,&d->nro_cli) == 0)
        return CLAV_DUP;

    nue = (tNodo*) malloc(sizeof(tNodo));
    if(nue == NULL)
        return SIN_MEM;
    nue->info = *d;
    nue->sig = (*p);
    (*p) = nue;
    return O_K;
}
int compararXindice(const unsigned *d1,const unsigned *d2)
{
    return (int)*d1 - (int)*d2;
}
void vaciarLista(Lista *p)
{
    tNodo *aux;
    while(*p)
    {
        aux = *p;
        p = &(*p)->sig;
        free(aux);
    }
}

void mostrarArchivo(FILE **fp)
{
   clientes reg;
   long actualPos = ftell(*fp);
   rewind(*fp);
   mostrarCliente(NULL);
   fread(&reg,sizeof(clientes),1,*fp);
   while(!feof(*fp))
   {
       mostrarCliente(&reg);
       fread(&reg,sizeof(clientes),1,*fp);
   }
   fseek(*fp,actualPos,SEEK_SET);
   fclose(*fp);
}

void mostrarCliente(clientes *p)
{
    if(p)
        printf("%u    %.2f\n",p->nro_cli,p->saldo);
    else
        printf("Numero de cliente        Saldo\n");
}
