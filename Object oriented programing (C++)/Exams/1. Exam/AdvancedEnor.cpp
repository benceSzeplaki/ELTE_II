#include "AdvancedEnor.h"

using namespace std;

bool isFileEmpty(ifstream& file)
{
    return file.peek() == ifstream::traits_type::eof();
}

AdvancedEnor::AdvancedEnor(const string &filename)
{
    input.open(filename);
    if(input.fail()) throw NO_MATCHING_FILENAME;
    if(isFileEmpty(input)) throw FILE_IS_EMPTY;
}

AdvancedEnor::~AdvancedEnor()
{
    input.close();
}
ostream& operator<<(ostream& out, Adaption &s)
{
    out << "ID: " << s.ID << endl;
    out << "Date: " << s.date << endl;
    for(unsigned int i = 0; i < s.dogsandowners.size(); i++)
    {
        out << "Name: " << s.dogsandowners[i].ownerFirstName << " " << s.dogsandowners[i].ownerSecondName << endl;
        out << "Dog type: " << s.dogsandowners[i].dogType << endl;
        out << "Dog name: " << s.dogsandowners[i].dogName << endl;
        out << "Age of the dog: "<< s.dogsandowners[i].ageOfDog << endl;
    }
    return out;
}

istream& operator>>(istream &in, Adaption &s)
{
    string line;
    getline(in, line);
    istringstream ss(line);
    s.ID.clear();
    ss >> s.ID;
    s.date.clear();
    ss >> s.date;
    DogsAndOwner x;
    s.dogsandowners.clear();
    while(ss >> x.ownerFirstName>>x.ownerSecondName>>x.dogType>>x.dogName>>x.ageOfDog)
    {
        s.dogsandowners.push_back(x);
    }
    if(s.dogsandowners.size() >= 2)
    {
        s.atLeastTwo = true;
    }
    else
    {
        s.atLeastTwo = false;
    }
    return in;
}

void AdvancedEnor::first()
{
    input >> _cur;
    //cout << _cur;
    st = input.fail() ? abnorm : norm;
    _end = (st == abnorm);
}

void AdvancedEnor::next()
{
    _prev = _cur;
    _end = (st == abnorm);
    if(!end())
    {
        input >> _cur;
        //cout << _cur;
        st = input.fail() ? abnorm : norm;
    }
}
