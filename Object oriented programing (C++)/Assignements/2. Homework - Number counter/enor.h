#pragma once

#include <fstream>

struct Pairs
{
    int before;
    int now;
};

class Enor
{
private:
    enum Status{abnorm,norm};
    std::ifstream _f;
    Status _st;
    bool _end;
    Pairs _cur;
    int _i;

public:
    enum Error{FILE_OPEN_ERROR};
    Enor(const std::string &filename);
    void first();
    void next();
    Pairs current() const;
    bool end() const;
    Status getStatus();
    Status read(int &e);

};