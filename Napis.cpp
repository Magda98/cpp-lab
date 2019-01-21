#include "Napis.h"

const char * Napis::Zwroc() const
{
	return m_pszNapis;
}

void Napis::Ustaw(const char * nowy_napis)
{
	delete[] m_pszNapis;
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
}
Napis & Napis::operator=(const Napis & wzor)
{
	if (this == &wzor)
		return *this;

	delete[]m_pszNapis;
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
	if (&we == &std::cin) 
	{
		char buf[40];
		we >> buf[0];
		we.get(buf + 1, 39);
		p.Ustaw(buf);
		while (we.peek() != '\n')
		{
			we.get(buf, 40);
			p += buf;
		}
		we.get();//'\n'
	}
	else
	{
		char temp[2];
		char buf;
		we >> buf;
		temp[0] = buf;
		temp[1] = '\0';
		p.Ustaw(temp);
		while ((we.peek() != '\t') && (we.peek() != '\0') && (we.peek() != '\n'))
		{	
			we >> buf;
			temp[0] = buf;
			temp[1] = '\0';
			p += temp;
		}
		we.get();//'\n'
	}
	return we;
}
void Napis::operator+=(const char * n)
{
	if (n == nullptr) return;
	m_nDl += strlen(n);
	char *pn = new char[m_nDl + 1];
	if (m_pszNapis == nullptr)
	{
		strcpy(pn, n);
	}
	else
	{
		strcpy(pn, m_pszNapis);
		strcat(pn, n);
	}
	delete[]m_pszNapis;
	m_pszNapis = pn;
}

