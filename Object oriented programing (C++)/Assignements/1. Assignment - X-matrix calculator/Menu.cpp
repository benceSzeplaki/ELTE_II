#include "Menu.h"
#include <iostream>
#include "xMatrix.h"
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void Menu::run()
{
    int menuPoint;
    xMatrix X;
    do
    {
        writeMenuPoints();
        menuPoint = selectMenuPoint();
    }while(menuPoint != 0);
}
void Menu::writeMenuPoints()
{
    cout << endl;
    cout << "Menu points: "<<endl;
    cout << "0. - Exit from the program."<<endl;
    cout << "1. - Add matrix to memory."<<endl;
    cout << "2. - Print matrix in memory."<<endl;
    cout << "3. - Clear memory." << endl;
    cout << "4. - Print a given element of matrix in memory."<<endl;
    cout << "5. - Add up matrices."<< endl;
    cout << "6. - Multiply matrices."<< endl;
    cout << "-----------------------------------------------"<<endl;
    cout << "Give a menu point number: ";
}
int Menu::selectMenuPoint()
{
        int menuPoint;
        cin >> menuPoint;
        if(menuPoint < 0 || menuPoint > 6)
        {
            cout << "! INVALID MENU POINT NUMBER !" << endl << "Please give a number between 0 - 6!"<<endl;
        }
        cout << endl;
        switch (menuPoint)
        {
            case 1:
                readMatrix();
                break;
            case 2:
                writeMatrix();
                break;
            case 3:
                clearMemory();
                break;
            case 4:
                getElement();
                break;
            case 5:
                addMatrices();
                break;
            case 6:
                multiplyMatrices();
                break;
        }
        return menuPoint;
}

void Menu::readMatrix()
{
    cout << "Give the size (N) of the matrix (NxN) and then give the elements of the matrix from left to right row-by-row (without 0 elements): ";
    try
    {
        cin >> Xmatrix;
    }
    catch(xMatrix::Exceptions ex)
    {
        if(ex == xMatrix::OVERINDEXED)
        {
            cout << "Overindexed!";
        }
        else if(ex == xMatrix::NULLPART)
        {
            cout << "Nullpart!";
        }
    }
}
void Menu::writeMatrix()
{
    cout << Xmatrix << endl;
}
void Menu::getElement() const
{
    int i,j;
    cout << "Give the index of the row: ";
    cin >> i;
    cout << "Give the index of the column: ";
    cin >> j;
    try
    {
        cout << "The searched element is: Matrix[ " << i << " , " << j << " ] = " << Xmatrix(i-1,j-1) << endl;
    }
    catch(xMatrix::Exceptions ex)
    {
        if(ex == xMatrix::OVERINDEXED)
            cout << "Overindexing!" << endl;
        else
            cout << "Unhandled ecxeption!" << endl;
    }
}
void Menu::addMatrices()
{
    try
    {
        xMatrix b;
        cout << "Give the size and the items of the second  matrix: " << endl;
        cin >> b;
        cout << "Sum of the matrices: " << endl;
        cout << Xmatrix + b << endl;
    }
    catch(xMatrix::Exceptions ex)
    {
        if(ex == xMatrix::DIFFERENT)
        {
            cout << "Different sizes!" << endl;
        }
    }
}
void Menu::multiplyMatrices()
{
    try
    {
        xMatrix b;
        cout << "Give the size and the items of the second  matrix: " << endl;
        cin >> b;
        cout << "Product of the matrices: " << endl;
        cout << Xmatrix * b << endl;
    }
    catch(xMatrix::Exceptions ex)
    {
        if(ex == xMatrix::DIFFERENT)
        {
            cout << "Different sizes!" << endl;
        }
    }
}
void Menu::clearMemory()
{
    Xmatrix.reSize(0);
    cout << "The memory has been cleared."<<endl;
}
