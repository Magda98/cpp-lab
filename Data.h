#pragma once
#include <iostream>
//#include <ostream>
class Data
{
private:
	int m_nDzien;
	int m_nMiesiac;
	int m_nRok;
	void Koryguj();
public:
	void  Ustaw(int d, int m, int r);
	int Dzien() const;
	int Miesiac() const;
	int Rok() const;
	void Wypisz() const;
	void Wpisz();
	int Porownaj(const Data & wzor) const;
	Data(int d, int m, int r);
	~Data();
	friend std::ostream & operator<<(std::ostream &wy, const Data &d);
	friend std::istream & operator>>(std::istream &we, Data & d);
};




