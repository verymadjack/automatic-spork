#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream U1;
    int b=0;
    int i = 0;
    int a = 0;
    int c = 0;
    int ii=0;
    int howMany=1;
    string firstLetter;
    int pages;
    string word;
    int numberOfNames;
    int namesPerPage;
    U1.open("U1.txt");
    U1>>numberOfNames;
    U1>>namesPerPage;
    if(numberOfNames/namesPerPage>0)
    {
        pages=numberOfNames/namesPerPage;
    }
    else if(numberOfNames/namesPerPage<=0)
    {
        pages=0;
    }
    //cout<<pages<<endl;
    string tablica [namesPerPage][pages];
    while(!U1.eof())
    {

        for(;b<pages;b++){i=0;
            for(;i<namesPerPage;i++){
                U1>>tablica[pages][namesPerPage];
                cout<<tablica[pages][namesPerPage];
            }
        }
    }
    while(a != pages && c != namesPerPage)
    {
        for(;b<pages;b++){ii=0;
            for(;i<namesPerPage;i++){
                word=tablica[pages][namesPerPage];
                if(ii!=1){
                firstLetter=word[0];ii++;}
                else if(firstLetter!=word[0]){
                    howMany++;
                }
            }
        }
    }




    //cout<<tablica[0][0];
    return 0;
}
