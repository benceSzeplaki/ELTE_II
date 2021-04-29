#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct DogsAndOwner
{
    std::string ownerFirstName;
    std::string ownerSecondName;
    std::string dogType;
    std::string dogName;
    int ageOfDog;
};

struct Adaption
{
    std::string ID;
    std::string date;
    std::vector<DogsAndOwner> dogsandowners;
    bool atLeastTwo;

    friend std::ostream& operator<<(std::ostream& out, Adaption &s);
    friend std::istream& operator>>(std::istream& in, Adaption &s);
};

class AdvancedEnor
{
    public:
        enum Errors{NO_MATCHING_FILENAME,FILE_IS_EMPTY};
        AdvancedEnor(const std::string &filename);
        ~AdvancedEnor();
        void first();
        void next();
        bool end(){return _end;};
        Adaption current() {return _cur;};
        Adaption prev() {return _prev;};

    private:
        enum Status{abnorm,norm};
        std::ifstream input;
        Status st;
        Adaption _cur;
        Adaption _prev;
        bool _end;
};
