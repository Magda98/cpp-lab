#pragma once
#include <fstream>
#include "Pracownik.h"
class ListaPracownikow
{
private:
	Pracownik* m_pPoczatek;
	int m_nLiczbaPracownikow;

public:
	void Dodaj(const Pracownik &p);
	void Usun(const Pracownik &wzorzec);
	void WypiszPracownikow() const;
	const Pracownik* Szukaj(const char* nazwiko, const char* imie) const;
	void Zapisz();
	ListaPracownikow();
	~ListaPracownikow();
};

