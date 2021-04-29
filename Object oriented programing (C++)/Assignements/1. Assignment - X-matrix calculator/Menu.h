#ifndef MENU_H
#define MENU_H
#include "xMatrix.h"

class Menu
{
    public:
        void run();
        void writeMenuPoints();
        int selectMenuPoint();
        void readMatrix();
        void writeMatrix();
        void getElement() const;
        void multiplyMatrices();
        void addMatrices();
        void clearMemory();
    private:
        xMatrix Xmatrix;
};

#endif
