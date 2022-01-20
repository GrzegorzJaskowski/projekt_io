#include "rozgrywka.h"
#include "interfejs.h"
#include "gracz.h"

int main()
{
    wczytywanie();
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
