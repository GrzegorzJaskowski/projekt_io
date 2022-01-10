#pragma once
#include <string>

class Gracz {
private:
    std::string login;
    std::string haslo;
    int wynik;
    bool rola_admin;
    bool dostep_do_konta;
public:
    Gracz();
    void dodawanie(std::string l, std::string h, int w, bool r, bool d);
    void wypisanie();
    friend void logowanie(Gracz tab[]);
    friend void zapis(Gracz tab[]);
    void dodaj_punkty(int pkt)
    {
        wynik += pkt;
    }
};

void wczytywanie();