#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikZUzytkownikami.h"
#include "PlikZAdresatami.h"

using namespace std;


class AdresatMenedzer {

    vector <Adresat> adresaci;
    string nazwaPlikuZAdresatami = "Adresaci.txt";
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;

    Adresat adresat;
    MetodyPomocnicze metodyPomocnicze;
    PlikZAdresatami plikZAdresatami;
    PlikZUzytkownikami plikZUzytkownikami;

public:

    AdresatMenedzer(string nazwaPlikuZAdresatami)
        :plikZAdresatami(nazwaPlikuZAdresatami) {
    };

    int dodajAdresata();
    void wyswietlWszystkichAdresatow();
    int wczytajAdresatowZalogowanegoUzytkownikaZPliku();

    Adresat podajDaneNowegoAdresata();
    void dopiszAdresataDoPliku();
    void wyswietlDaneAdresata();

};


#endif
