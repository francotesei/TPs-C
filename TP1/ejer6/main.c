#include <stdio.h>
#include <stdlib.h>

long int fact(const int n){ /* ARREGLAR */

    return (n==0)?1:n*fact(n-1);
}

long int pot(const int b, const int e){

    return (e == 0)?1:b*pot(b,e-1);
}

float sinX(const int x, const int t){


}

int main()
{
    printf("%ld",pot(2,3));
    printf("\n");
    return 0;
}
