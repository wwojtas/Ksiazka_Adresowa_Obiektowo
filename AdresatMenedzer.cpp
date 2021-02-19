#include "AdresatMenedzer.h"


void AdresatMenedzer::dodajAdresata() {

    Adresat adresat;
    menu.czyscEkran();
    cout << " =========== DODAWANIE NOWEGO ADRESATA =========== \n\n";
    adresat = podajDaneNowegoAdresata();
    adresaci.push_back(adresat);

    if (plikZAdresatami.dopiszAdresataDoPliku(adresat))
        cout << "Nowy adresat zostal dodany \n";
    else
        cout << "Blad. Nie udalo sie dodac nowego adresata do pliku. \n";
    system("pause");
}

void AdresatMenedzer::wyswietlWszystkichAdresatow() {

    menu.czyscEkran();
    if (!adresaci.empty()) {
        cout << "============= ADRESACI ==============  " << endl;
        cout << "                ***                    " << endl;
        cout << "                 *                     " << endl;
        cout << "                ***                    " << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata() {

    Adresat adresat;

    adresat.ustawIdAdresata((plikZAdresatami.pobierzIdOstatniegoAdresata() + 1) );
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

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

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat) {

    cout << "=========== Adresat =========== " << endl;
    cout << "Id:                 " << adresat.pobierzIdAdresata() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;

}

void AdresatMenedzer::pobierzIdOstatniegoAdresata() {
    plikZAdresatami.pobierzIdOstatniegoAdresata();
}

void AdresatMenedzer::wyswietlIloscWyszukanychAdresatow() {

    if (pobierzIloscAdresatow() == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << pobierzIloscAdresatow() << endl << endl;
}

int AdresatMenedzer::pobierzIloscAdresatow() {
    return iloscAdresatow;
}

void AdresatMenedzer::wyszukajAdresatowPoImieniu() {

    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    menu.czyscEkran();
    if (!adresaci.empty()) {
        cout << "=========== WYSZUKIWANIE ADRESATOW O IMIENIU ===========" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = metodyPomocnicze.wczytajLinie();
        imiePoszukiwanegoAdresata = metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            if (itr -> pobierzImie() == imiePoszukiwanegoAdresata) {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow();
    } else {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer::wyszukajAdresatowPoNazwisku() {

    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    menu.czyscEkran();
    if (!adresaci.empty()) {
        cout << "=========== WYSZUKIWANIE ADRESATOW O NAZWISKU ===========" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = metodyPomocnicze.wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = metodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            if (itr -> pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata) {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow();
    } else {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}

int AdresatMenedzer::usunAdresata()
{
    int idUsuwanegoAdresata = 0;
    menu.czyscEkran();
    cout << " =========== USUWANIE WYBRANEGO ADRESATA =========== " << endl << endl;

    idUsuwanegoAdresata = plikZAdresatami.podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); ++i)
    {
        if (adresaci[i].pobierzIdAdresata() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << "Czy na pewno usunac ? " << endl;
            cout << " =========== Adresat =========== " << endl;
            cout << "Id:                 " << adresaci[i].pobierzIdAdresata() << endl;
            cout << "Imie:               " << adresaci[i].pobierzImie() << endl;
            cout << "Nazwisko:           " << adresaci[i].pobierzNazwisko() << endl;
            cout << "Numer telefonu:     " << adresaci[i].pobierzNumerTelefonu() << endl;
            cout << "Email:              " << adresaci[i].pobierzEmail() << endl;
            cout << "Adres:              " << adresaci[i].pobierzAdres() << endl;

            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = metodyPomocnicze.wczytajZnak();

            if (znak == 't')
            {
                plikZAdresatami.usunWybranegoAdresataZPliku(idUsuwanegoAdresata);
                adresaci.erase(adresaci.begin() + i);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                return idUsuwanegoAdresata;
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
                return 0;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
    return 0;
}



