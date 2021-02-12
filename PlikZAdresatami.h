#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Adresat.h"
#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class PlikZAdresatami {

    const string nazwaPlikuZAdresatami;
    vector <Adresat> adresaci;
    int idZalogowanegoUzytkownika;
    bool czyPlikJestPusty();
    MetodyPomocnicze metodyPomocnicze;
    PlikZUzytkownikami plikZUzytkownikami;

public:

    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI)   : nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI) {};
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku();

    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
};

#endif
