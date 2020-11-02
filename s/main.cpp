#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;


int main()
{
    int amount = 0;
    int resultsPerPage = 0;
    int readIterator = 0;
    int one = 0;

    fstream U1;
    U1.open("U1.txt");
    U1 >> amount;
    U1 >> resultsPerPage;
    string names[amount];
    string letters;
    int mostUniqueLetters = 0;

    while(!U1.eof())
    {
        U1 >> names[readIterator];
        readIterator++;
    }

    int totalPages = ceil(amount / resultsPerPage);

    for (int i = 0; i <= totalPages; i++) {
        string uniqueLettersOnPage = "";
        int start = i * resultsPerPage;
        int endElem = start + resultsPerPage;

        if (endElem >= amount) {
            endElem = amount;
        }

        for (int j = start; j < endElem; j++) {
            if (uniqueLettersOnPage == "") {
                uniqueLettersOnPage = names[j][0];
            } else {
                bool isUnique = true;
                for (int k = 0; k < uniqueLettersOnPage.length(); k++ ) {
                    if (uniqueLettersOnPage[k] == names[j][0]) {
                        isUnique = false;
                    }
                }
                if (isUnique) {
                    uniqueLettersOnPage += names[j][0];
                }
            }
        }

        if (mostUniqueLetters < uniqueLettersOnPage.length()) {
            mostUniqueLetters = uniqueLettersOnPage.length();
        }
    }

    cout << mostUniqueLetters;
    return 0;
}
