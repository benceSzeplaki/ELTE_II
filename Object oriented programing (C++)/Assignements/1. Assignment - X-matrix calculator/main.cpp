#include <iostream>
#include "Menu.h"
#include "xMatrix.h"
#include <iomanip>
#include "read.hpp"
#include <fstream>
#include <string>

#define NORMAL_MODE
#ifdef NORMAL_MODE
using namespace std;

int main()
{
    Menu m;
    m.run();
    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Menu.h"
#include "xMatrix.h"

using namespace std;

TEST_CASE("create", "inp.txt")
{
    const string fileName = "inp.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }
    xMatrix c;
    in >> c;
    CHECK(c(0,0) == 1);
    CHECK(c(1,1) == 2);
    CHECK(c(2,2) == 3);
    CHECK(c(2,0) == 5);
    CHECK(c(0,2) == 4);
}

TEST_CASE("copy constructor", "inp.txt")
{
    const string fileName = "inp.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    xMatrix a;
    in >> a;

    xMatrix b = a;

    CHECK(a(0,0) == b(0,0));
    CHECK(a(1,1) == b(1,1));
    CHECK(a(2,2) == b(2,2));
    CHECK(a(0,2) == b(0,2));
    CHECK(a(2,0) == b(2,0));
}

TEST_CASE("assignment operator", "inp.txt")
{
    const string fileName = "inp.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    xMatrix a, b;
    in >> a;

    b = a;
    CHECK(a(0,0) == b(0,0));
    CHECK(a(1,1) == b(1,1));
    CHECK(a(2,2) == b(2,2));
    CHECK(a(0,2) == b(0,2));
    CHECK(a(2,0) == b(2,0));

    xMatrix c;
    c = b = a;
    CHECK(a(0,0) == c(0,0));
    CHECK(a(1,1) == c(1,1));
    CHECK(a(2,2) == c(2,2));
    CHECK(a(0,2) == c(0,2));
    CHECK(a(2,0) == c(2,0));

    a = a;
    CHECK(a(0,0) == 1);
    CHECK(a(1,1) == 2);
    CHECK(a(2,2) == 3);
    CHECK(a(0,2) == 4);
    CHECK(a(2,0) == 5);
}

TEST_CASE("add", "inp2.txt")
{
    const string fileName = "inp2.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    xMatrix a, b, c, d, f;
    in >> a >> b;

    c = a + b;
    CHECK(c(0,0) == 6);
    CHECK(c(1,1) == 6);
    CHECK(c(2,2) == 6);
    CHECK(c(2,0) == 6);
    CHECK(c(0,2) == 6);

    d = b + a;
    CHECK(d(0,0) == c(0,0));
    CHECK(d(1,1) == c(1,1));
    CHECK(d(2,2) == c(2,2));
    CHECK(d(0,2) == c(0,2));
    CHECK(d(2,0) == c(2,0));

    d = (a + b) + c;
    f = a + (b + c);
    CHECK(d(0,0) == f(0,0));
    CHECK(d(1,1) == f(1,1));
    CHECK(d(2,2) == f(2,2));
    CHECK(d(0,2) == f(0,2));
    CHECK(d(2,0) == f(2,0));
}

TEST_CASE("multiply", "inp2.txt")
{
    const string fileName = "inp2.txt";

    ifstream in(fileName.c_str());
    if(in.fail())
    {
        cout << "File name error!" << endl;
        exit(1);
    }

    xMatrix a, b, c, d, f;
    in >> a >> b;

    c = a * b;
    CHECK(c(0,0) == 9);
    CHECK(c(1,1) == 9);
    CHECK(c(2,2) == 21);
    CHECK(c(0,2) == 6);
    CHECK(c(2,0) == 30);

    d = b * a;
    CHECK(d(0,0) == c(2,2));
    CHECK(d(1,1) == c(1,1));
    CHECK(d(2,2) == c(0,0));
    CHECK(d(0,2) == c(2,0));
    CHECK(d(2,0) == c(0,2));

    d = (a * b) * c;
    f = a * (b * c);
    CHECK(d(0,0) == f(0,0));
    CHECK(d(1,1) == f(1,1));
    CHECK(d(2,2) == f(2,2));
    CHECK(d(0,2) == f(0,2));
    CHECK(d(2,0) == f(2,0));

}
#endif
