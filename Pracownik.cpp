#include "Pracownik.h"

int Pracownik::ID = 0; 

int Pracownik::Porownaj(const Pracownik & wzorzec) const
{
	int x = -1;

	if ((this->SprawdzNazwisko(wzorzec.Nazwisko())) == 0 && (this->SprawdzImie(wzorzec.Imie())) == 0 && (this->m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia)) == 0)
		return 0;
	if (this->SprawdzNazwisko(wzorzec.Nazwisko()) > 0)
	{
		return 1;
	}
	else if (this->SprawdzNazwisko(wzorzec.Nazwisko()) == 0 && (this->SprawdzImie(wzorzec.Imie()) > 0))
	{
		return 1;
	}
	else if (this->SprawdzNazwisko(wzorzec.Nazwisko()) == 0 && this->SprawdzImie(wzorzec.Imie()) == 0 && (this->m_DataUrodzenia.Porownaj(wzorzec.m_DataUrodzenia)) > 0)
	{
		return 1;
	}

	return x;
}

const char * Pracownik::Imie() const
{
	return m_Imie.Zwroc();
}

const char * Pracownik::Nazwisko() const
{
	return m_Nazwisko.Zwroc();
}

Data  Pracownik::DataUrodzenia() const
{
	return m_DataUrodzenia;
}

void Pracownik::Imie(const char * nowe_imie)
{
	m_Imie.Ustaw(nowe_imie);
}

void Pracownik::Nazwisko(const char * nowe_nazwisko)
{
	m_Nazwisko.Ustaw(nowe_nazwisko);
}

void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
	m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}

void Pracownik::Wypisz() const
{
	m_Imie.Wypisz();
	std::cout << "		";
	m_Nazwisko.Wypisz();
	std::cout << "		";
	m_DataUrodzenia.Wypisz();
	std::cout << std::endl;
}

void Pracownik::Wpisz()
{
	std::cout << "podaj imie: ";
	m_Imie.Wpisz();
	std::cout << "podaj nazwisko: ";
	m_Nazwisko.Wpisz();
	m_DataUrodzenia.Wpisz();

}

void Pracownik::WypiszDane()
{
	std::cout << *this << std::endl;
}

void Pracownik::WypiszDanePlik(std::ostream &plik)
{
	plik << *this << std::endl;
}

Pracownik  *  Pracownik::KopiaObiektu()const
{
	return  new Pracownik(*this);
}

int Pracownik::SprawdzImie(const char * por_imie) const
{
	return m_Imie.SprawdzNapis(por_imie);
}

int Pracownik::SprawdzNazwisko(const char * por_nazwisko) const
{
	return m_Nazwisko.SprawdzNapis(por_nazwisko);
}

Pracownik::Pracownik(const char* im, const char * naz, int dzien, int miesiac, int rok) : m_Imie(im), m_Nazwisko(naz) ,m_DataUrodzenia(dzien, miesiac, rok), m_nIDZatrudnienia{ID++}
{
	m_pNastepny = nullptr;
}
Pracownik::Pracownik(const Pracownik & wzor) :  m_Imie(wzor.m_Imie), m_Nazwisko(wzor.m_Nazwisko), m_DataUrodzenia(wzor.m_DataUrodzenia),m_pNastepny{nullptr}, m_nIDZatrudnienia{ID++}
{
}
Pracownik::~Pracownik()
{
}

Pracownik & Pracownik::operator=(const Pracownik & wzor)
{
	if (this == &wzor)
		return *this;
	m_Nazwisko = wzor.m_Nazwisko;
	m_Imie = wzor.m_Imie;
	m_DataUrodzenia = wzor.m_DataUrodzenia;
	m_pNastepny = nullptr;
	return *this;
}

bool Pracownik::operator==(const Pracownik & wzor) const
{
	if (this == &wzor)
		return  true;
	if (Porownaj(wzor) == 0)
		return true;
	return false;
}

std::ostream & operator<<(std::ostream & wy, const Pracownik & p)
{
	wy << p.m_Imie << "\t" << p.m_Nazwisko << "\t" << p.m_DataUrodzenia;
	return wy;
}

std::istream & operator>>(std::istream & we, Pracownik & p)
{
	we >> p.m_Imie;
	we >> p.m_Nazwisko;
	we >> p.m_DataUrodzenia;
	return we;
}
