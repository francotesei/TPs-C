#include <iostream>
#include "Racional.h"


using namespace std;



int main()
{
    Racional r1(3,7), r2(3,11), r3, r4 ,r5,r6;
    r3 = r1 * r2;
    r4 = r3 + 5;
    r5 = 8 + r3;
	r6 = r3 + r5;
    cout << r1<<endl;
    cout << r2<<endl;
    cout << r3<<endl;
    cout << r4<<endl;
    cout << r5<<endl;
    cout << r6<<endl;
     if (r5 != r2)
        cout << "Son distintos" << endl;

    return 0;
}
