#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int liczba;
    int silnia=1;
    int i=0;
    int t=2;
    cin >> liczba ;
    i=liczba;
    while (liczba!=1)
    {
        silnia=silnia*liczba;
        liczba=liczba-1;
    }
    cout<<silnia<<endl;
    cout<<i<<endl;
    while(silnia>1)
    {
        while(silnia%t==0)
        {
            silnia=silnia/t;
            cout<<t<<"x";
            t++;
        }
    }
    return 0;
}

