#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;



int main() {

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    ksiazkaAdresowa.wypiszWszystkichUzytkownikow();

    ksiazkaAdresowa.logowanieUzytkownika();

    ksiazkaAdresowa.dodajAdresata();


    ksiazkaAdresowa.wyswietlWszystkichAdresatow();

    ksiazkaAdresowa.wylogowanieUzytkownika();

    return 0;
}



















/*
// testy AdresatMenedzer
#include "AdresatMenedzer.h"
// _testAdresatMen
int _main()
{
    AdresatMenedzer adresatMenedzer.("Adresaci.txt", 2);

    adresatMenedzer.wyswietlWszystkichAdresatow();
    adresatMenedzer.dodajAdresata();
    adresatMenedzer.wyswietlWszystkichAdresatow();
}

*/
/*
// testy PlikZAdresatami
#include "Adresat.h"
#include "PlikZAdresatami.h"
// _testPlikZA
int _main()
{
    PlikZAdresatami plikZAdresatami("Adresaci-test.txt");
    Adresat adresat(1,9,"Janek", "twardowski", "999 888 777", "janek@o2.pl", "ul.Jankowa 3a" )
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    cout << plikZAdresatami.pobierzIdOstatniegoAdresata();
}
*/
