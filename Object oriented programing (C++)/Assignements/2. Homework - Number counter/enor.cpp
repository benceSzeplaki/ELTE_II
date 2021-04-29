#include "Enor.h"

using namespace std;

Enor::Enor(const std::string &filename)
{
    _f.open(filename);
    if(_f.fail()) throw FILE_OPEN_ERROR;
}

Enor::Status Enor::read(int &e)
{
    _f >> _i;
    return _f.fail() ? abnorm : norm;
}

void Enor::first()
{
    _st = read(_cur.now);
    if(abnorm == _st) throw FILE_OPEN_ERROR;
    _cur.now = _i;
    next();
}

void Enor::next()
{
    _st=read(_i);
    _end = _st == abnorm;
    if(!_end)
    {
        _cur.before = _cur.now;
        _cur.now = _i;
    }
}

Pairs Enor::current() const
{
    return _cur;
}

bool Enor::end() const
{
    return _end;
}

Enor::Status Enor::getStatus()
{
    return _st;
}