# projekt_io

STANDARDY KODOWANIA
- wcięcia w kodzie dla każdej jego zagnieżdżonej części
- domyślne kolory kodu dla visual studio
- rozłożenie poszczególnych klas na oddzielne pliki nagłówkowe i źródłowe
- stosowanie zapisu klamrowego
- korzystanie ze snake case w nazewnictwie zmiennych i funkcji




PRZYKŁAD REFAKTORYZACJI

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
