#include <stdio.h>
#include <stdlib.h>

long int factorial(const int n){

    return (n==0)?1:n*factorial(n-1);
}

int main()
{
    printf("%d",factorial(1));
    printf("\n");
    return 0;
}
