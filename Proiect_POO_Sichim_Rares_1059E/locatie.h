#pragma once
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#pragma warning(disable:4996)

class Locatie
{
private:
	int nr_zone;
	int nr_randuri;
	int* locuri;//vectorul ce contine numarul de locuri de pe fiecare rand

public:
	Locatie() {
		nr_zone = 0;
		nr_randuri = 0;
		locuri = NULL;
	}

	Locatie(int nr_zone, int nr_randuri, int* locuri) {
		this->nr_zone = nr_zone;
		this->nr_randuri = nr_randuri;
		if (nr_randuri > 0)
		{
			this->locuri = new int[nr_randuri];
			for (int i = 0; i < nr_randuri; i++)
				this->locuri[i] = locuri[i];
		}
		else locuri = NULL;

	}
	~Locatie() {
		if (locuri != NULL) delete[]locuri;
		locuri = NULL;
	}

	Locatie(const Locatie& l) {
		this->nr_zone = l.nr_zone;
		this->nr_randuri = l.nr_randuri;
		if (l.locuri != NULL)
		{
			this->locuri = new int[l.nr_randuri];
			for (int i = 0; i < l.nr_randuri; i++)
				this->locuri[i] = l.locuri[i];
		}
	}

	Locatie& operator=(Locatie& l) {
		this->nr_zone = l.nr_zone;
		if (l.nr_randuri > 0)
		{
			this->nr_randuri = l.nr_randuri;
			if (this->locuri != NULL)
				delete[]this->locuri;
			if (l.locuri != NULL) {
				this->locuri = new int[l.nr_randuri];
				for (int i = 0; i < nr_randuri; i++)
					this->locuri[i] = l.locuri[i];
			}
		}
		return *this;
	}

	int getNrZone() {
		return this->nr_zone;
	}

	void setNrZone(int nr_zone) {
		this->nr_zone = nr_zone;
	}

	int getNrRanduri() {
		return nr_randuri;
	}

	void setNrRanduri(int nr_randuri) {
		this->nr_randuri = nr_randuri;
	}

	int* getLocuri() {
		int* copie = new int[nr_randuri];
		for (int i = 0; i < nr_randuri; i++)
			copie[i] = locuri[i];
		return copie;
	}

	void setLocuri(int* locuri, int nr_randuri) {
		if (nr_randuri > 0 && locuri != NULL)
		{
			if (this->locuri != NULL)delete[]this->locuri;
			this->nr_randuri = nr_randuri;
			this->locuri = new int[nr_randuri];
			for (int i = 0; i < nr_randuri; i++)
				this->locuri[i] = locuri[i];
		}
		else {
			this->locuri = NULL;
			this->nr_randuri = 0;
		}
	}

	int& operator[](int index)//cate locuri se afla pe randul index
	{
		if (index > 0 && index < nr_randuri)
			return locuri[index];
		cout << endl<<"Randul introdus nu exista"<<endl;

	}

	friend Locatie operator++(Locatie& t) {
		t.nr_zone++;
		return t;
	}


	int nr_total_locuri()
	{
		int n = 0;
		for (int i = 0; i < nr_randuri; i++)
			n += this->locuri[i];
		return n;
	}

	friend int diferenta_locuri(Locatie l1, Locatie l2)//Cu cate locuri sunt mai multe intr-o locatie fata de alta
	{
		if (l1.nr_total_locuri() > l2.nr_total_locuri())
		{
			return l1.nr_total_locuri() - l2.nr_total_locuri();
		}
		else {
			return abs(l1.nr_total_locuri() - l2.nr_total_locuri());
		}
	}

	friend istream& operator>>(istream& in, Locatie& l) {
		cout << "Numarul de zone: ";
		in >> l.nr_zone;
		cout << "Numar de randuri: ";
		in >> l.nr_randuri;
		cout << "Numarul locurilor de pe fiecare rand: ";
		l.locuri = new int[l.nr_randuri];
		for (int i = 0; i < l.nr_randuri; i++)
			in >> l.locuri[i];

		return in;
	}

	friend ostream& operator<<(ostream& out, Locatie& l) {
		out << "-----------Locatie--------"<<endl;
		out << "Numarul de zone este " << l.nr_zone << endl;
		out << "Numarul randurilor este " << l.nr_randuri << endl;
		if (l.nr_randuri > 0) {
			out << "Numarul locurilor de pe fiecare rand este: ";
			for (int i = 0; i < l.nr_randuri; i++)
				out << l.locuri[i] << " ";
		}
		else out << "-";
		out << endl;
		return out;
	}

};
