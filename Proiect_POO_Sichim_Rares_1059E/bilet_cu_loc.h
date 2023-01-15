#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include <fstream>
using namespace std;
#pragma warning(disable:4996)
#include "bilet.h"

class Bilet_cu_loc :public Bilet
{
private:
	string zona;
	int rand;
	int loc;
public:
	Bilet_cu_loc() {
		zona = "Necunoscuta";
		rand = -1;
		loc = -1;
	}

	Bilet_cu_loc(string zona,int rand, int loc,int pret,char*categorie,int nr_plati,int* incarcari ) :Bilet(pret,categorie,nr_plati,incarcari)
	{
		this->zona = zona;
		this->rand = rand;
		this->loc = loc;
	}

	~Bilet_cu_loc(){}

	Bilet_cu_loc(const Bilet_cu_loc& bl) :Bilet(bl)
	{

		this->zona = bl.zona;
		this->rand = bl.rand;
		this->loc = bl.loc;
	}

	Bilet_cu_loc& operator=(const Bilet_cu_loc& bl) {
		if (this != &bl) {
			Bilet::operator=(bl);
			this->zona = bl.zona;
			this->rand = bl.rand;
			this->loc = bl.loc;
		}
		return *this;
	}

	string getZona() {
		return zona;
	}

	void setZona(string zona) {
		this->zona = zona;
	}
	
	int getRand() {
		return this->rand;
	}

	void setRand(int rand) {
		this->rand = rand;
	}

	int getLoc() {
		return this->loc;
	}

	void setLoc(int loc) {
		this->loc = loc;
	}

	void scriere_binar()
	{
			ofstream f("bilete_cu_loc.bin", ios::binary);
			f.write((char*)&id, sizeof(id));
			f.write((char*)&pret, sizeof(pret));

			int lungime = strlen(categorie);
			f.write((char*)&lungime, sizeof(lungime));
			f.write(categorie, (lungime + 1) * sizeof(char));

			f.write((char*)&nr_plati, sizeof(nr_plati));
			for (int i = 0; i < nr_plati; i++)
			{
				f.write((char*)&incarcari[i], sizeof(incarcari[i]));
			}
		int dim = zona.length();
		f.write((char*)&dim, sizeof(dim));
		f.write(zona.c_str(), dim + 1);
		f.write((char*)&rand, sizeof(rand));
		f.write((char*)&loc, sizeof(loc));
		f.close();
	}

	void citire_binar()
	{
		ifstream f("bilete.bin", ios::binary);
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
		for (int i = 0; i < nr_plati; i++)
		{
			f.read((char*)&incarcari[i], sizeof(incarcari[i]));
		}
		int dim = 0;
		f.read((char*)&dim, sizeof(dim));
		char* n = new char[dim + 1];
		f.read(n, dim + 1);
		zona = n;
		delete[]n;
		f.read((char*)&rand, sizeof(rand));
		f.read((char*)&loc, sizeof(loc));
		f.close();
	}

	void upgrade() {
		if (rand == 1 ) cout << "Biletul dumneavoastra " <<id<<" nu poate fi upgradat";
		else {
			cout << "Biletul dumneavoastra " << id << " a fost upgradat";
			delete[]categorie;
			categorie = new char[4];
			strcpy(categorie, "vip");
			pret += 50;
		}
		cout << endl;
	}

	friend istream& operator>>(istream& in, Bilet_cu_loc& bl) {
		in >> (Bilet&)bl;
		cout << "Randul: ";
		in >> bl.rand;
		cout << "Locul: ";
		in >> bl.loc;
		return in;
	}

	friend ostream& operator<<(ostream& out, Bilet_cu_loc& bl) {
		out << "-----------Bilet " << bl.id << "--------------"<<endl;
		out << "Pret: " << bl.pret << endl;
		out << "Categorie: " << bl.categorie << endl;
		out << "Rand: " << bl.rand << endl;
		out << "Loc: " << bl.loc << endl;
		out << "Numarul platilor efectuate: " << bl.nr_plati << endl;
		out << "Valorile fiecarei plati: ";
		for (int i = 0; i < bl.nr_plati; i++)
			out << bl.incarcari[i] << " ";
		out << endl;
		return out;

	}

	friend ofstream& operator<<(ofstream& f, Bilet_cu_loc& bl) {
		f << bl.pret << endl;
		f << bl.categorie << endl;
		f << bl.rand << endl;
		f << bl.loc << endl;
		f << bl.nr_plati << endl;
		for (int i = 0; i < bl.nr_plati; i++)
			f << bl.incarcari[i] << endl;
		return f;
	}
};