#include "UzytkownikMenedzer.h"

void UzytkownikMenedzer::rejestracjaUzytkownika() {

    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika() {

    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login, haslo;
    do {
        cout << endl << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawlogin(login);

    } while ( czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika() {
    if ( uzytkownicy.empty() == true )
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin( string login ) {

    for ( int i = 0; i < uzytkownicy.size(); i++ ) {

        if ( uzytkownicy[i].pobierzLogin() == login ) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow() {

    for ( int i = 0; i < uzytkownicy.size(); i++ ) {
        cout << uzytkownicy[i].pobierzId() << endl;
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
}


int UzytkownikMenedzer::logowanieUzytkownika() {


    string login = "", haslo = "";
    cout << "MENU LOGOWANIA \n";
    cout << "Podaj login: ";
    login = metodyPomocnicze.wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();

    while (itr != uzytkownicy.end()) {
        if (itr -> pobierzLogin() == login) {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--) {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = metodyPomocnicze.wczytajLinie();

                if (itr -> pobierzHaslo() == haslo) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");

                    return idZalogowanegoUzytkownika = itr -> pobierzId();
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika() {


    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = metodyPomocnicze.wczytajLinie();
    for ( int i = 0; i < uzytkownicy.size(); i++ ) {
        if ( uzytkownicy[i].pobierzId() == idZalogowanegoUzytkownika ) {
            uzytkownicy[i].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);

}


int UzytkownikMenedzer::wylogowanieUzytkownika() {

    idZalogowanegoUzytkownika = 0;

    return idZalogowanegoUzytkownika;

}

bool UzytkownikMenedzer::czyUzytkownikJestZalogowany()
{
    if (idZalogowanegoUzytkownika > 0) return true;
    else return false;
}


int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenedzer::ustawIdZalogowanegoUzytkownika(int noweIdZalogowanegoUzytkownika) {

    if(noweIdZalogowanegoUzytkownika >= 0)
    idZalogowanegoUzytkownika = noweIdZalogowanegoUzytkownika;
}

