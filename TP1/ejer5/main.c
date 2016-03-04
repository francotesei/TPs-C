#include <stdio.h>
#include <stdlib.h>

int fibonacci(const int n)
{
   if (n == 0)
      return 0;
   else if (n == 1)
      return 1;
   else
      return (fibonacci(n-1) + fibonacci(n-2));
}


int isFibbo(const int x){
    int n = 0,a;

    while(x >= (a = fibonacci(n))){
        if(x == a)
            return 1;
        n+=1;
    }return 0;
}

int main()
{
    printf("%d",isFibbo(9));
    printf("\n");
    return 0;
}
