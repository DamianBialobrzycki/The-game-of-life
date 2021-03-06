// The game of life.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct komorka
{
	char stan;
	bool odwiedzona;
};

struct swiat
{
	komorka ** komorki;
	int szerokoscMapy, wysokoscMapy, liczbaTur, wielkoscGrupy, najwiekszaWielkoscGrupy, obecnaTura;

	swiat();
	swiat(int szerokosc, int wysokosc);
	~swiat();

	void NastepnaTura(swiat * s);
	void Skanuj();
	void SkanujSasiadow(int i, int j);
	void RysujMape();
	void WczytajMape();
	char NowyStan(int wiersz, int kolumna);
	int PoliczSasiadow(int wiersz, int kolumna);
};

swiat::swiat()
{
	komorki = NULL;
	szerokoscMapy = 0;
	wysokoscMapy = 0;
	liczbaTur = 0;
	wielkoscGrupy = 0;
	najwiekszaWielkoscGrupy = 0;
	obecnaTura = 0;
}

swiat::swiat(int szerokosc, int wysokosc)
{
	szerokoscMapy = szerokosc;
	wysokoscMapy = wysokosc;
	komorki = new komorka *[wysokosc];
	for (int i = 0; i < wysokosc; i++)
	{
		komorki[i] = new komorka[szerokosc];
	}
	for (int i = 0; i < wysokosc; i++)
	{
		for (int j = 0; j < szerokosc; j++)
		{
			komorki[i][j].stan = '.';
			komorki[i][j].odwiedzona = false;
		}
	}

	liczbaTur = 0;
	wielkoscGrupy = 0;
	najwiekszaWielkoscGrupy = 0;
	obecnaTura = 0;
}

swiat::~swiat()
{
	for (int i = 0; i < wysokoscMapy; i++)
		delete[] komorki[i];
	delete[] komorki;
}

void swiat::WczytajMape()
{
	cin >> szerokoscMapy;
	cin >> wysokoscMapy;
	cin >> liczbaTur;

	komorki = new komorka *[wysokoscMapy];
	for (int i = 0; i < wysokoscMapy; i++)
		komorki[i] = new komorka[szerokoscMapy];

	for (int i = 0; i < wysokoscMapy; i++)
	{
		for (int j = 0; j < szerokoscMapy; j++)
		{
			cin >> komorki[i][j].stan;
			komorki[i][j].odwiedzona = false;
		}
	}
}

void swiat::RysujMape()
{
	for (int i = 0; i < wysokoscMapy; i++)
	{
		for (int j = 0; j < szerokoscMapy; j++)
		{
			cout << komorki[i][j].stan;
		}
		cout << endl;
	}
}

int swiat::PoliczSasiadow(int wiersz, int kolumna)
{
	int iloscSasiadow = 0;
	int tmpWiersz = 0;
	int tmpKolumna = 0;


	if (wiersz + 1 < wysokoscMapy)
		if (komorki[wiersz + 1][kolumna].stan == '#')
			iloscSasiadow++;
	if (wiersz - 1 >= 0)
		if (komorki[wiersz - 1][kolumna].stan == '#')
			iloscSasiadow++;

	if (kolumna + 1 < szerokoscMapy)
		if (komorki[wiersz][kolumna + 1].stan == '#')
			iloscSasiadow++;

	if (kolumna - 1 >= 0)
		if (komorki[wiersz][kolumna - 1].stan == '#')
			iloscSasiadow++;

	if (kolumna + 1 < szerokoscMapy && wiersz + 1 < wysokoscMapy)
		if (komorki[wiersz + 1][kolumna + 1].stan == '#')
			iloscSasiadow++;

	if (kolumna + 1 < szerokoscMapy && wiersz - 1 >= 0)
		if (komorki[wiersz - 1][kolumna + 1].stan == '#')
			iloscSasiadow++;

	if (kolumna - 1 >= 0 && wiersz - 1 >= 0)
		if (komorki[wiersz - 1][kolumna - 1].stan == '#')
			iloscSasiadow++;

	if (kolumna - 1 >= 0 && wiersz + 1 < wysokoscMapy)
		if (komorki[wiersz + 1][kolumna - 1].stan == '#')
			iloscSasiadow++;


	return iloscSasiadow;
}

char swiat::NowyStan(int wiersz, int kolumna)
{
	int iloscSasiadow = PoliczSasiadow(wiersz, kolumna);

	if (iloscSasiadow == 3)
		return '#';
	else if (iloscSasiadow == 2)
		return komorki[wiersz][kolumna].stan;
	else
		return '.';
}

void swiat::NastepnaTura(swiat * s)
{
	swiat * tmpS = new swiat(s->szerokoscMapy, s->wysokoscMapy);

	for (int i = 0; i < wysokoscMapy; i++)
	{
		for (int j = 0; j < szerokoscMapy; j++)
		{
			tmpS->komorki[i][j].stan = s->NowyStan(i, j);
		}
	}


	for (int i = 0; i < wysokoscMapy; i++)
	{
		for (int j = 0; j < szerokoscMapy; j++)
		{
			s->komorki[i][j].stan = tmpS->komorki[i][j].stan;
		}
	}

	delete tmpS;
}

void swiat::Skanuj()
{
	for (int i = 0; i < wysokoscMapy; i++)
	{
		for (int j = 0; j < szerokoscMapy; j++)
		{
			if (komorki[i][j].stan == '#' && komorki[i][j].odwiedzona == false)
			{
				komorki[i][j].odwiedzona = true;
				wielkoscGrupy++;

				SkanujSasiadow(i, j);

				if (wielkoscGrupy > najwiekszaWielkoscGrupy)
					najwiekszaWielkoscGrupy = wielkoscGrupy;
				wielkoscGrupy = 0;
			}
		}
	}
}

void swiat::SkanujSasiadow(int i, int j)
{
	for (int a = -2; a <= 2; a++)
	{
		for (int b = -2; b <= 2; b++)
		{
			int tmpWiersz = 0;
			int tmpKolumna = 0;


			if (i + a < 0 || i + a > wysokoscMapy - 1)
				continue;
			if (j + b < 0 || j + b > szerokoscMapy - 1)
				continue;

			tmpWiersz = a + i;
			tmpKolumna = b + j;

			if (komorki[tmpWiersz][tmpKolumna].stan == '#' && komorki[tmpWiersz][tmpKolumna].odwiedzona == false)
			{
				komorki[tmpWiersz][tmpKolumna].odwiedzona = true;
				wielkoscGrupy++;
				SkanujSasiadow(tmpWiersz, tmpKolumna);
			}
		}
	}
}

int main()
{
	swiat * s = new swiat;

	s->WczytajMape();

	for (int i = 0; i < s->liczbaTur; i++)
	{
		/*cout << endl;
		cout << "Tura " << i << endl;
		cout << endl;
		s->RysujMape();*/
		s->NastepnaTura(s);
	}
	//s->RysujMape();
	s->Skanuj();
	cout << s->najwiekszaWielkoscGrupy << endl;


	delete s;
	return 0;
}

