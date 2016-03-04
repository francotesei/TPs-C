#include <stdio.h>
#include <stdlib.h>

float mySqrt( int b){ /*BABILONIC ALGORITHM*/

    int x = b;
    if(b == 0)
        return 0;

    while(b != (x/b))
        b = 0.5*((x/b)+b);
    return b;

}

int main()
{
    printf("%f",mySqrt(0));
    printf("\n");
    return 0;
}
