#include <iostream>
#include "Data.h"
#include "Napis.h"
#include "Pracownik.h"
#include "ListaPracownikow.h"



//L03 Kochman Magdalena



int main() {
//	Pracownik p;
//	Pracownik d;
//	Pracownik k;
//	Pracownik l;
//	ListaPracownikow list;
////	Data d;
//	Napis s;
//	//char np[20] = "asdsdasd";
//	//s.Ustaw(np);
//	//s.Wypisz();
//	Napis imie, nazwisko;
//	p.Wpisz();
//	d.Wpisz();
//	k.Wpisz();
//	l.Wpisz();
//	list.Dodaj(p);
//	list.Dodaj(d);
//	list.Dodaj(k);
//	list.Dodaj(l);
//	std::cout << std::endl;
//	list.WypiszPracownikow();
//
//	std::cout << "usuniecie:" << std::endl;
//	imie.Wpisz();
//	nazwisko.Wpisz();
//
//	list.Usun(*list.Szukaj(nazwisko.Zwroc(), imie.Zwroc() ));
//
//	std::cout << std::endl;
//	list.WypiszPracownikow();
//
//	imie.Wpisz();
//	nazwisko.Wpisz();
//
//	list.Usun(*list.Szukaj(nazwisko.Zwroc(), imie.Zwroc()));
//
//	std::cout << std::endl;
//	list.WypiszPracownikow();
//	imie.Wpisz();
//	nazwisko.Wpisz();
//
//	list.Usun(*list.Szukaj(nazwisko.Zwroc(), imie.Zwroc()));
//
//	std::cout << std::endl;
//	list.WypiszPracownikow();
//	imie.Wpisz();
//	nazwisko.Wpisz();
//
//	list.Usun(*list.Szukaj(nazwisko.Zwroc(), imie.Zwroc()));
//
//	std::cout << std::endl;
//	list.WypiszPracownikow();

	Pracownik ppp;
	ppp.Wpisz();
	Napis nap = "xddddd";
	Napis xd = nap;
	Napis xp;
	xd.Ustaw("pppp");
	Data d(5, 12, 2018);
	xp = nap;
	xp.Ustaw("hahaha");
	std::cout << d << " " << nap << " " << xd << " " << xp << std::endl;
	std::cout << (nap == xd);
	//std::cout << d;
	std::cout << "\n"<< ppp << std::endl;
	std::cin >> d;
	std::cout << std::endl;
	std::cout << d;

	system("pause");
	return 0;
}

