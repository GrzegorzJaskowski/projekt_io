#include "rozgrywka.h"
#include "interfejs.h"
#include "gracz.h"
#include <iostream>

std::string test_kostruktora_domyslnego_klasy_gracz()
{
    Gracz testowy_gracz;
    if (testowy_gracz.getlogin() == "domyslne")
    {
        return "konstruktor domyslny klasy Gracz dziala poprawnie";
    }
    else
    {
        return "blad w konstruktorze domyslnym klasy Gracz";
    }
}

std::string test_dodawania_danych_obiektu_klasy_gracz()
{
    Gracz testowy_gracz;
    testowy_gracz.dodawanie("testowy_login", "testowe_haslo", 0, 0, 1);
    if (testowy_gracz.getlogin() == "testowy_login")
    {
        return "konstruktor domyslny klasy Gracz dziala poprawnie";
    }
    else
    {
        return "blad w konstruktorze domyslnym klasy Gracz";
    }
}

std::string test_funkcji_ruch_przeciwnika_latwy()
{
    char tab[9];
    if (ruch_przeciwnika_latwy(tab) >= 0 && ruch_przeciwnika_latwy(tab) <= 8)
    {
        return "funkcja ruch_przeciwnika_latwy dziala poprawnie";
    }
    else
    {
        return "blad w funkcji ruch_przeciwnika_latwy";
    }
}

void testy_jednostkowe()
{
    std::cout << "Test konstruktora domyslnego klasy gracz..." << std::endl
        << test_kostruktora_domyslnego_klasy_gracz() << "\n\n\n";
    std::cout << "Test dodawania danych obiektu klasy gracz..." << std::endl
        << test_dodawania_danych_obiektu_klasy_gracz() << "\n\n\n";
    std::cout << "Test funkcji ruch_przeciwnika_latwy..." << std::endl
        << test_funkcji_ruch_przeciwnika_latwy() << "\n\n\n";
}

int main()
{
    wczytywanie();

    testy_jednostkowe();
}

//PRZYKŁAD REFAKTORYZACJI FUNKCJI
/*
funkcja przed zmianą:
void wypisanie(Gracz tab[]) {
    int i = 0;
    while (tab[i].login != "domyslne") {
        std::cout << "[" << i << "] " << tab[i].login << " " << tab[i].haslo << " " << tab[i].wynik << " " << tab[i].rola_admin << " " << tab[i].dostep_do_konta << std::endl;
        i++;
    }
}

funkcja po zmianie:
void wypisanie(Gracz tab[]) {
    int i = 0;
    while (tab[i].login != "domyslne") {
        std::cout << "[" << i << "] " << tab[i].login << " " << tab[i].haslo
            << " " << tab[i].wynik << " " << tab[i].rola_admin
            << " " << tab[i].dostep_do_konta << std::endl;
        i++;
    }
}
*/
