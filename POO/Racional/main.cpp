#include <iostream>
#include "Racional.h"

using namespace std;

int main()
{
    int x;

    Racional r2(3,2),r1,r3,r4,r5,r6;

    r1 = r2;
    r3 = 5 + r1;




    cout<<r1<<endl;
    cout<<r2<<endl;
    cout<<r2.real()<<endl;
    cout<<r3<<endl;
    cout<<r4<<endl;
    cout<<r5<<endl;
    cout<<r6<<endl;


    return 0;
}
