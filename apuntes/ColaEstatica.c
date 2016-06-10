#include <stdio.h>
#include <stdlib.h>
#define TAM 10
typedef struct
{
    int num;
} t_info;
typedef struct
{
    int pri,ult;
    t_info cola[TAM]
} t_cola;
void crearCola(t_cola *cola)
{
    cola->pri=0;
    cola->ult=-1;
}
int colaVacia(const t_cola *cola)
{
    if(cola->ult==-1)
        return 1;
    return 0;
}
int colaLlena(const t_cola *cola)
{
    if((cola->ult==TAM-1)&&(cola->pri==0)||((cola->ult==cola->pri-1)&&(cola->ult!=-1)))
        return 1;
    return 0;
}
int acolar(t_cola *cola,const t_info *info)
{
    if((cola->pri==0 && cola->ult==TAM-1)|| (cola->pri==cola->ult+1 && cola->ult!=-1))
        return 0;
    cola->ult++;
    if(cola->ult==TAM)
        cola->ult=0;

    cola->cola[cola->ult]=*info;

    return 1;
}
int DesACola(t_cola *cola,t_info *info)
{
    if(cola->ult==-1)
        return 0;

    *info=cola->cola[cola->pri];

    if (cola->pri==cola->ult)
    {
        cola->pri=0;
        cola->ult=0;
    }
    else
    {
        cola->pri++;
        if(cola->pri==TAM)
            cola->pri=0;

    }
    return 1;
}
int verPrimero(const t_cola *cola,t_info *info)
{
	if(cola->ult==-1)
	return 0;
	
	*info=cola->cola[cola->pri];
	return 1;
	

}
void vaciarCola(t_cola *cola)
{
    cola->pri=0;
    cola->ult=-1;
}
int main()
{
    printf("\n");
    return 0;
}
