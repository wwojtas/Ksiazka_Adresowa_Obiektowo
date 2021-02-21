#include "AdresatMenedzer.h"


void AdresatMenedzer::dodajAdresata() {

    Adresat adresat;
    Menu::czyscEkran();
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

    Menu::czyscEkran();
    if (!adresaci.empty()) {
        cout << " =========== ADRESACI ===========     " << "\n";
        cout << "               ***                    " << "\n";
        cout << "                *                     " << "\n";
        cout << "               ***                    " << "\n";
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    } else {
        cout << "\n" << "Ksiazka adresowa jest pusta." << "\n" << endl;
    }
    system("pause");
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata() {

    Adresat adresat;

    adresat.ustawIdAdresata((plikZAdresatami.pobierzIdOstatniegoAdresata() + 1) );
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze::wczytajLinie()));

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze::wczytajLinie()));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres( MetodyPomocnicze::wczytajLinie());

    return adresat;
}

void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat) {

    cout << " =========== Adresat =========== " << "\n";
    cout << "Id:                 " << adresat.pobierzIdAdresata() << "\n";
    cout << "Imie:               " << adresat.pobierzImie() << "\n";
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << "\n";
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << "\n";
    cout << "Email:              " << adresat.pobierzEmail() << "\n";
    cout << "Adres:              " << adresat.pobierzAdres() << endl;

}

void AdresatMenedzer::pobierzIdOstatniegoAdresata() {

    plikZAdresatami.pobierzIdOstatniegoAdresata();
}

void AdresatMenedzer::wyswietlIloscWyszukanychAdresatow() {

    if (pobierzIloscAdresatow() == 0)
        cout << "\n" << "W ksiazce adresowej nie ma adresatow z tymi danymi." << "\n";
    else
        cout << "\n" << "Ilosc adresatow w ksiazce adresowej wynosi: " << pobierzIloscAdresatow() << "\n" << endl;
}

int AdresatMenedzer::pobierzIloscAdresatow() {

    return iloscAdresatow;
}

void AdresatMenedzer::wyszukajAdresatowPoImieniu() {

    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    Menu::czyscEkran();
    if (!adresaci.empty()) {
        cout << " =========== WYSZUKIWANIE ADRESATOW O IMIENIU =========== " << "\n" << "\n";

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            if (itr -> pobierzImie() == imiePoszukiwanegoAdresata) {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow();
    } else {
        cout << "\n" << "Ksiazka adresowa jest pusta" << "\n" << "\n";
    }
    cout << endl;
    system("pause");
}

void AdresatMenedzer::wyszukajAdresatowPoNazwisku() {

    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    Menu::czyscEkran();
    if (!adresaci.empty()) {
        cout << " =========== WYSZUKIWANIE ADRESATOW O NAZWISKU =========== " << "\n" << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
            if (itr -> pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata) {
                wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow();
    } else {
        cout << "\n" << "Ksiazka adresowa jest pusta." << "\n" << "\n";
    }
    cout << endl;
    system("pause");
}

int AdresatMenedzer::usunAdresata()
{
    int idUsuwanegoAdresata = 0;
    Menu::czyscEkran();
    cout << " =========== USUWANIE WYBRANEGO ADRESATA =========== " << "\n" << "\n";

    idUsuwanegoAdresata = plikZAdresatami.podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); ++i)
    {
        if (adresaci[i].pobierzIdAdresata() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << "Czy na pewno usunac ? " << "\n";
            cout << " =========== Adresat =========== " << "\n";
            cout << "Id:                 " << adresaci[i].pobierzIdAdresata() << endl;
            cout << "Imie:               " << adresaci[i].pobierzImie() << endl;
            cout << "Nazwisko:           " << adresaci[i].pobierzNazwisko() << endl;
            cout << "Numer telefonu:     " << adresaci[i].pobierzNumerTelefonu() << endl;
            cout << "Email:              " << adresaci[i].pobierzEmail() << endl;
            cout << "Adres:              " << adresaci[i].pobierzAdres() << endl;

            cout << "\n" << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();

            if (znak == 't')
            {
                plikZAdresatami.usunWybranegoAdresataZPliku(idUsuwanegoAdresata);
                adresaci.erase(adresaci.begin() + i);
                cout << "\n" << "\n" << "Szukany adresat zostal USUNIETY" << "\n" << "\n";
                system("pause");
                return idUsuwanegoAdresata;
            }
            else
            {
                cout << "\n" << "\n" << "Wybrany adresat NIE zostal usuniety" << "\n" << "\n";
                system("pause");
                return 0;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << "\n" << "Nie ma takiego adresata w ksiazce adresowej" << "\n" << "\n";
        system("pause");
    }
    return 0;
}


void AdresatMenedzer::edytujAdresata()
{
    Menu::czyscEkran();
    Adresat adresat;
    int idEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";
    cout << " =========== EDYCJA WYBRANEGO ADRESATA =========== " << "\n";

    idEdytowanegoAdresata = plikZAdresatami.podajIdWybranegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzIdAdresata() == idEdytowanegoAdresata)
        {
            czyIstniejeAdresat = true;

            wybor = Menu::wybierzOpcjeZMenuEdycja();

            switch (wybor)
            {
            case '1':
                cout << "Podaj nowe imie: ";

                adresaci[i].ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze::wczytajLinie()));
                plikZAdresatami.zaktualizujDaneWybranegoAdresata( adresaci[i] );
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";

                adresaci[i].ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(MetodyPomocnicze::wczytajLinie()));
                plikZAdresatami.zaktualizujDaneWybranegoAdresata( adresaci[i] );
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";

                adresaci[i].ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.zaktualizujDaneWybranegoAdresata( adresaci[i] );
                break;
            case '4':
                cout << "Podaj nowy email: ";

                adresaci[i].ustawEmail(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.zaktualizujDaneWybranegoAdresata( adresaci[i] );
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";

                adresaci[i].ustawAdres(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.zaktualizujDaneWybranegoAdresata( adresaci[i] );
                break;
            case '6':
                cout << "\n" << "Powrot do menu uzytkownika" << "\n" << "\n";
                break;
            default:
                cout << "\n" << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << "\n" << "\n";
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << "\n" << "Nie ma takiego adresata." << "\n" << "\n";
    }
    system("pause");
}
