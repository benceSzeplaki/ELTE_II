#ifndef XMATRIX_H
#define XMATRIX_H
#include <vector>
#include<iostream>

class xMatrix
{
    public:
        enum Exceptions{OVERINDEXED, NULLPART, DIFFERENT};

        xMatrix(){ }
        xMatrix(int x): Matrix(x, 0) { }
        xMatrix(const std::vector<int> &v): Matrix(v) { }

        void reSize(int x) { Matrix.resize(x, 0); }

        int operator()(int i, int j) const;
        int& operator()(int i, int j);
        int matrixSize() const;

        int elementOdd(int i, int j) const;
        int elementEven(int i, int j) const;

        friend xMatrix operator+ (const xMatrix& a, const xMatrix& b);
        friend xMatrix operator* (const xMatrix& a, const xMatrix& b);

        friend std::istream& operator>> (std::istream& s, xMatrix& a);
        friend std::ostream& operator<< (std::ostream& s, const xMatrix& a);

        int getElementeOfMatrix(int i, int j);
    private:
        std::vector<int> Matrix;

};

#endif
