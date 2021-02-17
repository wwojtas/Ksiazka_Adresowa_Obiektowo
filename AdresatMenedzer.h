#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikZUzytkownikami.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdresatMenedzer
 {
    vector <Adresat> adresaci;
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    void wyswietlDaneAdresata(Adresat adresat);
    Adresat podajDaneNowegoAdresata();

    PlikZAdresatami plikZAdresatami;
    MetodyPomocnicze metodyPomocnicze;

public:

    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
        :plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
        {
            adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
        };

    void dodajAdresata();
    void wyswietlWszystkichAdresatow();

    int pobierzZPlikuIdOstatniegoAdresata();

    void ustawIdOstatniegoAdresata(int noweIdOstatniegoAdresata);

};

#endif
