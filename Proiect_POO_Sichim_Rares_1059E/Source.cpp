#include "bilet.h"
#include "bilet_cu_loc.h"
#include "eveniment.h"
#include "locatie.h"
#include "taxa.h"
int main(int nr_argumente,char* valori[])
{
	////FAZA1--------------------------------------------------
	//Bilet b1; //constructor implicit
	//cout << b1;
	//int v[]{ 20,30,40 };
	//Bilet b2(50, "normal", 3, v); //constructor cu parametrii
	//b2.scriere_binar();
	//cout << b2;
	//Bilet b3 = b2; //operator =
	//cout << b3;
	//Bilet b4(b1); //constructor copiere
	//cout << b4;
	//Bilet b5 = b2 + b3; //50+50=100
	//cout << b5;
	//int a=(int)b2;//operator cast explicit
	//cout << a<<endl;
	//cout << b2.suma_cheltuita()<<endl;//20+30+40=90
	//Bilet t[]{ b1,b2,b3};
	//cout << Bilet::CelMaiScumpBilet(t, 3)<<endl;
	//Bilet b6(70, "vip", 3, v);
	//cout << b6.getID()<<endl;
	//b3.setPret(12);
	//cout << b3.getPret()<<endl;
	//char* cat = new char[4];
	//strcpy(cat, "vip");
	//b3.setCategorie(cat);
	//cout << b3. getCategorie() << endl;
	//b3.setNrPlati(1);
	//cout << b3.getNrPlati()<<endl;
	//int y[]{ 10,20 };
	//b3.setIncarcari(y, 2);
	//Bilet b7;
	//cin >> b7;

	//Eveniment e1,e2;
	//cout << e1;
	////cin >> e2;
	//Eveniment e3("James Bond", 10, 11, 2022, 12, 30);
	//cout << e3;
	//Eveniment e4;
	//e4 = --e3;
	//cout << e4;
	//cout <<!e1<<" "<<!e3<<endl;
	//e3.intarziere(2, 10);
	//cout << e3.getOra() << ":" << e3.getMinute() << endl;
	//cout << primul(e3, e4) << endl;
	//cout << primul(e3, e3)<<endl;

	//int l[]{ 20,25,30 };
	//Locatie l1(4,3,l);
	//cout << l1;
	//Locatie l2; 
	//cin >> l2;
	//Locatie l3(l1);
	//cout << l3;
	//Locatie l4 = l1;
	//cout << l4;
	//cout << l1[2] << endl;
	//Locatie l5 = ++l4;
	//cout << l5.getNrZone() << endl;
	//cout << l1.nr_total_locuri()<<endl; //20+25+30=75
	//int q[]{ 20,30,40,10 };
	//Locatie l6(7, 4, q);
	//cout<<diferenta_locuri(l1, l6)<<endl;//100-75
	//Locatie l7;
	//cout<< l7;

	//Faza2-------------------------------------------------------------------------
	//cout << endl;s
	//
	//cout << b2.tva() << endl; //metoda virtual pura tva
	//b2.upgrade(); //metoda virtuala
	//b6.upgrade();
	//cout << endl;
	//char* cat1 = new char[7];
	//strcpy(cat1, "normal");
	//Bilet_cu_loc bl1("A",1,3,30,cat,3,v);
	//cout << bl1;
	//cout << endl;
	//Bilet_cu_loc bl2;
	//cin >> bl2;
	//cout << endl;
	//Bilet_cu_loc bl3(bl1);
	//cout << bl3;
	//Bilet_cu_loc bl5;
	//bl5 = bl1;
	//cout << bl5;
	//cout << endl;
	//Bilet_cu_loc bl6("B", 3, 3, 20, cat1, 3, v);
	//bl1.upgrade();
	//bl6.upgrade();
	//bl6.setZona("C");
	//cout << bl6.getZona() << endl;
	//bl6.setRand(4);
	//cout << bl6.getRand() << endl;
	//bl6.setLoc(3);
	//cout << bl6.getLoc() << endl;
	Bilet B;
	Bilet_cu_loc BL;
	Eveniment E;
	Locatie L;
	int x=1;
	cout << "-----------Ticketing App---------------" << endl;
	while (x != 0) {
		cout << endl;
		cout << "Pentru afisarea datelor din fisierul text apasati 1" << endl;
		cout << "Pentru introducerea unor date de la tastatura: " << endl;
		cout << "2->Bilet" << endl;
		cout << "3->Bilet cu loc" << endl;
		cout << "4->Eveniment" << endl;
		cout << "5->Locatie" << endl;
		cout << "Pentru a iesi apasati 0" << endl;
		cout << "Alegeti o optiune: ";
		cin >> x;
		if (x == 1) {
			ifstream f;
			f.open("fisier.txt", ios::in);
			string c;
			getline(f, c);
			while (strcmp(c.c_str(), "/") != 0) {
				int p = 0, nrp = 0;
				char* ch = new char[20];
				strcpy(ch, c.c_str());
				f >> p >> nrp;
				int* y = new int[nrp];
				for (int i = 0; i < nrp; i++)
					f >> y[i];
				Bilet b(p, ch, nrp, y);
				b.scriere_binar();
				cout << b;
				getline(f, c);
				delete[]ch;
				delete[]y;
				getline(f, c);
			}
			f.close();
		}
		else if (x == 2) {
			cout << endl;
			cin >> B;
			cout << B;
			B.scriere_binar();
			while (x != 9) {
				cout << endl;
				cout << "Pentru biletul acesta aveti urmatoarele optiuni: " << endl;
				cout << "6->suma cheluita" << endl;
				cout << "7->tva" << endl;
				cout << "8->posibilitatea de a face upgrade la urmatoarea categorie/se percepe o taxa in valoare de 50 RON" << endl;
				cout << "9->inapoi"<<endl;
				cin >> x;
				if (x == 6) cout << "Suma cheltuita este: " << B.suma_cheltuita() << endl;
				else if (x == 7) cout << "Tva-ul este in valoare de: " << B.tva() << endl;
				else if (x == 8) B.upgrade();
			}
			BL.scriere_binar();
			cout << endl;
		}
		else if (x == 3) {
			cout << endl;
			cin >> BL;
			cout << endl;
			cout << "10->Doriti sa faceti upgrade la urmatoare categorie?" << endl;
			cout << "11->inapoi" << endl;
			cin >> x;
			if (x == 10) BL.upgrade();
			BL.scriere_binar();
			cout << endl;
		}
		else if (x == 4)
		{
			cin >> E;
			cout << E;
			while (x != 13) {
				cout << endl;
				cout << "12->intarzierea evenimentului" << endl;	
				cout << "13->inapoi" << endl;
				cin >> x;
				if (x == 12) {
					cout << "Evenimentul intarzie cu ";
					int a, b;
					cin >> a;
					cout << "ore si ";
					cin >> b;
					cout << " minute" << endl;
					E.intarziere(a, b);
				}
			}
		}
		else if (x == 5)
		{
				cin >> L;
				cout << L;
				while (x != 17) {
				cout << endl;
				cout << "14->Numarul locurilor de randul dorit" << endl;
				cout << "15->Numarul total de locuri" << endl;
				cout << "16->Marirea numarului de zone cu o unitate" << endl;
				cout << "17->inapoi" << endl;
				cin >> x;
				if (x == 14)
				{
					int k;
					cout << "Randul: ";
					cin >> k;
					cout << endl;
					cout << L[k] << endl;
				}
				else if (x == 15) {
					cout << "Locatia are " << L.nr_total_locuri() << " locuri" << endl;
				}
				else if (x == 16) {
					++L;
					cout << L;
				}
			}
		}
		else exit(0);
	}

}