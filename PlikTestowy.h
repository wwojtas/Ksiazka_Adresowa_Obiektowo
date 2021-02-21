#ifndef PLIKTESTOWY_H
#define PLIKTESTOWY_H

#include <iostream>
#include <fstream>


using namespace std;

class PlikTestowy {

    const string NAZWA_PLIKU;

public:

    PlikTestowy(string nazwaPliku)
        : NAZWA_PLIKU(nazwaPliku)
    {}
    string pobierzNazwePliku();
    bool czyPlikJestPusty(string);
};

#endif
