#include "Data.h"


void  Data::Ustaw(int d, int m, int r) {
	m_nDzien = d;
	m_nMiesiac = m;
	m_nRok = r;
	Koryguj();
}
int Data::Rok() const {
	return m_nRok;
}

void Data::Wypisz() const
{
	std::cout << m_nDzien << "-" << m_nMiesiac << "-" << m_nRok;
}

void Data::Wpisz()
{
	int m, d, r;
	std::cout << " podaj dzien: ";
	std::cin >> d;
	std::cout << " podaj miesiac: ";
	std::cin >> m;
	std::cout << " podaj rok: ";
	std::cin >> r;
	Ustaw(d, m, r);
}

int Data::Miesiac() const {
	return m_nMiesiac;
}

int Data::Dzien() const {
	return m_nDzien;
}
void Data::Koryguj() {
	bool przestepny = false;
	if (m_nRok % 400 == 0 || m_nRok %4 == 0 && m_nRok % 100 != 0 )
		przestepny = true;

	if (m_nMiesiac == 2 && przestepny) {
		if (m_nDzien < 0) {
			m_nDzien = 1;
		}
		else if (m_nDzien > 29)
		{
			m_nDzien = 29;
		}
	}
	 if (m_nMiesiac == 2 && !przestepny) {
		if (m_nDzien < 0) {
			m_nDzien = 1;
		}
		else if (m_nDzien > 29)
		{
			m_nDzien = 28;
		}
	}
	if (m_nMiesiac < 0)
				m_nMiesiac = 1;
	 if (m_nMiesiac > 12)
				m_nMiesiac = 12;
	 if (m_nMiesiac > 0 && m_nMiesiac < 13 && m_nMiesiac != 2)
			{
				if (m_nMiesiac == 1 || m_nMiesiac == 3 || m_nMiesiac == 5 || m_nMiesiac == 7 || m_nMiesiac == 8 || m_nMiesiac == 10 || m_nMiesiac == 12)
				{
					if (m_nDzien > 31)
						m_nDzien = 31;
					if (m_nDzien < 0)
						m_nDzien = 1;
				}
				if (m_nMiesiac == 4 || m_nMiesiac == 6 || m_nMiesiac == 9 || m_nMiesiac == 11 )
				{
					if (m_nDzien > 30)
						m_nDzien = 30;
					if (m_nDzien < 0)
						m_nDzien = 1;
				}
			}
	
}

int Data::Porownaj(const Data & wzor) const {
	int x = -1;
	if (wzor.Dzien() == m_nDzien && wzor.Miesiac() == m_nMiesiac && wzor.Rok() == m_nRok)
		x = 0;
	if (wzor.Rok() > m_nRok)
		x = 1;
	else if (wzor.Rok() == m_nRok && wzor.Miesiac() > m_nMiesiac)
		x = 1;
	else if (wzor.Rok() == m_nRok && wzor.Miesiac() == m_nMiesiac && wzor.Dzien() > m_nDzien)
		x = 1;
		return x;
}


Data::Data(int d, int m, int r)
{
	m_nDzien = d;
	m_nRok = r;
	m_nMiesiac = m;
}
Data::~Data()
{
}

std::ostream & operator<<(std::ostream &wy, const Data &d) {
	wy << d.m_nDzien << "-" << d.m_nMiesiac << "-" << d.m_nRok;
	return wy;
}
std::istream & operator >> (std::istream &we, Data & d) {
	we >> d.m_nDzien;
	we >> d.m_nMiesiac;
	we >> d.m_nRok;
	return we;
}
