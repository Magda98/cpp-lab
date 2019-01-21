#pragma once
#include "Pracownik.h"
class Kierownik : Pracownik
{
private:
	Napis m_NazwaDzialu;
	int m_nliczbaPracownikow;
public:

	Kierownik(const char* im, const char * naz, int dzien, int miesiac, int rok, Napis n, int k);
	Kierownik(const Kierownik &wzor);
	Kierownik &operator=(const Kierownik &wzor);
	bool operator==(const Kierownik &wzor)const;
	virtual void WypiszDane();
	virtual void WypiszDanePlik(std::ostream &plik);
	virtual Pracownik*  KopiaObiektu()const;
	friend std::ostream &operator<<(std::ostream & wy, const Kierownik &s);
	friend std::istream &operator>>(std::istream & we, Kierownik &s);
	~Kierownik();
};

