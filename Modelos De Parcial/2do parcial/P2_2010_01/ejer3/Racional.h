#ifndef RACIONAL_H_INCLUDED
#define RACIONAL_H_INCLUDED


using namespace std;



class Racional{

    private:
        int num;
        int den;

    public:

        Racional(int,int);
        Racional();
        float real();
        Racional    operator   *(const Racional &)const;
        Racional    operator   +(int)const;
        Racional    operator   +(const Racional&)const;
        bool      operator     !=(const Racional&)const;

        friend ostream& operator<<(ostream&,const Racional&);
        friend Racional operator +(int,const Racional&);
        friend int mcd(int,int);
        ~Racional();



};



#endif // RACIONAL_H_INCLUDED
