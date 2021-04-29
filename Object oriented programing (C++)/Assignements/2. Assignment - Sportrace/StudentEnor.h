#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

struct Race
{
    std::string category;
    int place;
};
struct Student
{
    std::vector<std::string> name;
    std::string ID;
    std::vector<Race> achivements;

    friend std::istream& operator>>(std::istream& in, Student &s);
    friend std::ostream& operator<<(std::ostream& out, Student &s);

    int medals = 0;
    int races = 0;
};
class StudentEnor
{
    public:
        enum Errors{NO_MATCHING_FILENAME};
        StudentEnor(const std::string &filename);
        ~StudentEnor();
        void first();
        void next();
        bool end(){return _end;};
        Student current() {return _cur;};
    private:
        enum Status{abnorm,norm};
        std::ifstream input;
        Status st;
        Student _cur;
        bool _end;
};
