
 //Librerías
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//Estructura
struct _fecha
{
    int dia;
    int mes;
    int anio;
} fechaactual;
void ordBurbuja (long a[], int n)
{
int interruptor = 1;
int pasada, j;
for (pasada = 0; pasada < n-1 && interruptor; pasada++)
{
/* bucle externo controla la cantidad de pasadas */
interruptor = 0;
for (j = 0; j < n-pasada-1; j++)
if (a[j] > a[j+1])
{
/* elementos desordenados, es necesario intercambio */
long aux;
interruptor = 1;
aux = a[j];
a[j] = a[j+1];
a[j+1] = aux;
}
}
}
/////////////////////////////////////////////////////////////////////
void  binarioTexto(){}
void  textoBinario(){}
int restarFecha(){}

void sumaSegundosAunaHora(int h, int m, int s){

    if (s>=60){
        m++;
        s=s%60;
    }
     if (m>=60){
        h++;
        m=m%60;
    }
       if (h>=24){
        h=h%24;
    }
    cout <<h<<":"<<m<<":"<<s<<endl;
}



//función que calcula si es bisiesto un año
int bisiesto(int anio)
{
    if (anio%400 == 0 || (anio%4==0 && anio%100!=0))
        return 1;
    else
        return 0;
}

//función que Calcula los días de un mes
int dias_mes(struct _fecha fecha)
{
    switch (fecha.mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;

    case 2:
        if (bisiesto(fecha.anio))
            return 29;
        else
            return 28;
    }
    return 0;
}

//Determinar si la fecha es válida
int validarFecha(struct _fecha fecha)
{
    if (fecha.mes>0 && fecha.mes<=12)
    {
        if (fecha.dia>0 && fecha.dia<=dias_mes(fecha))
            return 1;
        else
            return 0;
    }
    else
        return 0;
}

 int cuenta_dias(struct _fecha fecha1, struct _fecha fecha2)
{
    int acum=0;
    while (1)
    {
        if (fecha1.anio == fecha2.anio && fecha1.mes == fecha2.mes)
            break;

        acum=acum+(dias_mes(fecha1)-fecha1.dia);

        if(fecha1.mes==12)
        {
            fecha1.mes=1;
            fecha1.anio++;
        }
        else
            fecha1.mes++;

        fecha1.dia=0;
    }
    acum=acum+(fecha2.dia-fecha1.dia);
    return acum;
}

// main program
int main ()
{
    fechaactual.dia = 8;
    fechaactual.mes = 2;
    fechaactual.anio = 2012;
    if (validarFecha(fechaactual))
    {
        puts("es valida!\n") ;
    }
    else
    {
        puts("No es valida!\n") ;
    }
    return 0;
{
    struct _fecha fecha1, fecha2;

    fecha1.dia = 8;
    fecha1.mes = 2;
    fecha1.anio = 2012;

    fecha2.dia = 18;
    fecha2.mes = 2;
    fecha2.anio = 2012;


    printf("%d dias de diferencia entre ambas fechas.\n", cuenta_dias(fecha1, fecha2));
    return 0;
}
}
