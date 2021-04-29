#include "SchoolEnor.h"

using namespace std;

SchoolEnor::SchoolEnor(const string &filename)
{
    input.open(filename);
    if(input.fail()) throw NO_MATCHING_FILENAME;
}

SchoolEnor::~SchoolEnor()
{
    input.close();
}

bool noNumber(const std::string &c)
{
    if (c.find('0') != std::string::npos ||
        c.find('1') != std::string::npos ||
        c.find('2') != std::string::npos ||
        c.find('3') != std::string::npos ||
        c.find('4') != std::string::npos ||
        c.find('5') != std::string::npos ||
        c.find('6') != std::string::npos ||
        c.find('7') != std::string::npos ||
        c.find('8') != std::string::npos ||
        c.find('9') != std::string::npos)
    {
        return false;
    }

    return true;
}

std::ostream& operator<<(ostream& out, School& s)
{
    out << "Name: ";
    for(int i = 0; i < s.name.size(); i++)
    {
        out << s.name[i];
        out << " ";
    }
    out << endl <<"Shcool ID: " << s.ID << endl << "Races: "<< endl;
    for(int i = 0; i < s.achivements.size(); i++)
    {
        out << s.achivements[i].category << ": " << s.achivements[i].place << ". place"<<endl;
    }
    out << "Medals won: "<< s.medals << endl;
    return out;
}

std::istream& operator>>(std::istream &in, School &s)
{
    string line;
    getline(in, line);
    istringstream ss(line);
    string str;
    s.name.clear();
    s.ID.clear();
    while(!ss.fail())
    {
        ss >> str;
        if(noNumber(str))
        {
            s.name.push_back(str);
        }
        else
        {
            s.ID = str;
            break;
        }
    }
    Competition x;
    s.achivements.clear();
    while(ss >> x.category >> x.place){s.achivements.push_back(x);}
    s.medalsOfStudent = 0;
    for(int i = 0; i < s.achivements.size(); i++)
    {
        if(s.achivements[i].place <= 3)
        {
            s.medalsOfStudent = s.medalsOfStudent + 1;
        }
    }
    s.medals = s.medalsOfStudent;
    return in;
}

void SchoolEnor::first()
{
    input >> _cur;
    st = input.fail() ? abnorm : norm;
}

void SchoolEnor::next()
{
    _prev = _cur;
    _end = (st == abnorm);
    if(!end())
    {
        input >> _cur;
        st = input.fail() ? abnorm : norm;
        if(_prev.ID == _cur.ID)
        {
            _cur.medals = _cur.medals + _prev.medals;
        }
    }
}
