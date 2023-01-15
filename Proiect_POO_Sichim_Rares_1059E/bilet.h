#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include"taxa.h"
using namespace std;
#pragma warning(disable:4996)
 
class Bilet :public Taxa
{
protected:
	const int id = 0;
	static int bilete_tiparite; //contorul pentru id
	float pret;
	char* categorie;
	//consideram ca cel care a cumparat biletul face mai multe plati pe platforma 
	//pentru a isi incarca contul cu o anumita suma pentru a putea achizitiona diferite produse in timpul evenimentului
	int nr_plati;
	int* incarcari;

public:
	Bilet() :id(0)
	{
		pret = 0;
		nr_plati = 0;
		categorie = new char[12];
		strcpy(categorie, "necunoscuta");
		incarcari = NULL;
	}
	Bilet(int pret, const char* categorie, int nr_plati, int* incarcari) :id(++bilete_tiparite)
	{
		this->pret = pret;
		this->categorie = new char[strlen(categorie) + 1];
		strcpy(this->categorie, categorie);
		this->nr_plati = nr_plati;

		if (nr_plati > 0)
		{
			this->incarcari = new int[nr_plati];
			for (int i = 0; i < nr_plati; i++)
				this->incarcari[i] = incarcari[i];
		}
		else this->incarcari = NULL;
	}

	Bilet(const Bilet& b) :id(b.id)
	{
		this->pret = b.pret;
		if (b.categorie != NULL)
			this->categorie = new char[strlen(b.categorie) + 1];

		strcpy(this->categorie, b.categorie);

		this->nr_plati = b.nr_plati;
		if (b.incarcari != NULL)
			this->incarcari = new int[b.nr_plati];
		for (int i = 0; i < b.nr_plati; i++)
			this->incarcari[i] = b.incarcari[i];
	}

	~Bilet() {
		if (this->categorie != NULL) delete[]this->categorie;
		this->categorie = NULL;
		if (this->incarcari != NULL) delete[]this->incarcari;
		this->incarcari = NULL;
	}

	Bilet& operator=(const Bilet& b) 
	{
		if (this != &b) {
			this->pret = b.pret;
			if (this->categorie != NULL)
				delete[] this->categorie;

			if (b.categorie != NULL)
				this->categorie = new char[strlen(b.categorie) + 1];

			strcpy(this->categorie, b.categorie);

			this->nr_plati = b.nr_plati;

			if (this->incarcari != NULL)
				delete[] this->incarcari;

			if (b.incarcari != NULL) {
				this->incarcari = new int[b.nr_plati];

				for (int i = 0; i < b.nr_plati; ++i)
					this->incarcari[i] = b.incarcari[i];
			}
		}
		return *this;

	}

	int getID() {
		return this->id;
	}

	float getPret() {
		return this->pret;
	}

	void setPret(float pret) {
		if (pret > 0 ) this->pret = pret;
	}

	char* getCategorie() {
		return this->categorie;
	}

	void setCategorie(char* categorie) {
		if (categorie != NULL) {
			delete[]this->categorie;
			this->categorie = new char[strlen(categorie) + 1];
			strcpy(this->categorie, categorie);
		}
	}

	int getNrPlati() {
		return this->nr_plati;
	}

	void setNrPlati(int nr_plati) {
		if (nr_plati > 0 ) this->nr_plati = nr_plati;
	}

	int* getIncarcari() {	
		if (incarcari != nullptr) {
			int* copie = new int[this->nr_plati];
			for (int i = 0; i < this->nr_plati; i++)
				copie[i] = this->incarcari[i];
			return copie;
		}
		else return nullptr;
	}

	void setIncarcari(int* v, int nr_plati) {
		if (nr_plati > 0 && v != NULL) {
			if (this->incarcari != NULL) delete[]this->incarcari;
			this->nr_plati = nr_plati;
			this->incarcari = new int[nr_plati];
			for (int i = 0; i < nr_plati; i++)
				this->incarcari[i] = v[i];
		}
		else {
			this->incarcari = NULL;
			nr_plati = 0;
		}
	}

	friend Bilet& operator+(Bilet& b1, Bilet& b2) {
		b1.pret += b2.pret;
		return b1;
	}

	explicit operator int()
	{
		return pret;
	}

	int suma_cheltuita() {
		int suma = 0;
		for (int i = 0; i < nr_plati; i++)
			suma += incarcari[i];
		return suma;
	}

	void scriere_binar()
	{
		ofstream f("bilete.bin", ios::binary);
		f.write((char*)&id, sizeof(id));
		f.write((char*)&pret, sizeof(pret));

		int lungime = strlen(categorie);
		f.write((char*)&lungime, sizeof(lungime));
		f.write(categorie, (lungime + 1)*sizeof(char));

		f.write((char*)&nr_plati, sizeof(nr_plati));
		for (int i=0; i < nr_plati; i++)
		{
			f.write((char*)&incarcari[i], sizeof(incarcari[i]));
		}
		f.close();
	}

	void citire_binar()
	{
		ifstream f("bilete.bin",ios::binary);
		f.read((char*)&id, sizeof(id));
		f.read((char*)&pret, sizeof(pret));
		
		int lungime = 0;
		f.read((char*)&lungime, sizeof(lungime));
		char* sir = new char[lungime + 1];
		f.read(sir, lungime + 1);
		strcpy(categorie, sir);
		delete[]sir;

		f.read((char*)&nr_plati, sizeof(nr_plati));
		delete[]incarcari;
		incarcari = new int[nr_plati];
		for (int i=0; i < nr_plati; i++)
		{
			f.read((char*)&incarcari[i], sizeof(incarcari[i]));
		}
		f.close();
	}

	float tva() {
		return pret * 19 / 100;
	}

	//verifica daca biletul cumparat poate fi upgradat la o categorie superioara
	virtual void upgrade() {
		if (strcmp(categorie, "vip") == 0 || strcmp(categorie, "VIP") == 0 || strcmp(categorie, "Vip") == 0) cout << "Biletul dumneavoastra "<<id<<" nu poate fi upgradat";
		else
		{
			cout << "Biletul dumneavostra " << id << " a fost upgradat";
			delete[]categorie;
			categorie = new char[4];
			strcpy(categorie, "vip");
			pret += 50;
		}
		cout << endl;
	}

	//returneaza id-ul primului cumparator care a cumparat cel mai scump bilet dintr-un vector de bilete
	static int CelMaiScumpBilet(Bilet* v, int n) { 
		int maxim = -1, k = 0;
		for (int i = 0; i < n; i++)
			if (v[i].pret > maxim) {
				maxim = v[i].pret;
				k = i;
			}
		return v[k].id;
	}

	static int getBileteTiparite() {
		return bilete_tiparite;
	}


	friend istream& operator>>(istream& in, Bilet& b) { 
		char buffer[101];
		cout << "Pretul: ";
		in >> b.pret;
		cout << "Categoria: ";
		cin >> buffer;
		b.categorie = new char[strlen(buffer) + 1];
		strcpy(b.categorie, buffer);
		cout << "Numarul platilor: ";
		in >> b.nr_plati;
		b.incarcari = new int[b.nr_plati];
		cout << "Valorile platilor: ";
		for (int i = 0; i < b.nr_plati; i++)
			in >> b.incarcari[i];
		return in;
	}

	friend ostream& operator<<(ostream& out, Bilet& b) {
		out << "-----------Bilet "<<b.id<<"--------------"<<endl;
		out << "Pret: " << b.pret << endl;
		out << "Categorie: " << b.categorie << endl;
		out << "Numarul platilor efectuate: " << b.nr_plati << endl;
		out << "Valorile fiecarei plati: ";
		for (int i = 0; i < b.nr_plati; i++)
			out << b.incarcari[i] << " ";
		out << endl;
		return out;
	}

	/*friend ofstream& operator<<(ofstream& f, Bilet& b) {
		f << b.pret << endl;
		f << b.categorie << endl;
		f  << b.nr_plati << endl;
		for (int i = 0; i < b.nr_plati; i++)
			f << b.incarcari[i] << endl;
		return f;
	}*/

};
int Bilet::bilete_tiparite = 0;