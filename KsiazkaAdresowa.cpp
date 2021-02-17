#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow() {
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();
}

void KsiazkaAdresowa::logowanieUzytkownika() {

    uzytkownikMenedzer.logowanieUzytkownika();
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany()) {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
}

int KsiazkaAdresowa::wylogowanieUzytkownika() {

    uzytkownikMenedzer.wylogowanieUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika() {
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::dodajAdresata() {

    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany() == true) {
        adresatMenedzer -> dodajAdresata();
    } else {
        cout << "Aby dodac kontakt, musisz sie zalogowac ! \n";
        system("pause");
    }

}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany() == true) {
        adresatMenedzer -> wyswietlWszystkichAdresatow();
    } else {
        cout << "Aby wyswietlic kontakty, musisz sie zalogowac ! \n";
        system("pause");
    }
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika() {
    uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika();
}


char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego() {
    menu.wybierzOpcjeZMenuGlownego();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {
    menu.wybierzOpcjeZMenuUzytkownika();
}

int KsiazkaAdresowa::pobierzIdOstatniegoAdresata() {
    adresatMenedzer -> pobierzIdOstatniegoAdresata();
}

