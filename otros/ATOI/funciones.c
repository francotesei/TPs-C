#include <stdio.h>
#include "prototipo.h"

int a_toi(const char *s)
{
    char *aux = s,*aux2 = s,sig = '+';
    int acum = 0;

    //y si tiene un caracter que no es digito?

    if(!seaBlanco(aux2))
        return acum;

    if(*aux == '-')
    {
        sig = '-';
        aux ++;
    }
    else
    {
        if(*aux == '+') // La cadena viene con un caracter '+'??
            aux ++;
    }

    while(seaDigito(*aux) && *aux)
    {
      acum = (acum*10) + (*aux - '0');
      aux ++;
    }

    return sig == '-' ? -acum : acum;
}

int seaDigito(char a)
{
    char digitos[] = {"0123456789"};
    int i = 0;

    while(i < sizeof(digitos)-1)
    {
        if(digitos[i] == a)
            return 1;
        i ++;
    }
    return 0;
}

int seaBlanco(char *s)
{
    while(*s)
    {
        if(esBlanco(*s))
            return 0;
        s ++;
    }
    return 1;
}
