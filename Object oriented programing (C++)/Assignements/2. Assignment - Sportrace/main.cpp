#include "StudentEnor.h"
#include "SchoolEnor.h"

using namespace std;

bool firstTask(string filename, Student &theBest)
{
    StudentEnor t(filename);
    bool l = false;
    int Max;
    t.first();
    while(!t.end())
        {
        if(t.current().races >= 3 && l)
        {
            if(t.current().medals > Max)
            {
                Max = t.current().medals;
                theBest = t.current();
            }
        }
        else if(t.current().races >= 3 && !l)
        {
            l = true;
            Max = t.current().medals;
            theBest = t.current();
        }
        t.next();
    }
    return l;
}

bool secondTask(string filename, School &theBest)
{
    bool ret = false;
    SchoolEnor e(filename);
    int Max;
    e.first();
    Max = e.current().medals;
    theBest = e.current();
    e.next();
    while(!e.end())
    {
        if(e.current().medals > Max)
        {
            Max = e.current().medals;
            theBest = e.current();
        }
        e.next();
        ret = true;
    }
    return ret;
}

//#define NORMAL_MODE
#ifdef NORMAL_MODE

int main()
{
    cout << "Give a filename: ";
    string filename;
    cin >> filename;

    cout << "First task: "<<endl;
    Student theBestStudent;
    try
    {
        if(firstTask(filename, theBestStudent))
        {
            if(theBestStudent.medals == 0)
            {
                cout << "Noone won a medal."<<endl;
            }
            else
            {
                for(unsigned int i = 0; i < theBestStudent.name.size(); i++)
                {
                    cout << theBestStudent.name[i];
                    cout << " ";
                }
                cout <<"got the most medals, he entered on " << theBestStudent.races <<" competition(s) and won "<< theBestStudent.medals<< " medals!"<<endl;
            }
        }
        else
        {
            cout << "There was no student, who entered on at least 3 competitions."<<endl;
        }
    }
    catch(StudentEnor::Errors err)
    {
        cerr << "Can't find the input file: " << filename << endl;
    }

    cout << "Second task: "<<endl;
    School theBestSchool;
    try
    {
        if(secondTask(filename, theBestSchool))
        {
            if(theBestSchool.medals == 0)
            {
                cout << "No school has won a medal."<<endl;
            }
            else
            {
                cout << theBestSchool.ID << " school won the most medals. Medals won: " << theBestSchool.medals << endl;
            }
        }
        else{cout << "File is empty!" << endl;}
    }
    catch(SchoolEnor::Errors err)
    {
        cerr << "Can't find the input file: " << filename << endl;
    }
    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

    TEST_CASE("First task - empty file", "test1.txt")
    {
        Student e;
        CHECK_FALSE(firstTask("test1.txt", e));
    }

    TEST_CASE("First task - no students with requirement", "test2.txt")
    {
        Student e;
        CHECK_FALSE(firstTask("test2.txt", e));
    }

    TEST_CASE("First task - 1 student with requirement", "test3.txt")
    {
        Student e;
        CHECK(firstTask("test3.txt", e));
        CHECK(e.name[0] == "Kiss");
        CHECK(e.name[1] == "Adel");
        CHECK(e.medals == 4);
        CHECK(e.races == 4);
    }

    TEST_CASE("First task - more students with requirement", "test4.txt")
    {
        Student e;
        CHECK(firstTask("test4.txt", e));
        CHECK(e.name[0] == "Jo");
        CHECK(e.name[1] == "Robert");
        CHECK(e.medals == 4);
        CHECK(e.races == 5);
    }

    TEST_CASE("First task - 1 student in file, no requirements", "test5.txt")
    {
        Student e;
        CHECK_FALSE(firstTask("test5.txt",e));
    }

    TEST_CASE("First task - 1 student in file, good requirements", "test6.txt")
    {
        Student e;
        CHECK(firstTask("test6.txt",e));
        CHECK(e.name[0] == "Kiss");
        CHECK(e.name[1] == "Adel");
        CHECK(e.races == 4);
        CHECK(e.medals == 3);
    }
    TEST_CASE("First task - more students, first one is maximum", "test7.txt")
    {
        Student e;
        CHECK(firstTask("test7.txt", e));
        CHECK(e.name[0] == "Soos");
        CHECK(e.name[1] == "Peter");
        CHECK(e.name[2] == "Pal");
        CHECK(e.medals == 5);
        CHECK(e.races == 5);
    }

    TEST_CASE("First task - more students, third one is maximum", "test8.txt")
    {
        Student e;
        CHECK(firstTask("test8.txt", e));
        CHECK(e.name[0] == "Soos");
        CHECK(e.name[1] == "Peter");
        CHECK(e.name[2] == "Pal");
        CHECK(e.medals == 5);
        CHECK(e.races == 5);
    }

    TEST_CASE("First task - more students, last one is maximum", "test9.txt")
    {
        Student e;
        CHECK(firstTask("test9.txt", e));
        CHECK(e.name[0] == "Soos");
        CHECK(e.name[1] == "Peter");
        CHECK(e.name[2] == "Pal");
        CHECK(e.medals == 5);
        CHECK(e.races == 5);
    }

    TEST_CASE("First task - more students in file, noone won medals", "test11.txt")
    {
        Student e;
        CHECK(firstTask("test11.txt",e));
        CHECK(e.medals == 0);
    }

    TEST_CASE("Second task - empty file", "test1.txt")
    {
        School e;
        CHECK_FALSE(secondTask("test1.txt", e));
    }

    TEST_CASE("Second task - 1 student in file", "test6.txt")
    {
        School e;
        CHECK(secondTask("test6.txt",e));
        CHECK(e.ID == "8600VakB");
        CHECK(e.medals == 3);
        CHECK(e.medalsOfStudent == e.medals);
    }

    TEST_CASE("Second task - 2 students in file, same school", "test2.txt")
    {
        School e;
        CHECK(secondTask("test2.txt",e));
        CHECK(e.ID == "8600VakB");
        CHECK(e.medals == 3);
    }

    TEST_CASE("Second task - 2 students in file, not the same school", "test10.txt")
    {
        School e;
        CHECK(secondTask("test10.txt",e));
        CHECK(e.ID == "6800Lorincz");
        CHECK(e.medals == 3);
    }

    TEST_CASE("Second task - more students in file, noone won medals", "test11.txt")
    {
        School e;
        CHECK(secondTask("test11.txt",e));
        CHECK(e.medals == 0);
    }


#endif
