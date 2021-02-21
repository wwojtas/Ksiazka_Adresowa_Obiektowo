#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikZUzytkownikami.h"
#include "PlikTestowy.h"

using namespace std;

class PlikZAdresatami :public PlikTestowy {

    const string NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI;
    int idZalogowanegoUzytkownika;

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

public:

    PlikZAdresatami(string nazwaPliku, string nazwaTymczasowegoPlikuZAdresatami)
    : PlikTestowy(nazwaPliku)
    , NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI(nazwaTymczasowegoPlikuZAdresatami)
    {
        idOstatniegoAdresata = 0;
    };

    int idOstatniegoAdresata;
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    bool dopiszAdresataDoPliku( Adresat adresat);
    int pobierzIdOstatniegoAdresata();
    int usunWybranegoAdresataZPliku (int idUsuwanegoAdresata);
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);
    int podajIdWybranegoAdresata();
    void zaktualizujDaneWybranegoAdresata( Adresat adresat );
};

#endif
