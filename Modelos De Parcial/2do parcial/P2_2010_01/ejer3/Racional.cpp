#include <iostream>
#include "Racional.h"
#include <math.h>
using namespace std;



int mcd(int x,int y){ // mcd con euclides //
  return (!y) ? x : mcd(y,x%y);
}

Racional::Racional(){
    this->num = 0;
    this->den = 0;
}
Racional::Racional(int num,int den){
    int m;
    if(den!=0){
        m = mcd(num,den);
        this->num = (num/m);
        this->den = (den/m);
    }
}
float Racional::real(){
        return((float(this->num))/(float(this->den)));

}

Racional Racional::operator*(const Racional &obj)const{

    return Racional(this->num*obj.num,this->den*obj.den);
}

Racional Racional::operator+(int x)const{

    return Racional((this->num)+(this->den*x),this->den);

}
Racional Racional::operator+(const Racional &obj)const{

    return Racional((this->num*obj.den)+(this->den*obj.num),this->den*obj.den);

}

Racional operator+(int x,const Racional &obj){

  return Racional((obj.num)+(obj.den*x),obj.den);
}

bool Racional::operator!=(const Racional &obj)const {

    return ((this->num*obj.den) != (this->den*obj.num))?true:false;

}

 ostream& operator<<(ostream & sal,const Racional &obj){
    sal<<obj.num<<" / "<<obj.den;
    return sal;
}

Racional::~Racional(){}






