#pragma once
#include "Napis.h"
#include "Data.h"
#include <iostream>




class Pracownik
{
private:
	static int ID;
	Napis m_Imie;
	Napis m_Nazwisko;
	Data m_DataUrodzenia;
	const int m_nIDZatrudnienia;
public:
	Pracownik* m_pNastepny;
	int Porownaj(const Pracownik& wzorzec) const;
	const char* Imie() const;
	const char* Nazwisko() const;
	Data  DataUrodzenia() const;
	void Imie(const char* nowe_imie);
	void Nazwisko(const char* nowe_nazwisko);
	void DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok);
	void Wypisz() const;
	void Wpisz();
	virtual void WypiszDane();
	virtual void WypiszDanePlik(std::ostream &plik);
	virtual Pracownik* KopiaObiektu()const;
	int SprawdzImie(const char* por_imie) const;
	int SprawdzNazwisko(const char* por_nazwisko) const;


	Pracownik(const char* im = "", const char * naz = "", int dzien = 1, int miesiac = 1, int rok = 2000);
	Pracownik(const Pracownik &wzor);
	~Pracownik();

	Pracownik & operator=(const Pracownik &wzor);
	bool operator==(const Pracownik &wzor)const;
	friend std::ostream & operator<<(std::ostream & wy, const Pracownik & p);
	friend std::istream & operator>>(std::istream & we, Pracownik & p);
};

