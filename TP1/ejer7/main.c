#include <stdio.h>
#include <stdlib.h>

int classDiv(const int n){
    int d = 1,s=0;

    while(d<n){
        if(n%d == 0)
            s+=d;
        d++;
    }

    if(s == n){
        printf("%d es PERFECTO\n",n);
        return s;
    }else if(s < n){
        printf("%d es DEFICIENTE\n",n);
        return s;
    }
    printf("%d es ABUNDANTE\n",n);
    return s;


}
int main()
{
    classDiv(0);
    printf("\n");
    return 0;
}
