#include <iostream>
#ifndef COMPLEX_H
#define COMPLEX_H

using namespace std;

class Complex
{
    private:
        int real, im;
    public:
        Complex(){this->real = 0; this->im = 0;};
        Complex(int a,int b){this->real = a; this->im = b;};
        void printComplex()
        {
            cout << this->getComplexReal();
            if(this->getComplexIm() < 0)
            {
                cout << " - " << this->getComplexIm() <<"i" << endl;
            }
            else
            {
                cout << " + " << this->getComplexIm() << "i"<< endl;
            }
        }
        void setComplexReal(int x)
        {
            this->real = x;
        }
        void setComplexIm(int x)
        {
            this->im = x;
        }
        int getComplexReal()
        {
            return this->real;
        };
        int getComplexIm()
        {
            return this->im;
        };
        Complex sum(Complex a)
        {
            Complex c;
            c.setComplexReal(a.getComplexReal() + this->getComplexReal());
            c.setComplexIm(a.getComplexIm() + this->getComplexIm());
            return c;
        };
        Complex multiply(Complex a)
        {
            Complex c;
            c.setComplexReal(a.getComplexReal()*this->getComplexReal()-a.getComplexIm()*this->getComplexIm());
            c.setComplexIm(a.getComplexReal()*this->getComplexIm()+a.getComplexIm()*this->getComplexReal());
            return c;
        };
        Complex divide(Complex a)
        {
            Complex c;
            c.setComplexReal((a.getComplexReal()*this->getComplexReal()+a.getComplexIm()*this->getComplexIm())/((this->getComplexReal()*this->getComplexReal())-(this->getComplexIm()*this->getComplexIm())));
            c.setComplexIm(this->getComplexReal()*a.getComplexIm()-a.getComplexReal()*this->getComplexIm()/((this->getComplexReal()*this->getComplexReal())-(this->getComplexIm()*this->getComplexIm())));
            return c;
        };
};

#endif
