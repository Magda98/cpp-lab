#include "Napis.h"

const char * Napis::Zwroc() const
{
	return m_pszNapis;
}

void Napis::Ustaw(const char * nowy_napis)
{
	m_nDl = strlen(nowy_napis);
	m_pszNapis = new char[m_nDl + 1];
	strcpy(m_pszNapis, nowy_napis);
}

void Napis::Wypisz() const
{
	std::cout << m_pszNapis;
}

void Napis::Wpisz()
{
	std::cin >> m_pszNapis;
}

int Napis::SprawdzNapis(const char * por_napis) const
{
	return strcmp(m_pszNapis, por_napis );
}

Napis::Napis(const char *nap)
{
	m_nDl = strlen(nap);
	m_pszNapis = new char[m_nDl + 1];
	strcpy(m_pszNapis, nap);
}

Napis::Napis(const Napis & wzor)
{
	m_nDl = wzor.m_nDl;
	m_pszNapis = new char[m_nDl + 1];
	strcpy(m_pszNapis, wzor.m_pszNapis);
}


Napis::~Napis()
{
	delete[] m_pszNapis;
	m_pszNapis = nullptr;
}
Napis & Napis::operator=(const Napis & wzor)
{
	if (this == &wzor)
		return *this;

	m_nDl = wzor.m_nDl;
	m_pszNapis = new char[m_nDl + 1];
	strcpy(m_pszNapis, wzor.m_pszNapis);

	return *this;
}
bool Napis::operator==(const Napis & wzor) const
{
	if (!strcmp(m_pszNapis, wzor.m_pszNapis))
		return true;
	return false;
}
std::ostream &operator<<(std::ostream &wy, const Napis &p) 
{
	return wy << p.m_pszNapis;
}
std::istream &operator>>(std::istream &we, Napis &p) 
{
	we >> p.m_pszNapis;
	p.m_nDl = strlen(p.m_pszNapis);
	return we;
}

