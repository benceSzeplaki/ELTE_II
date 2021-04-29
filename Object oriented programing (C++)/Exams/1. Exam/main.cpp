#include <Enor.h>
#include <AdvancedEnor.h>

using namespace std;

bool felt(Adaptions elem)
{
    bool ret = false;
    int counter = 0;
    for(unsigned int i = 0; i < elem.dogsandowners.size(); i++)
    {
        if(elem.dogsandowners[i].dogType == "labrador" && elem.dogsandowners[i].ageOfDog >= 2)
        {
            ret = true;
        }
        else
        {
            ret = false;
            if(elem.dogsandowners[i].dogType == "labrador")
            {
                counter++;
            }
        }
    }
    if(counter != 0)
    {
        ret = false;
    }
    return ret;
}

bool felt2(Adaption c, Adaption p)
{
    bool ret = false;
    bool l = true;
    if(c.ID == p.ID)
    {
        if(c.atLeastTwo == true && p.atLeastTwo == true)
        {
            l = true;
        }
        else
        {
            l = false;
        }
        ret = l;
    }
    else
    {
        if(c.atLeastTwo == true)
        {
            l = true;
        }
        else
        {
            l = false;
        }
        ret = l;
    }
    return ret;
}

bool first_task(string filename, Adaptions &elem)
{
    Enor t(filename);
    bool l = false;
    t.first();
    while(!t.end() && !l)
    {
        elem = t.current();
        l = felt(elem);
        t.next();
    }
    return l;
}

int main()
{
    string filename = "input.txt";
    Adaptions elem;
    try
    {
        if(first_task(filename, elem) == true)
        {
            cout <<"Ezen a napon az osszes labrador legalabb 2 eves volt:  "<< elem.date << endl;
        }
        else
        {
            cout <<"Nem volt olyan nap, amin az osszes labrador legalabb 2 eves lett volna!" << endl;
        }
    }
    catch(Enor::Errors err)
    {
        if(err == 0)
        {
            cerr << "Can't find the input file: " << filename << endl;
        }
        if(err == 1)
        {
            cerr << "The file you have given ("<< filename <<") is empty!"<<endl;
        }
    }
    filename = "input2.txt";
    Adaption c, p;
    string IDs;
    try
    {
        AdvancedEnor t(filename);
        bool l;
        t.first();
        if(t.end() == true)
        {
            c = t.current();
            if(c.atLeastTwo == true)
            {
                cout << c.ID <<endl;
            }
            else
            {
                cout << "Nem volt olyan intézmény, ahol minden nap 2 kutyat fogadtak volna orokbe."<<endl;
            }
        }
        else
        {
            t.next();
            while(!t.end())
            {
                c = t.current();
                p = t.prev();
                l = felt2(c,p);
                if(l == true)
                {
                    if(c.ID != p.ID)
                    {
                        IDs.append(c.ID);
                        IDs.append(" ");
                    }
                }
                t.next();
            }
        }
        if(IDs == "")
        {
            cout << "Nem volt olyan menhely, ahol tobb mint 2 orokbefogadas tortent volna minden nap."<<endl;
        }
        else
        {
            cout << "Ezeken a menhelyeken minden nap tobb mint 2 orokbefogadas tortent: "<< IDs << endl;
        }
    }
    catch(AdvancedEnor::Errors err)
    {
        if(err == 0)
        {
            cerr << "Can't find the input file: " << filename << endl;
        }
        if(err == 1)
        {
            cerr << "The file you have given ("<< filename <<") is empty!"<<endl;
        }
    }
    return 0;
}
