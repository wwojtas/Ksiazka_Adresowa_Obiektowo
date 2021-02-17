#include "PlikTestowy.h"


bool PlikTestowy::czyPlikJestPusty(string nazwaPlikuTestowego)
{
    bool pusty = true;

    fstream plikTekstowy;
    plikTekstowy.open(nazwaPlikuTestowego.c_str(), ios::app);

    if (plikTekstowy.good() == true)
    {
        plikTekstowy.seekg(0, ios::end);
        if (plikTekstowy.tellg() != 0)
            pusty = false;
    }

    plikTekstowy.close();
    return pusty;
}


