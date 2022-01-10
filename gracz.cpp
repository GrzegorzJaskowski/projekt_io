#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
#include "gracz.h"
#include "interfejs.h"

Gracz::Gracz() {
    login = "domyslne";
    haslo = "domyslne";
    wynik = NULL;
    rola_admin = NULL;
    dostep_do_konta = NULL;
}

void Gracz::dodawanie(std::string l, std::string h, int w, bool r, bool d) {
    login = l;
    haslo = h;
    wynik = w;
    rola_admin = r;
    dostep_do_konta = d;
}

void wypisanie(Gracz tab[]) {
    int i = 0;
    while (tab[i].login != "domyslne") {
        std::cout << "[" << i << "] " << tab[i].login << " " << tab[i].haslo
            << " " << tab[i].wynik << " " << tab[i].rola_admin
            << " " << tab[i].dostep_do_konta << std::endl;
        i++;
    }
}

void wczytywanie()
{
    std::ifstream plik("baza.txt");
    const int wielkosc_bazy = 10;
    int i = 0;
    std::string line, login_pom, haslo_pom, wynik_pom, admin_pom, dostep_pom;
    bool rola_admin_pom, dostep_do_konta_pom;
    Gracz tablica_baza[wielkosc_bazy];
    if (plik.is_open()) {
        while (std::getline(plik, line)) {
            std::istringstream ss(line);
            getline(ss, login_pom, ' ');
            getline(ss, haslo_pom, ' ');
            getline(ss, wynik_pom, ' ');
            getline(ss, admin_pom, ' ');
            getline(ss, dostep_pom, ' ');
            if (admin_pom == "1") {
                rola_admin_pom = true;
            }
            else {
                rola_admin_pom = false;
            }
            if (dostep_pom == "1") {
                dostep_do_konta_pom = true;
            }
            else {
                dostep_do_konta_pom = false;
            }

            tablica_baza[i].dodawanie(login_pom, haslo_pom, std::stoi(wynik_pom), rola_admin_pom, dostep_do_konta_pom);
            i++;
        }
    }
    else {
        std::cout << "Pliku nie otworzono!" << std::endl;
    }
    menu_logowania(i, tablica_baza);
}

void logowanie(Gracz tab[]) {
    std::string login, haslo;
    system("cls");
    std::cout << "Wpisz login: ";
    std::cin >> login;
    int i = 0;
    while (tab[i].login != "domyslne") {
        if (tab[i].login == login) {
            std::cout << "Wpisz haslo: ";
            std::cin >> haslo;
            if (tab[i].dostep_do_konta == false)
            {
                std::cout << "Brak dostepu do konta. Konto zablokowane.";
                logowanie(tab);
            }
            if (tab[i].haslo == haslo) {
                if (tab[i].rola_admin == true) {
                    menu(1, i, tab);
                    return;
                }
                else {
                    menu(0, i, tab);
                    return;
                }

            }
            else {
                std::cout << "Niepoprawne haslo" << std::endl;
                Sleep(1500);
                logowanie(tab);
            }
        }
        i++;
    }
    std::cout << "Niepoprawny login" << std::endl;
    Sleep(1500);
    system("cls");
    logowanie(tab);
}

void zapis(Gracz tab[]) {
    std::ofstream zapisz("baza.txt");
    int i = 0;
    while (tab[i].login != "domyslne")
    {
        zapisz << tab[i].login << " " << tab[i].haslo
            << " " << tab[i].wynik << " " << tab[i].rola_admin
            << " " << tab[i].dostep_do_konta << std::endl;
        i++;
    }
    zapisz.close();
}

void zarzadzanie_kontem(int czy_admin, int id, Gracz tab[])
{
    system("cls");
    std::cout << "Dane" << std::endl
        << "[1]Login: " << tab[id].login << std::endl
        << "[2]Haslo: " << tab[id].haslo << std::endl
        << "[3]Powrot do menu" << std::endl
        << "Wpisz numer funkcji, ktora chcesz wykonac: ";
    int a;
    std::string log, has;
    std::cin >> a;
    switch (a) {
    case 1:
        system("cls");
        std::cout << "Wprowadz nowy login" << std::endl;
        std::cin >> log;
        tab[id].setlogin(log);
        zapis(tab);
        std::cout << "Login zmieniono" << std::endl;
        Sleep(1500);
        zarzadzanie_kontem(czy_admin, id, tab);
        break;
    case 2:
        system("cls");
        std::cout << "Wprowadz nowe haslo" << std::endl;
        std::cin >> has;
        tab[id].sethaslo(has);
        zapis(tab);
        std::cout << "Haslo zmieniono" << std::endl;
        Sleep(1500);
        zarzadzanie_kontem(czy_admin, id, tab);
        break;
    case 3:
        menu(czy_admin, id, tab);
        break;
    default:
        std::cout << "Nie ma takiej opcji!" << std::endl;
        Sleep(1500);
        system("cls");
        zarzadzanie_kontem(czy_admin, id, tab);
    }
}

void tworzenie_konta(int id, Gracz tab[])
{
    std::string login, haslo;
    system("cls");
    std::cout << "Wpisz login: ";
    std::cin >> login;
    std::cout << "Wpisz haslo: ";
    std::cin >> haslo;
    tab[id].dodawanie(login, haslo, 0, 0, 1);
    zapis(tab);
    std::cout << "Konto stworzono. Nalezy sie zalogowac" << std::endl;
    Sleep(1500);
    logowanie(tab);
}

void zmienianie_dostepu_do_kont(int czy_admin, int id, Gracz tab[])
{
    system("cls");
    std::cout << "[-1] powrot do menu";
    wypisanie(tab);
    std::cout << "Wybierz numer gracza, ktoremu dostep do konta chcesz zmienic " << std::endl;
    int pom;
    std::cin >> pom;
    if (pom > 9) {
        std::cout << "Wybrano zla opcje" << std::endl;
        Sleep(1500);
        zmienianie_dostepu_do_kont(czy_admin, id, tab);
    }
    std::cout << "Wprowadz 1 jesli chcesz zablokowac konto, 2 jesli chcesz je odblokowac, 3 aby wrocic do menu: ";
    int a;
    std::cin >> a;
    switch (a) {
    case -1:
        menu(czy_admin, id, tab);
    case 1:
        tab[pom].setdostep(false);
        std::cout << "Zmieniono dostep! " << std::endl;
        zapis(tab);
        Sleep(2500);
        zmienianie_dostepu_do_kont(czy_admin, id, tab);
        break;
    case 2:
        tab[pom].setdostep(true);
        std::cout << "Zmieniono dostep! " << std::endl;
        Sleep(2500);
        zapis(tab);
        zmienianie_dostepu_do_kont(czy_admin, id, tab);
        break;
    case 3:
        menu(czy_admin, id, tab);
        break;
    default:
        std::cout << "Nie ma takiej opcji!" << std::endl;
        Sleep(1500);
        system("cls");
        zmienianie_dostepu_do_kont(czy_admin, id, tab);
        break;
    }
}

void zarzadzanie_kontami_graczy(int czy_admin, int id, Gracz tab[])
{
    system("cls");
    std::cout << "[-1] powrot do menu";
    wypisanie(tab);
    std::cout << "Wybierz numer gracza, ktorego dane chcesz zmienic: ";
    int index;
    std::cin >> index;
    if (index == -1)
    {
        menu(czy_admin, id, tab);
    }
    else if (index > 9) {
        std::cout << "Wybrano zla opcje" << std::endl;
        Sleep(1500);
        zarzadzanie_kontami_graczy(czy_admin, id, tab);
    }
    zarzadzanie_kontem(czy_admin, index, tab);
}