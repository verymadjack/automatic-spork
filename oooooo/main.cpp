#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

//void getUniqueLetters(array names, int resultsPerPage, int currentPage) {
//}

int main()
{
    int amount = 0;
    int resultsPerPage = 0;
    int readIterator = 0;
    int one = 0;

    fstream U1;
    U1.open("U1.txt");
    // wczytujemy ile jest osob na liscie
    U1 >> amount;
    // wczytujemy wielkosc strony
    U1 >> resultsPerPage;
    string names[amount];
    string letters;
    int mostUniqueLetters = 0;

    // czytamy linijka po linijce
    while(!U1.eof())
    {
        // wrzucamy imiona do tablicy
        U1 >> names[readIterator];
        readIterator++;
    }

    // liczymy ile mamy stron na podstawie
    int totalPages = ceil(amount / resultsPerPage);

    // idziemy po stronach
    for (int i = 0; i <= totalPages; i++) {
        string uniqueLettersOnPage = "";
        //zaczynamy od pozycji ilosc_stron * ilosc_wynikow_na_stronie
        int start = i * resultsPerPage;
        // element ostatni na stronie element_start + ilosc_wynikow_na_stronie - 1
        int endElem = start + resultsPerPage;

        // jezeli ostatni element jest spoza tablicy, ustaw wielkosc tablicy jako ostani element
        if (endElem >= amount) {
            endElem = amount;
        }

        // idziemy po tablicy imion, korzystajac z wyliczonych indeksow start i koniec
        for (int j = start; j < endElem; j++) {
            // jezeli nie mamy jeszcze zadnych unikalnych liter - przypisujemy paktualna litera
            if (uniqueLettersOnPage == "") {
                // bierzemy pierwsza litere imienia
                uniqueLettersOnPage = names[j][0];
            } else { // jezeli juz mamy unikalna litera, sprawdzmy czy aktualna litera wystepuje czy nie
                // zakladamy, ze aktualna litera jest unikalna
                bool isUnique = true;
                // sprawdzamy wszystkie litery po kolei
                for (int k = 0; k < uniqueLettersOnPage.length(); k++ ) {
                    // jezeli chociaz raz litera wystapi na stronie, to ustawiamy, ze nie jest unikalna
                    if (uniqueLettersOnPage[k] == names[j][0]) {
                        isUnique = false;
                    }
                }
                // jezeli litera nie wystapila nigdy - jest unikalna, dodajemy do listy unikalnych liter
                if (isUnique) {
                    uniqueLettersOnPage += names[j][0];
                }
            }
        }
        // tutaj kod, ktory wystepuje, jak przeszlismy przez cala strone

        // jezeli dotychczasowa ilosc unikalnych liter jest mniejsza niz unikalne litery na tej stronie, nadpisz zmienna
        if (mostUniqueLetters < uniqueLettersOnPage.length()) {
            mostUniqueLetters = uniqueLettersOnPage.length();
        }
    }

    cout << mostUniqueLetters;
    return 0;
}
