#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <windows.h>

#include "MetodyPomocnicze.h"

using namespace std;

class Menu {

public:

    static char wybierzOpcjeZMenuGlownego();
    static char wybierzOpcjeZMenuUzytkownika();
    static char wybierzOpcjeZMenuEdycja();
    static void czyscEkran();
};

#endif
