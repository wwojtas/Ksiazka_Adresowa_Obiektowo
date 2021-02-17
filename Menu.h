#ifndef MENU_H
#define MENU_H

#include <iostream>
#include "MetodyPomocnicze.h"

using namespace std;

class Menu {

public:

    MetodyPomocnicze metodyPomocnicze;

    char wybierzOpcjeZMenuGlownego();
    char wybierzOpcjeZMenuUzytkownika();
};

#endif
