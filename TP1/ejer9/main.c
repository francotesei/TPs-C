#include <stdio.h>
#include <stdlib.h>

typedef struct{
int divisor,
    dividendo,
    cociente,
    resto
}t_division;

int doDiv( t_division *div){
    if((*div).divisor == 0)
        return 0;


    (*div).cociente = (*div).dividendo/(*div).divisor;
    (*div).resto =(*div).dividendo%(*div).divisor;
    return 1;
}

int main()
{
    t_division div;

    div.dividendo = 17;
    div.divisor = 0;
    if(doDiv(&div))
    printf("%d",div.resto);
    printf("\n");
    return 0;
}
