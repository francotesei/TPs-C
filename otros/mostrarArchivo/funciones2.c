#include <stdio.h>
#include "prototipos.h"

int abrirArchivo(FILE **fp,char *modo,char *archivo,int CON_SIN)
{
    *fp = fopen(archivo,modo);//devuelve una direccion de memoria

    if(!*fp)
    {
        if(CON_SIN_MSJ == CON_SIN)
            fprintf(stderr,"Error-abriendo\"%s\" en modo \"%s\"\n",archivo,modo);

        return 0;
    }
    return 1;
}
