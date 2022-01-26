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
    friend void wypisanie(Gracz tab[]);
    friend void logowanie(Gracz tab[]);
    friend void zapis(Gracz tab[]);
    friend void zarzadzanie_kontem(int czy_admin, int id, Gracz tab[]);
    friend void tworzenie_konta(int id, Gracz tab[]);
    friend void zmienianie_dostepu_do_kont(int czy_admin, int id, Gracz tab[]);
    friend void zarzadzanie_kontami_graczy(int czy_admin, int id, Gracz tab[]);
    void dodaj_punkty(int pkt)
    {
        wynik += pkt;
    }
    void setlogin(std::string l)
    {
        login = l;
    }
    void sethaslo(std::string h)
    {
        haslo = h;
    }
    void setdostep(bool d)
    {
        dostep_do_konta = d;
    }
    std::string getlogin()
    {
        return login;
    }
};

void wczytywanie();