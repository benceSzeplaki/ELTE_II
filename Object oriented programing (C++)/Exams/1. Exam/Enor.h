#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct DogsAndOwners
{
    std::string ownerFirstName;
    std::string ownerSecondName;
    std::string dogType;
    std::string dogName;
    int ageOfDog;
};

struct Adaptions
{
    std::string date;
    std::vector<DogsAndOwners> dogsandowners;

    friend std::ostream& operator<<(std::ostream& out, Adaptions &s);
    friend std::istream& operator>>(std::istream& in, Adaptions &s);
};

class Enor
{
    public:
        enum Errors{NO_MATCHING_FILENAME,FILE_IS_EMPTY};
        Enor(const std::string &filename);
        ~Enor();
        void first();
        void next();
        bool end(){return _end;};
        Adaptions current() {return _cur;};

    private:
        enum Status{abnorm,norm};
        std::ifstream input;
        Status st;
        Adaptions _cur;
        bool _end;
};
