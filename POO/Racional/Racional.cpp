#include <iostream>
#include "Racional.h"
#define  MSG_DIVCERO "DIVISION POR 0 NO PERMITIDA!,MATH ERROR."
#define  DIVCERO 0

using namespace std;

void myExceptions(int a){

    try{
        throw a;

    }catch(int e){
        switch(e){
            case 0:
                cerr<<MSG_DIVCERO<<endl;
            break;

        }
    }
}

int mcd(int x,int y){

    return (!y)?x:mcd(y,x%y);
}

Racional::Racional(){

    this->num = 0;
    this->den = 0;

}

Racional::Racional(int num , int den){
    int m;

    if(!den)
        myExceptions(DIVCERO);

    m = mcd(num,den);
    this->num = (num/m);
    this->den = (den/m);

}

Racional::Racional(float f){}



float Racional::real(){
    if(!this->den)
        myExceptions(DIVCERO);

    return((float(this->num))/(float(this->den)));

}

Racional Racional::operator+(const Racional &obj)const{

        if(!den)
            myExceptions(DIVCERO);

    return Racional((num*obj.den)+(den*obj.num),den*obj.den);

}
Racional Racional::operator+(int x)const{

    if(!den)
        myExceptions(DIVCERO);

    return Racional(num+(den*x),den);

}

Racional Racional::operator-(const Racional &obj)const{

    if(!den)
        myExceptions(DIVCERO);

    return Racional((num*obj.den)-(obj.num*den),den*obj.den);


}

Racional Racional::operator-(int x)const {

    if(!den)
        myExceptions(DIVCERO);

    return Racional(num-(x*den),den);

}

Racional Racional::operator*(const Racional &obj)const{

    if(!den)
        myExceptions(DIVCERO);

    return Racional(num*obj.num,den*obj.den);
}

Racional Racional::operator*(int x)const {

    if(!den)
        myExceptions(DIVCERO);

    return Racional(num*x,den);

}

Racional& Racional::operator++(){}

Racional& Racional::operator--(){}

Racional& Racional::operator+=(const Racional &obj){

    if(!den)
    myExceptions(DIVCERO);

    Racional rAux((num*obj.den)+(obj.num*den),den*obj.den); // creo el objeto para ya me retorne la fraccion simplificada.
    num = rAux.num;
    den = rAux.den;
    return *this;
}

Racional& Racional::operator+=(int x){

    if(!den)
        myExceptions(DIVCERO);

    Racional rAux(num+(den*x),den); // creo el objeto para que  ya me retorne la fraccion simplificada.
    num = rAux.num;
    den = rAux.den;
    return *this;

}

Racional& Racional::operator-=(const Racional &obj){

  if(!den)
    myExceptions(DIVCERO);

    Racional rAux((num*obj.den)-(obj.num*den),den*obj.den); // creo el objeto para ya me retorne la fraccion simplificada.
    num = rAux.num;
    den = rAux.den;
    return *this;


}

Racional& Racional::operator-=(int x){

    if(!den)
        myExceptions(DIVCERO);

    Racional rAux(num+(den*x),den); // creo el objeto para que  ya me retorne la fraccion simplificada.
    num = rAux.num;
    den = rAux.den;
    return *this;


}

bool Racional::operator==(const Racional &obj)const {

    return ((num*obj.den) == (den*obj.num))?true:false;

}

bool Racional::operator!=(const Racional &obj)const{

     return ((num*obj.den) != (den*obj.num))?true:false;

}

bool Racional::operator<(const Racional &obj)const {}

bool Racional::operator>(const Racional &obj)const {}

bool Racional::operator<=(const Racional &obj)const {}

bool Racional::operator>=(const Racional &obj)const {}



 Racional operator+(int x,const Racional &obj){

    if(!obj.den)
        myExceptions(DIVCERO);

    return Racional(obj.num+(obj.den*x),obj.den);


}

 Racional operator-(int x, const Racional &obj){

  if(!obj.den)
        myExceptions(DIVCERO);

    return Racional(obj.num+(obj.den*x),obj.den);


}

Racional& operator++(Racional &obj){}
Racional& operator--(Racional &obj){}


ostream& operator<<(ostream &sal,const Racional &obj){

    if(!obj.den)
        sal<<0;
    else
        sal<<obj.num<<" / "<<obj.den;
    return sal;

}

istream& operator>>(istream &ent , Racional &obj){

    ent>>obj.num;
    cout<<" / ";
    ent>>obj.den;
    return ent;
}



Racional::~Racional(){}
