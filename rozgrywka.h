#pragma once
#include "gracz.h"

void rozpocznij_rozgrywke(int czy_admin, int id, Gracz tab[]);
void wyswietl_plansze(char tab[]);
int ruch_przeciwnika_latwy(char tab[]);
bool koniec_partii(char tab[]);
char wygrany_symbol(char tab[]);
void remis(int czy_admin, int id, Gracz tab[]);
int ruch_przeciwnika_trudny(char plansza[]);
int poziom_trudnosci(int poziom);