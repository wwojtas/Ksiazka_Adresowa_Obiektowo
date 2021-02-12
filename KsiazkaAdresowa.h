#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"

using namespace std;

class KsiazkaAdresowa {

    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer adresatMenedzer;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami)
        : uzytkownikMenedzer(nazwaPlikuZUzytkownikami)  {
        uzytkownikMenedzer.wczytajUzytkownikowZPliku();
    };
    KsiazkaAdresowa(string nazwaPlikuZAdresatami)
        : adresatMenedzer(nazwaPlikuZAdresatami) {
        adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku();;
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();

    /** WPROWADZONE ZMIANY ***/

    int logowanieUzytkownika();
    int wylogowanieZalogowanegoUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
};

#endif
