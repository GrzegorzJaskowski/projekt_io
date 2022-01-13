#include <iostream>
#include <windows.h>
#include "interfejs.h"
#include "gracz.h"
#include "rozgrywka.h"

void menu_logowania(int id, Gracz tab[]) {
    system("cls");
    std::cout << "----------------MENU----------------\n"
        << "[1] Logowanie\n"
        << "[2] Tworzenie konta\n"
        << "[3] Wyjscie\n"
        << "------------------------------------\n";
    int a;
    std::cout << "Wpisz numer funkcji, ktora chcesz wykonac: ";
    std::cin >> a;
    switch (a) {
    case 1:
        system("cls");
        std::cout << "Wybrano logowanie" << std::endl;
        logowanie(tab);
        break;
    case 2:
        system("cls");
        std::cout << "Wybrano tworzenie konta" << std::endl;
        zapis(tab);
        tworzenie_konta(id, tab);
        break;
    case 3:
        system("cls");
        zapis(tab);
        std::cout << "Zakonczono!" << std::endl;
        exit(0);
    default:
        system("cls");
        std::cout << "Nie ma takiej opcji!" << std::endl;
        Sleep(1500);
        menu_logowania(id, tab);
    }
}

void menu(int czy_admin, int id, Gracz tab[]) {
    system("cls");
    int a;
    if (czy_admin == 0) {
        std::cout << "----------------MENU----------------\n"
            << "[1] Rozpoczecie rozgrywki\n"
            << "[2] Zarzadzanie kontem\n"
            << "[3] Wyloguj\n"
            << "------------------------------------\n";
        std::cout << "Wpisz numer funkcji, ktora chcesz wykonac: ";
        std::cin >> a;
        switch (a) {
        case 1:
            system("cls");
            std::cout << "Wybrano rozpoczecie rozgrywki" << std::endl;
            rozpocznij_rozgrywke(czy_admin, id, tab);
            break;
        case 2:
            system("cls");
            std::cout << "Wybrano zarzadzanie kontem" << std::endl;
            zarzadzanie_kontem(czy_admin, id, tab);
            break;
        case 3:
            system("cls");
            std::cout << "Wylogowano!" << std::endl;
            Sleep(1500);
            wczytywanie();
        default:
            std::cout << "Nie ma takiej opcji!" << std::endl;
            Sleep(1500);
            menu(czy_admin, id, tab);
        }

    }
    else {
        std::cout << "----------------MENU----------------\n"
            << "[1] Rozpoczecie rozgrywki\n"
            << "[2] Zarzadzanie kontem\n"
            << "[3] Zarzadzanie kontami graczy\n"
            << "[4] Blokowanie dostepu do kont graczy\n"
            << "[5] Wyloguj\n"
            << "------------------------------------\n";
        std::cout << "Wpisz numer funkcji, ktora chcesz wykonac: ";
        std::cin >> a;
        switch (a) {
        case 1:
            std::cout << "Wybrano rozpoczecie rozgrywki" << std::endl;
            rozpocznij_rozgrywke(czy_admin, id, tab);
            break;
        case 2:
            std::cout << "Wybrano zarzadzanie kontem" << std::endl;
            zarzadzanie_kontem(czy_admin, id, tab);
            break;
        case 3:
            std::cout << "Wybrano zarzadzanie kontami graczy" << std::endl;
            zarzadzanie_kontami_graczy(czy_admin, id, tab);
            break;
        case 4:
            std::cout << "Wybrano blokowanie dostepu do kont graczy" << std::endl;
            zmienianie_dostepu_do_kont(czy_admin, id, tab);
            break;
        case 5:
            system("cls");
            std::cout << "Wylogowano!" << std::endl;
            Sleep(1500);
            wczytywanie();
        default:
            std::cout << "Nie ma takiej opcji!" << std::endl;
            Sleep(1500);
            system("cls");
            menu(czy_admin, id, tab);
        }
    }

}
