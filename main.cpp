#include <iostream>
#include <fstream>
#include "Data.h"
#include "Napis.h"
#include "Pracownik.h"
#include "ListaPracownikow.h"
#include "Kierownik.h"


//L03 Kochman Magdalena



int main() {
	int war = 1;
	char x;
	Napis imie, naziwsko, napis;
	int lp;
	bool kier = false;
	Data data(1,1,1);
	ListaPracownikow lista;
	std::ifstream oplik;

	while (war)
	{
		std::cin.clear();
		std::cout << "d - dodaj pracownika\nk - dodaj kierownika\ns - szukaj \nu - usun\nw - wypisz pracownikow\nq - wyjdz\no - odczytaj z pliku\nz - zapisz do pliku" << std::endl;
		std::cin >> x;
		switch (x)
		{
		case 'd':
		{
			Pracownik *p = new Pracownik();
			p->Wpisz();
			lista.Dodaj(*p);
			break;
		}
		case 'k':
		{
			Kierownik *k = new Kierownik("", "" , 1 , 1, 1, "dzial", 0);
			std::cin >> *k;
			lista.Dodaj((Pracownik&)*k);
			break;
		}
		case 's':
			std::cout << "podaj imie: ";
			std::cin >> imie;
			std::cout << "podaj nazwisko: ";
			naziwsko.Wpisz();
			std::cout << *lista.Szukaj(naziwsko.Zwroc(), imie.Zwroc());
			break;
		case 'u':
			std::cout << "podaj imie: ";
			std::cin >> imie;
			std::cout << "podaj nazwisko: ";
			std::cin >> naziwsko;
			lista.Usun(*lista.Szukaj(naziwsko.Zwroc(), imie.Zwroc()));
			break;
		case 'w':
			lista.WypiszPracownikow();
			break;
		case 'o':
		{
			oplik.open("lista.txt");
			while (!(oplik.eof()))
			{
				x = oplik.peek();
				if (x == '\n') oplik.get(x);
				x = oplik.peek();
				if ((('A' <= x) && (x <= 'Z')) || (('a' <= x) && (x <= 'z')))
				{
					oplik >> imie;
					oplik >> naziwsko;
					oplik >> data;
					if (oplik.peek() == '\t') {
						oplik >> napis;
						oplik >> lp;
						kier = true;
					}
					if (strlen(imie.Zwroc()) != 0 && !kier)
					{
						Pracownik *p = new Pracownik(imie.Zwroc(), naziwsko.Zwroc(), data.Dzien(), data.Miesiac(), data.Rok());
						lista.Dodaj(*p);
					}
					else if(kier == true)
					{
						Kierownik *k = new Kierownik(imie.Zwroc(), naziwsko.Zwroc(), data.Dzien(), data.Miesiac(), data.Rok(), napis.Zwroc(), lp);
						lista.Dodaj((Pracownik&)*k);
						kier = false;
					}
				}
				else
				{
					break;
				}
			}
			oplik.close();
		}
			break;
		case 'z':
			lista.Zapisz();
			break;
		case 'q':
			war = 0;
			break;
		default:
			break;
		}
		std::cout << std::endl;
	}
	return 0;
}
