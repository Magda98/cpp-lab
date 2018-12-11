#pragma once
#include <string.h>
#include <iostream>


class Napis
{

private:
	char *m_pszNapis;
	int m_nDl;
public:
	const char* Zwroc() const;
	void Ustaw(const char* nowy_napis);
	void Wypisz() const;
	void Wpisz();
	int SprawdzNapis(const char* por_napis) const;
	Napis(const char *nap = "");
	Napis(const Napis &wzor);
	~Napis();

	Napis & operator=(const Napis &wzor);
	bool operator==(const Napis &wzor) const;
	friend std::ostream &operator<<(std::ostream &wy, const Napis &p);
	friend std::istream &operator>>(std::istream &we, Napis &p);
};

