#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikZUzytkownikami.h"
#include "PlikZAdresatami.h"
#include "Menu.h"

using namespace std;

class AdresatMenedzer
 {

    vector <Adresat> adresaci;
    Menu menu;
    PlikZAdresatami plikZAdresatami;
    MetodyPomocnicze metodyPomocnicze;
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    int iloscAdresatow;

    void wyswietlDaneAdresata(Adresat adresat);
    Adresat podajDaneNowegoAdresata();

public:

    AdresatMenedzer(string nazwaPlikuZAdresatami, string nazwaTymczasowegoPlikuZAdresatami, int idZalogowanegoUzytkownika)
        :plikZAdresatami(nazwaPlikuZAdresatami, nazwaTymczasowegoPlikuZAdresatami)
        , ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
        {
            adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        };

    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void pobierzIdOstatniegoAdresata();
    void wyswietlIloscWyszukanychAdresatow();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    int pobierzIloscAdresatow();
    int usunAdresata();




};

#endif
