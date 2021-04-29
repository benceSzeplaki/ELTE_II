#include <iostream>
#include <fstream>
#include "Complex.h"

using namespace std;

bool check(int n)
{
    if(n <= 0 && n <= 5)
    {
        return true;
    }
    else{return false;}
}

void menuOptions()
{
    cout << "0 - Exit form program."<< endl;
    cout << "1 - Read number from file."<< endl;
    cout << "2 - Write read number to console."<< endl;
    cout << "3 - Add up two complex numbers."<< endl;
    cout << "4 - Multiply two complex numbers."<< endl;
    cout << "5 - Divide two complex numbers."<< endl;
}

Complex readFromFile()
{
    int a, b;
    Complex x;
    cout << "Input filename: ";
    string filename; cin >> filename;
    ifstream input(filename);
    if(input.fail()) { cout << "File open error\n"; return x; }
    input >> a >> b;
    x.setComplexReal(a);
    x.setComplexIm(b);
    cout << "The program have stored this number in memory from the input file: ";
    x.printComplex();
    return x;
}

int main()
{
    Complex x;
    Complex y;
    Complex z;
    int a, b;
    int v = 0;
    do
    {
        cout << "\nChoose a menu point:\n";
        menuOptions();
        cout << "Enter menu point number: ";
        cin >> v;
        while(v < 0 || v > 5)
        {
            cout << "You have given invalid menu point number, please give a number between 0 and 5:";
            cin >> v;
        }
        switch(v){
            case 1: x = readFromFile(); break;
            case 2: x.printComplex(); break;
            case 3:
                    if(x.getComplexReal() == 0 && x.getComplexIm() == 0)
                    {
                        a = 0;
                        b = 0;
                        cout << "Please enter a complex number:\nr:";
                        cin >> a;
                        cout << "i:";
                        cin >> b;
                        x.setComplexReal(a);
                        x.setComplexIm(b);
                    }
                    y.setComplexIm(0);
                    y.setComplexReal(0);
                    a = 0;
                    b = 0;
                    cout << "Please enter another complex number:\nr: ";
                    cin >> a;
                    cout << "i: ";
                    cin >> b;
                    cout << endl;
                    y.setComplexReal(a);
                    y.setComplexIm(b);
                    z = x.sum(y);
                    cout << "The sum of the two complex number is: ";
                    z.printComplex();
                    break;
            case 4:
                    if(x.getComplexReal() == 0 && x.getComplexIm() == 0)
                    {
                        a = 0;
                        b = 0;
                        cout << "Please enter a complex number:\nr:";
                        cin >> a;
                        cout << "i:";
                        cin >> b;
                        x.setComplexReal(a);
                        x.setComplexIm(b);
                    }
                    y.setComplexIm(0);
                    y.setComplexReal(0);
                    a = 0;
                    b = 0;
                    cout << "Please enter another complex number:\nr: ";
                    cin >> a;
                    cout << "i: ";
                    cin >> b;
                    cout << endl;
                    y.setComplexReal(a);
                    y.setComplexIm(b);
                    z = x.multiply(y);
                    cout << "The product of the two complex number is: ";
                    z.printComplex();
                break;
            case 5:
                    if(x.getComplexReal() == 0 && x.getComplexIm() == 0)
                    {
                        a = 0;
                        b = 0;
                        cout << "Please enter a complex number:\nr:";
                        cin >> a;
                        cout << "i:";
                        cin >> b;
                        x.setComplexReal(a);
                        x.setComplexIm(b);
                    }
                    y.setComplexIm(0);
                    y.setComplexReal(0);
                    a = 0;
                    b = 0;
                    cout << "Please enter another complex number:\nr: ";
                    cin >> a;
                    cout << "i: ";
                    cin >> b;
                    cout << endl;
                    y.setComplexReal(a);
                    y.setComplexIm(b);
                    z = x.divide(y);
                    cout << "The quotient of the two complex number is: ";
                    z.printComplex();
                break;
        }
    }while(v != 0);
    return 0;
}
