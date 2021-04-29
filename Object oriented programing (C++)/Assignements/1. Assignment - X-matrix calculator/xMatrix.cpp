#include "xMatrix.h"
#include <iomanip>
#include <iostream>
#include <istream>
#include <ostream>

using namespace std;

int xMatrix::matrixSize() const
{
    int n;
    if(Matrix.size() % 2 == 0)
    {
        n = Matrix.size() / 2;
    }
    else
    {
        n = Matrix.size() / 2 + 1;
    }
    return n;
}
int xMatrix::operator()(int i, int j) const
{
    if ((i >= matrixSize() || i < 0 ) || (j >= matrixSize() || j < 0 )) throw OVERINDEXED;
    if(matrixSize() % 2 == 0)
    {
        if(i == j || i + j == matrixSize() - 1)
        {
            return Matrix[elementEven(i,j)];
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if(i == j || i + j == matrixSize() - 1)
        {
            return Matrix[elementOdd(i,j)];
        }
        else
        {
            return 0;
        }
    }
}
int xMatrix::elementOdd(int i, int j) const
{
    if(i == j)
    {
        return (2 * i);
    }
    else if(i < j)
    {
        return (matrixSize() - j + i);
    }
    else if(i > j)
    {
        return ((2 * i) - 1);
    }
}
int xMatrix::elementEven(int i, int j) const
{
    if(i == j)
    {
       if(i < matrixSize()/2)
       {
           return (2 * i);
       }
       else if(i >= matrixSize()/2)
       {
           return ((2 * i)+1);
       }
    }
    else if(i + j == matrixSize() - 1)
    {
        if(i < matrixSize()/ 2)
        {
            return(matrixSize()-j+i);
        }
        else if(i >= matrixSize()/2)
        {
            return (2 * i);
        }
    }
}
int& xMatrix::operator()(int i, int j)
{
    if ((i >= matrixSize() || i < 0 ) || (j >= matrixSize() || j < 0 )) throw OVERINDEXED;
    if(matrixSize() % 2 == 0)
    {
        if(i == j || i + j == matrixSize() - 1)
        {
            return Matrix[elementEven(i,j)];
        }
    }
    else
    {
        if(i == j || i + j == matrixSize() - 1)
        {
            return Matrix[elementOdd(i,j)];
        }
    }

}
ostream& operator<<(ostream& s, const xMatrix& a)
{
    for(unsigned int i = 0; i < a.matrixSize(); ++i)
        {
        for(unsigned int j = 0; j < a.matrixSize(); ++j)
        {
            s << std::setw(5) << a(i,j);
        }
        s << std::endl;
    }
    return s;
}
istream& operator>>(istream& s, xMatrix& a)
{
    unsigned int matrixSize;
    s >> matrixSize;
    if(matrixSize % 2 == 0){a.reSize(matrixSize*2);}
    else{a.reSize(matrixSize*2-1);}
    for(unsigned int i = 0; i < a.Matrix.size() ; ++i)
    {
        s >> a.Matrix[i];
    }
    std::cout << std::endl;
    return s;
}
xMatrix operator+(const xMatrix& a ,const xMatrix& b)
{
    if(a.Matrix.size()!=b.Matrix.size()) throw xMatrix::DIFFERENT;
    xMatrix c(a.Matrix.size());
    for(unsigned int i = 0; i < c.Matrix.size(); ++i)
    {
        c.Matrix[i] = a.Matrix[i] + b.Matrix[i];
    }
    return c;
}
xMatrix operator*(const xMatrix& a ,const xMatrix& b)
{
    if(a.Matrix.size()!= b.Matrix.size()) throw xMatrix::DIFFERENT;
    xMatrix c(a.Matrix.size());
    for(unsigned int i = 0; i < a.matrixSize(); ++i)
    {
        for(unsigned int j = 0; j < a.matrixSize(); ++j)
        {
            for(unsigned int k = 0; k < a.matrixSize(); ++k)
            {
                c(i,j) += a(i,k) * b(k,j);
            }
        }
    }
    return c;
}
int xMatrix::getElementeOfMatrix(int i, int j)
{
    int x;
    x = (i,j);
    return x;
}
