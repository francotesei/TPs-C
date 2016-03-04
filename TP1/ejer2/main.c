#include <stdio.h>
#include <stdlib.h>

long int factorial(const int n){

    return (n == 0)?1:n*factorial(n-1);
}

double comb(const int m,const int n){

    return (m >= n && n >= 0)?(factorial(m))/(factorial(n)*factorial(m-n)):-1;
}

int main()
{
    printf("%lf",comb(13,3));
    printf("\n");
    return 0;
}
