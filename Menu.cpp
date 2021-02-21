#include "Menu.h"

char Menu::wybierzOpcjeZMenuGlownego() {

    char wybor;

    czyscEkran();
    cout << " ===== MENU  GLOWNE ===== " << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

char Menu::wybierzOpcjeZMenuUzytkownika() {

    char wybor;

    czyscEkran();
    cout << " ===== MENU UZYTKOWNIKA ===== " << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

char Menu::wybierzOpcjeZMenuEdycja() {
    char wybor;
    cout << endl << " ===== MENU EDYCJA ===== " << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";

    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}

void Menu::czyscEkran() {

    HANDLE console = GetStdHandle( STD_OUTPUT_HANDLE );
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo( console, & csbi );
    DWORD tmp;
    COORD start = { 0, 0 };
    FillConsoleOutputCharacterA( console, ' ', csbi.dwSize.X * csbi.dwSize.Y, start, & tmp );
    FillConsoleOutputAttribute( console, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, start, & tmp );
    SetConsoleCursorPosition( console, start );
}
