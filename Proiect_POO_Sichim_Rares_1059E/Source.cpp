#include "bilet.h"
#include "eveniment.h"
#include "locatie.h"

int main()
{
	Bilet b1;
	int v[]{ 10,20,50 };
	Bilet b2(2000, "A", 3, v);
	Bilet b3(b2);
	Bilet b4(5000, "B", 3, v);
	cout << b4.getID() << endl;;
	Bilet v3[] = { b2,b3,b4 };
	int r = Bilet::CelMaiScumpBilet(v3, 3);
	cout << r << endl;;

	cin >> b1;
	cout << b2;
	cout << b1;
	cout << b3;
	 
	b1 = b2;
	cout << b1;
	 
	b1.setPret(10);
	cout << b1.getPret();
	
	char categorie_[10] = "vip";
	b1.setCategorie(categorie_);
	cout << b1.getCategorie()<<endl;
	 
	b1.setNrPlati(5);
	cout << b1.getNrPlati()<<endl;
	 
	b1.setIncarcari(v, 3);
	int* v1 = b1.getIncarcari();
	for (int i = 0; i <3; i++)
	cout << v1[i]<<" ";
	cout << endl;
	b1 = b1 + b2;
	cout << b1.getPret() << endl;;

	int p = (int)b2;
	cout << p;

	cout << b2.suma_cheltuita() << endl;;


	Locatie l1;
	cout << l1;
	Locatie l2 (10, "A", 3, v);
	cout << l2;
	Locatie l3(l2);
	cout << l3;
	cin >> l1;

	l1 = l2;
	cout << l1;

	l1.setNrZone(5);
	cout << l1.getNrZone() << endl;;
	 
	l1.setZona("B");
	cout << l1.getZona() << endl;;

	l1.setNrRanduri(7);
	cout << l1.getNrRanduri() << endl;;
	
	l1.setLocuri(v, 3);
	int* v2 = l1.getLocuri();
	for (int i = 0; i < 3; i++)
		cout << v2[i] << " ";
	cout << endl;
	int z = l2[2];
	cout << z;
	cout << endl;
	Locatie l4 = ++l2;
	cout << l4;
	
	cout << l2.nr_total_locuri()<<endl;

	cout << diferenta_locuri(l1, l2)<<endl;

	Eveniment e1;
	cin >> e1;
	cout << e1;
	Eveniment e2("Singur acasa", 10, 11, 2022, 20, 45);
	cout << e2;
	
	e1.setDenumire("Hamlet");
	cout << e1.getDenumire() << endl;;
	e1.setZi(12);
	cout << e1.getZi()<<endl;
	e1.setLuna(10);
	cout << e1.getLuna() << endl;;
	e1.setAn(2020);
	cout << e1.getAn() << endl;;
	e1.setOra(22);
	cout << e1.getOra() << endl;;
	e1.setMinute(30);
	cout << e1.getMinute()<<endl;
	
	Eveniment e3 = --e2;
	cout << e3;

	Eveniment e4;
	bool valid = !e2;
	bool valid_ = !e4;
	cout << valid<<" "<<valid_<<endl;
	e2.intarziere(4, 30);
	cout << e2;
	cout << endl;
	Eveniment e5("Film1", 10, 11, 2022,19, 30);
	Eveniment e6("Film2", 10, 11, 2022, 19, 31);
	cout << primul(e5, e6);
}