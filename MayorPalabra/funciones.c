#include <stdio.h>
#include "prototipos.h"

int tamMayorPalabra(const char *s)
{
    char *aux = s;
    char *ini = proximaPal(aux);
    char *fin = finPal(ini);
    int tamPal = 0;

    while(ini < fin)
    {
        if(tamPal < (int)(fin - ini))
            tamPal = (int)(fin - ini);

        ini = proximaPal(fin);
        fin = finPal(ini);
    }

    if(tamPal)
        return tamPal;

    return 0;
}

void palMayor(char *s, int tam)
{
    char *ini = proximaPal(s);
    char *fin = finPal(ini);

    while(*ini)
    {
        if(tam == (int)(fin - ini))
        {
            fprintf(stdout,"%.*s",tam,ini);
            puts("");
        }

        ini = proximaPal(fin);
        fin = finPal(ini);
    }
}

char *proximaPal(char *s)
{
    while(esBlanco(*s))
        s ++;
    return s;
}

char *finPal(char *s)
{
    while(!esBlanco(*s) && *s)
        s ++;
    return s;
}
