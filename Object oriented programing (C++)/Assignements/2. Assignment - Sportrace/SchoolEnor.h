#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

struct Competition
{
    std::string category;
    int place;
};
struct School
{
    std::vector<std::string> name;
    std::string ID;
    std::vector<Competition> achivements;
    friend std::istream& operator>>(std::istream& in, School &s);
    friend std::ostream& operator<<(std::ostream& out, School &s);
    int medalsOfStudent = 0;
    int medals = 0;
};

class SchoolEnor
{
    public:
        enum Errors{NO_MATCHING_FILENAME};
        SchoolEnor(const std::string &filename);
        ~SchoolEnor();
        void first();
        void next();
        bool end(){return _end;};
        School current() {return _cur;};
        School previous() {return _prev;};

    private:
        enum Status{abnorm,norm};
        std::ifstream input;
        Status st;
        School _cur;
        School _prev;
        bool _end;
};
