#include "Kierownik.h"





Kierownik::Kierownik(const char* im, const char * naz, int dzien, int miesiac, int rok, Napis n, int k) : Pracownik(im, naz, dzien, miesiac, rok)
{
	m_NazwaDzialu = n;
	m_nliczbaPracownikow = k;
}

Kierownik::Kierownik(const Kierownik & wzor) : Pracownik(wzor),  m_NazwaDzialu(wzor.m_NazwaDzialu), m_nliczbaPracownikow(wzor.m_nliczbaPracownikow)
{
}

Kierownik & Kierownik::operator=(const Kierownik & wzor)
{
	if (this == &wzor)
		return *this;

	Imie(wzor.Imie());
	Nazwisko(wzor.Nazwisko());
	DataUrodzenia(wzor.DataUrodzenia().Dzien(), wzor.DataUrodzenia().Miesiac(), wzor.DataUrodzenia().Rok());

	m_NazwaDzialu = wzor.m_NazwaDzialu;
	m_nliczbaPracownikow = wzor.m_nliczbaPracownikow;
	
	return *this;
}

bool Kierownik::operator==(const Kierownik & wzor) const
{
	if(this == &wzor)
		return true;
	if (Porownaj(wzor) != 0)
		return false;
	if (m_NazwaDzialu.SprawdzNapis(wzor.m_NazwaDzialu.Zwroc()) != 0)
		return false;
	if (wzor.m_nliczbaPracownikow != m_nliczbaPracownikow)
		return false;

	return true;
}

void Kierownik::WypiszDane()
{
	std::cout << *this << std::endl;
}

void Kierownik::WypiszDanePlik(std::ostream & plik)
{
	plik << *this << std::endl;
}

Pracownik *  Kierownik::KopiaObiektu()const
{
	return new Kierownik(*this);
}

Kierownik::~Kierownik()
{
}

std::ostream & operator<<(std::ostream & wy, const Kierownik & s)
{
	wy << s.Imie() << '\t' << s.Nazwisko() << '\t' << s.DataUrodzenia() << '\t' << s.m_NazwaDzialu << '\t' << s.m_nliczbaPracownikow;
	return wy;
}

std::istream & operator>>(std::istream & we, Kierownik & s)
{
	Napis imie;
	Napis nazwisko;
	Data dataUr(1, 1, 1);
	std::cout << "imie: ";
	we >> imie;
	std::cout << "nazwisko: ";
	we >> nazwisko;
	std::cout << "data urodzenia (dzien, miesiac, rok): ";
	we >> dataUr;
	std::cout << "nazwa dzialu: ";
	we >> s.m_NazwaDzialu;
	std::cout << "liczba pracownikow: ";
	we >> s.m_nliczbaPracownikow;
	s.Imie(imie.Zwroc());
	s.Nazwisko(nazwisko.Zwroc());
	s.DataUrodzenia(dataUr.Dzien(), dataUr.Miesiac(), dataUr.Rok());
	return we;
}
