#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main() {

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt", "Adresaci.txt");

    char wybor;

    while (true) {
        if (ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika() == 0) {
            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuGlownego();

            switch (wybor) {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else if (ksiazkaAdresowa.pobierzIdZalogowanegoUzytkownika() > 0) {

            wybor = ksiazkaAdresowa.wybierzOpcjeZMenuUzytkownika();

            switch (wybor) {
            case '1':
                ksiazkaAdresowa.dodajAdresata();
                ksiazkaAdresowa.pobierzIdOstatniegoAdresata();
                break;
            case '2':
                ksiazkaAdresowa.wyszukajAdresatowPoImieniu();
                break;
            case '3':
                ksiazkaAdresowa.wyszukajAdresatowPoNazwisku();
                break;
            case '4':
                ksiazkaAdresowa.wyswietlWszystkichAdresatow();
                break;
            case '5':
                //  idUsunietegoAdresata = usunAdresata(adresaci);
                //   idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
                //  edytujAdresata(adresaci);
                break;
            case '7':
                ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                ksiazkaAdresowa.wylogowanieUzytkownika();
                break;
            }
        }
    }
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
