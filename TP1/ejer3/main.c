#include <stdio.h>
#include <stdlib.h>

long int factorial(const int n){

    return (n==0)?1:n*factorial(n-1);
}

long int pot(const int b,const int e){

    return (e == 0)?1:b*pot(b,e-1);
}

float eX(const int x,const int t){ /** ARREGLAR **/

    return (1+(t<0)?1:(pot(x,t)/factorial(t))+(eX(x,t-1)));
}

int main()
{
    printf("%f",eX(9,3));
    printf("\n");
    return 0;
}
