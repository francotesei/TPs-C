#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "protComercial.h"

void crearArchivo(FILE **fp)
{
    *fp = fopen(ARCHPROD,"w+b");

    producto vec[] = {{"12458ASRF7","CHOCOLATE","NESTLE",{14,05,2015},{03,02,2016},101,58.56,25},
                      {"12458ASRF8","PIZZA","PIZZALANDIA",{15,05,2015},{04,02,2016},86.94,36},
                      {"12458ASRF9","HELADO","FREDO",{16,05,2015},{05,03,2016},103.5,82.15,14},
                      {"1458ASR10","RAVIOLES","EL BUEN GUSTO",{17,05,2015},{03,04,2016},44.96,52.96,89},
                      {"12458ASRF1","PAN","LA NORTEÑA",{14,05,2015},{07,04,2016},33.58,41.58,12},
                      {"12458ASF12","FIDEOS","EL BUEN GUSTO",{19,05,2015},{06,03,2016},90,98,78},
                      {"12458SRF13","SORRENTINOS","EL BUEN GUSTO",{20,05,2015},{07,01,2016},78.19,86.19,65},
                      {"12458ARF14","SALSA","EL BUEN GUSTO",{14,05,2015},{03,01,2016},14.15,22.15,28},
                      {"12458ARF15","CONDIMENTO","EL BUEN GUSTO",{22,05,2015},{11,05,2016},29.33,37.33,98},
                      {"12458ARF16","ÑOQUIS","EL BUEN GUSTO",{14,05,2015},{03,06,2016},65.45,73.45,26}};

    if(*fp)
        fwrite(vec,1,sizeof(vec),*fp);
    fclose(*fp);
}

int fechaValida(fecha *d)
{
   static int dias[][12] = {{31,28,31,30,31,30,31,31,30,31,30,31},
                      {31,29,31,30,31,30,31,31,30,31,30,31}};

   if((d->anio > 1900 && d->anio < 2060) || (d->mes > 0 && d->mes < 13) || (d->dia > 0 && d->dia < dias[ES_BISSIESTO(d->anio)][d->mes - 1]))
    return 1;
   return 0;
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

int compararXfcomYstock(const tInfo *d1,const datos *d2)
{
    int cmp = COMPFECHA(d1->fcom.anio,d2->fcom.anio,d1->fcom.mes,d2->fcom.mes,d1->fcom.dia,d2->fcom.dia);
    if(cmp <= 0 && d1->cant <= d2->stockMin)
        return 1;
    return 0;
}

void actualizacionPrecio(FILE ** fp,tInfo *d)
{
    d->prec /= 1.25;
    fseek(*fp,-1 * sizeof(tInfo),SEEK_CUR);
    fwrite(d,1,sizeof(tInfo),*fp);
    fseek(*fp,0,SEEK_CUR);
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
int insertarPorFechaVentaYdescripcion(Lista *p,const tInfo *d,int (*comparar)(const tInfo*,const tInfo*))
{
    while(*p && comparar(&(*p)->info,d) < 0)
        p = &(*p)->sig;
    if(*p && comparar(&(*p)->info,d) == 0)
        return CLA_DUP;
    tNodo *nue = (tNodo*) malloc(sizeof(tNodo));
    if(nue == NULL)
        return SIN_MEM;
    nue->info = *d;
    nue->sig = *p;
    *p = nue;
    return O_K;
}

int compararXfcomYDescrp(const tInfo *d1,const tInfo *d2)
{
    int cmp = COMPFECHA(d1->fvta.anio,d2->fvta.anio,d1->fvta.mes,d2->fvta.mes,d1->fvta.dia,d2->fvta.dia);
    if(cmp)
        return cmp;
    return strcmp(d1->desc,d2->desc);
}

void eliminarDeLista(Lista *p,char *prov)
{
    tNodo *aux;
    while(*p)
    {

        if(strcmpi((*p)->info.prov,prov) == 0)
        {
            aux = *p;
            p = &(*p)->sig;
            free(aux);
        }
        else
            p = &(*p)->sig;
    }
}

void vaciarLista(Lista *p)
{
    tNodo *aux;
    mostrarProd(NULL);
    while(*p)
    {
        if(MAYOR100((*p)->info.prec))
            mostrarProd(&(*p)->info);

        aux = *p;
        p = &(*p)->sig;
        free(aux);
    }
}
void mostrarArchivo(FILE **fp)
{
    long posAct = ftell(*fp);
    tInfo reg;
    rewind(*fp);

    mostrarProd(NULL);
    fread(&reg,1,sizeof(tInfo),*fp);
    while(!feof(*fp))
    {
        mostrarProd(&reg);
        fread(&reg,1,sizeof(tInfo),*fp);
    }
    fseek(*fp,posAct,SEEK_SET);
}
void mostrarProd(const tInfo *d)
{
    if(d)
        printf("%s   %s   %s  %d/%d/%d  %d/%d/%d  %f    %f    %d\n",d->codi,
                                                                  d->desc,
                                                                  d->prov,
                                                                  d->fcom.dia,d->fcom.mes,d->fcom.anio,
                                                                  d->fvta.dia,d->fvta.mes,d->fvta.anio,
                                                                  d->prec,
                                                                  d->cost,
                                                                  d->cant);
    else
        printf("CODIGO    DESCRIPCION   PROVEEDOR   FECHA COMPRA   FECHA VENTA   PRECIO   COSTO   STOCK\n");
}
