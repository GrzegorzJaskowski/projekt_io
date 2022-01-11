#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "rozgrywka.h"
#include "interfejs.h"
#include "gracz.h"

void rozpocznij_rozgrywke(int czy_admin, int id, Gracz tab[])
{
	srand((unsigned int)time(NULL));
	int poziom = 1;
	int index;
	char legenda[9] = { '1', '2', '3', '4', '5','6','7','8','9' };
	char plansza[9];
	int pom;
	for (int i = 0; i < 9; i++)
	{
		plansza[i] = ' ';
	}
	bool figura = true;
	char znak;

	system("cls");
	std::cout << "Rozgrywka zostala rozpoczeta!" << std::endl;

	while (koniec_partii(plansza))
	{
		Sleep(500);
		system("cls");
		std::cout << "Legenda:" << std::endl;
		wyswietl_plansze(legenda);
		std::cout << std::endl << "Plansza:" <<std::endl;
		wyswietl_plansze(plansza);
		if (figura)
		{
			figura = false;
			znak = 'o';
		}
		else
		{
			figura = true;
			znak = 'x';
		}
		std::cout << std::endl << "Podaj numer pola (1-9), na ktorym chcesz postawic swoja figure: ";
		std::cin >> index;
		if (plansza[index - 1] == ' ')
		{
			plansza[index - 1] = znak;
		}
		else
		{
			while (plansza[index - 1] != ' ')
			{
				std::cout << std::endl << "Podane pole jest zajete, podaj wlasciwy numer pola: ";
				std::cin >> index;
			}
			plansza[index - 1] = znak;
		}
		std::cout << std::endl;
		Sleep(500);
		system("cls");
		std::cout << "Legenda:" << std::endl;
		wyswietl_plansze(legenda);
		std::cout << std::endl << "Plansza:" << std::endl;
		wyswietl_plansze(plansza);
		if (!koniec_partii(plansza)) break;
		if (figura)
		{
			std::cout << std::endl << "Kolej kolka.";
			figura = false;
			znak = 'o';
		}
		else
		{
			std::cout << std::endl << "Kolej krzyzyka." << std::endl;
			figura = true;
			znak = 'x';
		}
		if (poziom == 1)
		{
			pom = ruch_przeciwnika_latwy(plansza);
			if (pom == -1)
			{
				system("cls");
				wyswietl_plansze(plansza);
				remis(czy_admin, id, tab);
			}
			else
				plansza[pom] = znak;
		}
	}
	if (wygrany_symbol(plansza) == 'o')
	{
		system("cls");
		wyswietl_plansze(plansza);
		std::cout << std::endl << "Koniec gry, wygrales! Zdobywasz " << poziom << " punkt/y!" << std::endl;
		tab[id].dodaj_punkty(poziom);
	}
	else if (wygrany_symbol(plansza) == 'x')
	{
		system("cls");
		wyswietl_plansze(plansza);
		std::cout << std::endl << "Koniec gry, przegrales... Wygraly " << wygrany_symbol(plansza) << "!" << std::endl;
	}
	std::cout << std::endl << "Wcisnij dowolny klawisz aby kontynuowac";
	std::cin.get();
	std::cin.ignore();
	menu(czy_admin, id, tab);
}

void wyswietl_plansze(char plansza[])
{
	std::cout << " " << plansza[0] << " " << "|" << " " << plansza[1] << " " << "|" << " " << plansza[2] << " " << std::endl
		<< "---+---+---" << std::endl
		<< " " << plansza[3] << " " << "|" << " " << plansza[4] << " " << "|" << " " << plansza[5] << " " << std::endl
		<< "---+---+---" << std::endl
		<< " " << plansza[6] << " " << "|" << " " << plansza[7] << " " << "|" << " " << plansza[8] << " " << std::endl;
}

int ruch_przeciwnika_latwy(char plansza[])
{
	int pole = rand() % 9;
	int counter = 0;
	while (plansza[pole] == 'x' || plansza[pole] =='o')
	{
		if (counter > 100)
			return -1;
		pole = rand() % 9;
		counter++;
	}
	return pole;
}

bool koniec_partii(char plansza[])
{
	bool wynik = true;
	if (plansza[0] != ' ' && plansza[0] == plansza[1] && plansza[1] == plansza[2])	wynik = false;
	else if (plansza[3] != ' ' && plansza[3] == plansza[4] && plansza[4] == plansza[5])	wynik = false;
	else if (plansza[6] != ' ' && plansza[6] == plansza[7] && plansza[7] == plansza[8])	wynik = false;
	else if (plansza[0] != ' ' && plansza[0] == plansza[3] && plansza[3] == plansza[6])	wynik = false;
	else if (plansza[1] != ' ' && plansza[1] == plansza[4] && plansza[4] == plansza[7])	wynik = false;
	else if (plansza[2] != ' ' && plansza[2] == plansza[5] && plansza[5] == plansza[8])	wynik = false;
	else if (plansza[0] != ' ' && plansza[0] == plansza[4] && plansza[4] == plansza[8])	wynik = false;
	else if (plansza[3] != ' ' && plansza[3] == plansza[5] && plansza[5] == plansza[7])	wynik = false;
	return wynik;
}

char wygrany_symbol(char plansza[])
{
	char wygrany =' ';
	if (plansza[0] != ' ' && plansza[0] == plansza[1] && plansza[1] == plansza[2])	wygrany = plansza[0];
	else if (plansza[3] != ' ' && plansza[3] == plansza[4] && plansza[4] == plansza[5])	wygrany = plansza[3];
	else if (plansza[6] != ' ' && plansza[6] == plansza[7] && plansza[7] == plansza[8])	wygrany = plansza[6];
	else if (plansza[0] != ' ' && plansza[0] == plansza[3] && plansza[3] == plansza[6])	wygrany = plansza[0];
	else if (plansza[1] != ' ' && plansza[1] == plansza[4] && plansza[4] == plansza[7])	wygrany = plansza[1];
	else if (plansza[2] != ' ' && plansza[2] == plansza[5] && plansza[5] == plansza[8])	wygrany = plansza[2];
	else if (plansza[0] != ' ' && plansza[0] == plansza[4] && plansza[4] == plansza[8])	wygrany = plansza[0];
	else if (plansza[3] != ' ' && plansza[3] == plansza[5] && plansza[5] == plansza[7])	wygrany = plansza[3];
	return wygrany;
}

void remis(int czy_admin, int id, Gracz tab[])
{

	std::cout << std::endl << "Koniec gry, remis!" << std::endl << "Wcisnij dowolny klawisz aby kontynuowac";
	std::cin.get();
	std::cin.ignore();
	menu(czy_admin, id, tab);
}