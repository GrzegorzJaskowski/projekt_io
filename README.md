# projekt_io

STANDARDY KODOWANIA
- wcięcia w kodzie dla każdej jego zagnieżdżonej części
- domyślne kolory kodu dla visual studio
- rozłożenie poszczególnych klas na oddzielne pliki nagłówkowe i źródłowe
- stosowanie zapisu klamrowego
- korzystanie ze snake case w nazewnictwie zmiennych i funkcji




PRZYKŁAD REFAKTORYZACJI

funkcja przed zmianą: <br />
void wypisanie(Gracz tab[]) { <br />
    int i = 0; <br />
    while (tab[i].login != "domyslne") { <br />
        std::cout << "[" << i << "] " << tab[i].login << " " << tab[i].haslo << " " << tab[i].wynik << " " << tab[i].rola_admin << " " << tab[i].dostep_do_konta << std::endl; <br />
        i++; <br />
    } <br />
} <br />

funkcja po zmianie: <br />
void wypisanie(Gracz tab[]) { <br />
    int i = 0; <br />
    while (tab[i].login != "domyslne") { <br />
        std::cout << "[" << i << "] " << tab[i].login << " " << tab[i].haslo <br />
            << " " << tab[i].wynik << " " << tab[i].rola_admin <br />
            << " " << tab[i].dostep_do_konta << std::endl; <br />
        i++; <br />
    } <br />
} <br />
