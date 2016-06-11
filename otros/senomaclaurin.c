/**
*************************************************************
* @file senoMaclaurin.c
* @brief Cálculo del seno con el algoritmo de MacLaurin
*
* @author Gaspar Fernández <blakeyed@totaki.com>
* http://totaki.com/poesiabinaria/algoritmos/
*
* Compilar con:
*   $ gcc -o senoMaclaurin senoMaclaurin.c -lm
* para incluir la biblioteca matemática 
*************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define PI 3.141592653588

unsigned factorial(int n)
{
  if (n<1)
    return 1;
  
  return n*factorial(n-1);
}

double senoTaylor(double n)
{
  double t=0;
  int i;

  short signo=(n>=0);
  n=fabs(n);			/* Calculamos el valor absoluto */

  while (n>PI)		/* Reducimos el ángulo, de dos en dos cuadrantes*/
    {
      n-=PI;			/* 1 vuelta = 2PI radianes */
      signo=!signo;		/* cada PI, el signo cambia */
    }

  for (i=0; i<9; i++)
    t+=pow(-1, i)*pow(n, 2*(double)i+1)/(double)factorial(2*i+1);

  if (!signo)			/* Cambiamos el signo del ángulo */
    t*=-1;

  return t;
}

int main(int argc, char *argv[])
{
  double n;
  printf ("Introduzca un numero: ");
  scanf ("%lf", &n);

  printf ("sen: %lf\n", sin(n));
  printf ("sen: %lf\n", senoTaylor(n));

  return EXIT_SUCCESS;
}

