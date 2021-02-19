#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <windows.h>

#include "MetodyPomocnicze.h"

using namespace std;

class Menu {

public:

    MetodyPomocnicze metodyPomocnicze;

    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
    void czyscEkran();
};

#endif
