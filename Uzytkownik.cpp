#include "Uzytkownik.h"

//settery
void Uzytkownik::ustawId(int noweId) {
    if(noweId >= 0)
    this -> id = noweId;
}
void Uzytkownik::ustawlogin(string nowyLogin) {
    this -> login = nowyLogin;
}
void Uzytkownik::ustawHaslo(string noweHaslo) {
    this -> haslo = noweHaslo;
}

//gettery
int Uzytkownik::pobierzId() {
    return id;
}
string Uzytkownik::pobierzLogin() {
    return login;
}

string Uzytkownik::pobierzHaslo() {
    return haslo;
}


