#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctype.h>
#include <fstream>

using namespace std;

class MetodyPomocnicze {

public:

    static string konwerjsaIntNaString(int liczba);
    int konwersjaStringNaInt(string liczba);
    char wczytajZnak();
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    string wczytajLinie();

};

#endif
