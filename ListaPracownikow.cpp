#include "ListaPracownikow.h"



void ListaPracownikow::Dodaj(const Pracownik & p)
{
	Pracownik *k = new Pracownik(p);
	Pracownik *ap = m_pPoczatek;

	if (m_nLiczbaPracownikow == 0) {
		m_pPoczatek = k;
		k->m_pNastepny = nullptr;
		m_nLiczbaPracownikow++;
	}
	else if(p.Porownaj(*ap) < 0){
		k->m_pNastepny = m_pPoczatek;
		m_pPoczatek = k;
		m_nLiczbaPracownikow++;
	}
	else if (p.Porownaj(*ap) > 0)
	{
		while(true){
			if (ap->m_pNastepny == nullptr) {
				ap->m_pNastepny = k;
				m_nLiczbaPracownikow++;
				break;
			}
			if (p.Porownaj(*(ap->m_pNastepny)) < 0)
			{
				k->m_pNastepny = ap->m_pNastepny;
				ap->m_pNastepny = k;
				m_nLiczbaPracownikow++;
				break;
			}
			else
			{
				ap = ap->m_pNastepny;
			}
		}
	}
	
}

void ListaPracownikow::Usun(const Pracownik & wzorzec)
{
	Pracownik *ap = m_pPoczatek;
	if (m_pPoczatek == &wzorzec) {
		m_pPoczatek = ap->m_pNastepny;
		m_nLiczbaPracownikow--;
		return;
	}

	for (int i = 1; i < m_nLiczbaPracownikow; i++) {
		if (ap->m_pNastepny == &wzorzec) {
			ap->m_pNastepny = (ap->m_pNastepny)->m_pNastepny;
			m_nLiczbaPracownikow--;
			return;
		}
		ap = ap->m_pNastepny;
	}
}

void ListaPracownikow::WypiszPracownikow() const
{
	Pracownik *ap = m_pPoczatek;
	for(int i = 0; i < m_nLiczbaPracownikow; i++){
		ap->Wypisz();
		ap = ap->m_pNastepny;
	}
}

const Pracownik * ListaPracownikow::Szukaj(const char * nazwisko, const char * imie) const
{
	Pracownik *ap = m_pPoczatek;
	for (int i = 0; i < m_nLiczbaPracownikow; i++)
	{
		if (ap->SprawdzImie(imie) == 0 && ap->SprawdzNazwisko(nazwisko) == 0 )
			return ap;

		ap = ap->m_pNastepny;
	}
	return nullptr;
}

ListaPracownikow::ListaPracownikow()
{
	m_pPoczatek = nullptr;
	m_nLiczbaPracownikow = 0;
}


ListaPracownikow::~ListaPracownikow()
{
}
