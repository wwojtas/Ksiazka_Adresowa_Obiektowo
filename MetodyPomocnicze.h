#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctype.h>

using namespace std;

class MetodyPomocnicze {
public:
    static string konwerjsaIntNaString(int liczba);

    /** WPROWADZONE ZMIANY ***/

    string wczytajLinie();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    int konwersjaStringNaInt(string liczba);
};

#endif
