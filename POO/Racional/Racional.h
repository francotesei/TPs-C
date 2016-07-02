#ifndef RACIONAL_H_INCLUDED
#define RACIONAL_H_INCLUDED

using namespace std;


class Racional{

    private:
        int num,
            den;
    public:
        Racional();
        Racional(int,int);
        Racional(float);

        float real();

        Racional    operator+   (const Racional&)const;
        Racional    operator+   (int)const;
        Racional    operator-   (const Racional&)const;
        Racional    operator-   (int)const;
        Racional    operator*   (const Racional&)const;
        Racional    operator*   (int)const;
        Racional&   operator+=  (const Racional&);
        Racional&   operator-=  (const Racional&);
        Racional&   operator++  ();
        Racional&   operator--  ();
        Racional&   operator+=  (int);
        Racional&   operator-=  (int);

        bool    operator==  (const Racional&)const;
        bool    operator!=  (const Racional&)const;
        bool    operator>   (const Racional&)const;
        bool    operator<   (const Racional&)const;
        bool    operator>=  (const Racional&)const;
        bool    operator<=  (const Racional&)const;


        friend Racional     operator+   (int,const Racional&);
        friend Racional     operator-   (int,const Racional&);
        friend Racional&    operator++  (Racional&);
        friend Racional&    operator--  (Racional&);

        friend ostream&     operator<<  (ostream&,const Racional&);
        friend istream&    operator>>  (istream&,Racional&);

        ~Racional();



};
void myExceptions(char *);
int mcd (int,int);// calcula el mcd




#endif // RACIONAL_H_INCLUDED
