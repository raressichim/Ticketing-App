#pragma once
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
#pragma warning(disable:4996)
class Eveniment
{
private:
	string denumire;
	int zi;
	int luna;
	int an;
	int ora;
	int minute; //Ora evenimentului va fi de forma ora:minute (exemplu: 19:45 )
public:
	Eveniment() {
		denumire = "Necunoscuta";
		zi = 0;
		luna = 0;
		an = 0;
		ora = -1;
		minute = -1;
	}

	Eveniment(string denumire, int zi, int luna, int an, int ora, int minute) {
		this->denumire = denumire;
		this->zi = zi;
		this->luna = luna;
		this->an = an;
		this->ora = ora;
		this->minute = minute;
	}

	~Eveniment() {}

	string getDenumire() {
		return this->denumire;
	}

	void setDenumire(string denumire) {
		if (denumire != "Necunoscuta")
			this->denumire = denumire;
	}

	int getZi() {
		return this->zi;
	}
	void setZi(int zi) {
		this->zi = zi;
	}

	int getLuna() {
		return this->luna;
	}

	void setLuna(int luna) {
		this->luna = luna;
	}

	int getAn() {
		return this->an;
	}

	void setAn(int an) {
		this->an = an;
	}

	int getOra() {
		return this->ora;
	}

	void setOra(int ora) {
		if (ora != -1)
			this->ora = ora;
	}

	int getMinute() {
		return this->minute;
	}

	void setMinute(int minute) {
		this->minute = minute;
	}

	friend Eveniment operator--(Eveniment& e) {
		if (e.ora = 0)
		{
			e.ora = 23;
			if (e.zi = 1) {
				e.zi = 31;
				if (e.luna = 1) {
					e.luna = 12;
					e.an--;
				}
				else e.luna--;
			}
			else e.zi--;
		}
		else e.ora--;
		return e;
	}

	friend bool operator!(Eveniment e) {
		return e.ora != -1; //se compara cu -1 deoarece ora poate avea valoarea 0 (12PM)
	}

	void intarziere(int ora, int minute) {    //se presupune ca ora de incepere a evenimentului este amanata
		this->ora += ora;
		if (this->ora >= 24) this->ora = this->ora - 24;
		this->minute += minute;
		if (this->minute > 60) this->minute = this->minute - 60;
	}

	friend string primul(Eveniment e1, Eveniment e2) {
		if (e1.an < e2.an) return e1.denumire;
		else if (e1.an > e2.an) return e2.denumire;
		else {
			if (e1.luna < e2.luna) return e1.denumire;
			else if (e1.luna > e2.luna) return e2.denumire;
			else {
				if (e1.zi < e2.zi) return e1.denumire;
				else if (e1.zi > e2.zi) return e2.denumire;
				else {
					if (e1.ora < e2.ora) return e1.denumire;
					else if (e1.ora > e2.ora) return e2.denumire;
					else {
						if (e1.minute < e2.minute) return e1.denumire;
						else if (e1.minute > e2.minute) return e2.denumire;
						return "Evenimentele incep in acelasi timp";
					}
				}
			}
		}
	}

	friend istream& operator>>(istream& in, Eveniment e) {
		cout << "Denumirea filmului: ";
		in >> e.denumire;
		cout << "Zi: ";
		in >> e.zi;
		cout << "Luna: ";
		in >> e.luna;
		cout << "An: ";
		in >> e.an;
		cout << "Ora: ";
		in >> e.ora;
		cout << "Minutele: ";
		in >> e.minute;
		return in;
	}

	friend ostream& operator<<(ostream& out, Eveniment e) {
		out << "Denumirea evenimentului este '" << e.denumire << "'" << endl;
		out << "Data sa este " << e.zi << "." << e.luna << "." << e.an << endl;
		if (e.ora == 0) out << "Evenimentul incepe la 00:";
		else out << "Evenimentul incepe la ora: " << e.ora << ":";
		if (e.minute == 0)
			out << "00" << endl;
		else
			out << e.minute << endl;
		return out;
	}
};