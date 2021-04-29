#include <iostream>
#include <fstream>
#include "Enor.h"

using namespace std;

int main(int argc, char const *argv[])
{
	char const * filename="input.txt";
    if(argc == 2)
    {
        filename = argv[1];
    }
    Enor list(filename);
    Pairs x;
    int counter = 1;
    list.first();
    x = list.current();
    while(!list.end())
    {
    	if(x.before == x.now)
    	{
    		counter++;
    	}
    	else
    	{
    		cout << x.before << " " << counter << endl;
    		counter = 1;
    	}
    	list.next();
    	if(list.getStatus() == 0)
    	{
    		cout << x.now << " " << counter << endl;
    	}
    	x = list.current();
    }
	return 0;
}