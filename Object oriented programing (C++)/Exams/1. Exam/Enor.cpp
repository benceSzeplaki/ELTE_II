#include "Enor.h"

using namespace std;

bool isTheFileEmpty(ifstream& file)
{
    return file.peek() == ifstream::traits_type::eof();
}

Enor::Enor(const string &filename)
{
    input.open(filename);
    if(input.fail()) throw NO_MATCHING_FILENAME;
    if(isTheFileEmpty(input)) throw FILE_IS_EMPTY;
}

Enor::~Enor()
{
    input.close();
}
ostream& operator<<(ostream& out, Adaptions &s)
{
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

istream& operator>>(istream &in, Adaptions &s)
{
    string line;
    getline(in, line);
    istringstream ss(line);
    s.date.clear();
    ss >> s.date;
    DogsAndOwners x;
    s.dogsandowners.clear();
    while(ss >> x.ownerFirstName>>x.ownerSecondName>>x.dogType>>x.dogName>>x.ageOfDog)
    {
        s.dogsandowners.push_back(x);
    }
    return in;
}

void Enor::first()
{
    input >> _cur;
    //cout << _cur;
    st = input.fail() ? abnorm : norm;
}

void Enor::next()
{
    _end = (st == abnorm);
    if(!end())
    {
        input >> _cur;
        //cout << _cur;
        st = input.fail() ? abnorm : norm;
    }
}
