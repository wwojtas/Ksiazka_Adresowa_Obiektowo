#include "AdresatMenedzer.h"


int AdresatMenedzer::dodajAdresata() {
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    dopiszAdresataDoPliku();

    return ++idOstatniegoAdresata;
}

void AdresatMenedzer::wyswietlWszystkichAdresatow() {

    system("cls");
    if (!adresaci.empty()) {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            wyswietlDaneAdresata();
        }
        cout << endl;
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata() {
    Adresat adresat;

    adresat.ustawIdAdresata(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    cout << "Podaj imie: ";
    adresat.ustawImie(metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(metodyPomocnicze.wczytajLinie()));

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(metodyPomocnicze.wczytajLinie()));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(metodyPomocnicze.wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(metodyPomocnicze.wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres( metodyPomocnicze.wczytajLinie());

    return adresat;
}

void AdresatMenedzer::dopiszAdresataDoPliku() {
    Adresat adresat;
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true) {
        liniaZDanymiAdresata = plikZAdresatami.zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (plikZAdresatami.czyPlikJestPusty() == true) {
            plikTekstowy << liniaZDanymiAdresata;
        } else {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
    } else {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    plikTekstowy.close();
    system("pause");
}

void AdresatMenedzer::wyswietlDaneAdresata() {
    cout << "Id:         "         << adresat.pobierzIdAdresata() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

int AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku() {
    idOstatniegoAdresata = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}
