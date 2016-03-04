#include <stdio.h>
#include <stdlib.h>

int proXsum(const int a,const int b){

    return (a == 0)?0:b+proXsum(a-1,b);
}

int main()
{
    printf("%d",proXsum(1,22));
    printf("\n");
    return 0;
}
