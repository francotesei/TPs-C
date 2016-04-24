#include <stdio.h>
#include <string.h>
#include "prototipos.h"

char *i_toa(int n,char *s, int base)
{
   char *ini = s, *fin, aux;
   char digitos[] = {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
   unsigned num = (unsigned) n;

   if(n < 0 && base == 10)
   {
       *ini = '-';
       ini ++;
       n = -n;
   }
   fin = ini;

   while(num)
   {
       *fin = digitos[num % base];
       num = num / base;
       fin ++;
   }
   *fin = '\0';
   fin --;

   while(ini < fin)
   {
       aux = *ini;
       *ini = *fin;
       *fin = aux;
       ini ++;
       fin --;
   }

   return s;
}
