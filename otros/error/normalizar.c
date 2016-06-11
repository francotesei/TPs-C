#include<stdio.h>
#include<stdlib.h>
#define esBlanco(X) ((X) == ' ' || (X) == '\t')
#define esMin(X) ((X) > = 'a' && (X) < = 'z' ? (X) - '32' : (X))
#define esMay(X) ((X) > = 'A' && (X) < = 'Z' ? (X) + '32' : (X))

void normalizar(char []);

int main()
{
  char cad[31];

  Printf("\t\t\tNormalizar Cadena \n\n Ingrese cadena a normalizar: ");
  gets(cad);
  normalizar(cad);
  puts(cad);
}

void normalizar(char *c)
{
   char *dest = c,
        *pos = dest;

   while(*pos)
   {
      while(esBlanco(*pos))

        pos ++;

      if(*pos)
      {
          printf("%s",pos);
         //*dest = esMin(*pos);
         dest ++;
         pos ++;

        while(!esBlanco(*pos) && *pos)
        {
          //*dest = pesMay(*pos);
           dest ++;
           pos ++;
        }
        if(*pos)
        {
          *dest = ' ';
          dest ++;
          pos ++;
        }

      }

   }

   if(dest > c && esBlanco(*(dest - 1)))
     dest --;

   *dest = '\0';
}
