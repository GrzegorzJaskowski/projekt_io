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

void Gracz::wypisanie() {
    std::cout << login << std::endl;
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
    menu_logowania(tablica_baza);
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