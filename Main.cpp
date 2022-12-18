#include "Classes.h"

int Bilet::contor = 1;
int Locatie::contor = 1;
int Eveniment::contor = 1;

int main()
{
	cout << "Clasa Bilet" << endl << endl;
	Bilet b;
	Bilet b1("Oana Gagiu", "VIP", 200, 1);
	Bilet b2("Popescu Adrian", "Peluza", 50, 0);
	Bilet b3("Andrei Maria", "Normal", 100, 1);
	cout << endl;

	cout << "Getteri si setteri" << endl;
	cout << b.getId() << endl;
	cout << b.getParticipant() << endl;
	cout << b.getTipBilet() << endl;
	cout << b.getPret() << endl;
	cout << b.getCodQR() << endl;
	cout << endl << endl;
	cout << b1.getId() << endl;
	cout << b1.getParticipant() << endl;
	cout << b1.getTipBilet() << endl;
	cout << b1.getPret() << endl;
	cout << b1.getCodQR() << endl;
	cout << endl << endl;
	cout << b2.getId() << endl;
	cout << b2.getParticipant() << endl;
	cout << b2.getTipBilet() << endl;
	cout << b2.getPret() << endl;
	cout << b2.getCodQR() << endl;
	cout << endl << endl;
	cout << b3.getId() << endl;
	cout << b3.getParticipant() << endl;
	cout << b3.getTipBilet() << endl;
	cout << b3.getPret() << endl;
	cout << b3.getCodQR() << endl;

	cout << endl << endl;
	cout << endl << endl;

	b2.setParticipant("Ionescu Alin");
	b2.setTipBilet("tribuna");
	b2.setPret(66);
	b2.setCodQR(1);
	cout << b2.getId() << endl;
	cout << b2.getParticipant() << endl;
	cout << b2.getTipBilet() << endl;
	cout << b2.getPret() << endl;
	cout << b2.getCodQR() << endl;
	cout << endl << endl;

	cout << "Operatorul<<" << endl;
	cout << b << endl << endl;
	cout << b1 << endl << endl;
	cout << b2 << endl << endl;
	cout << b3 << endl << endl;
	cout << endl << endl << endl;
	//cout << "Operatorul>>" << endl;
	//cout << b1 << endl;
	//cin >> b1;
	//cout << b1 << endl;
	cout << "Constructorul de copiere" << endl;
	cout << b3 << endl << endl;
	Bilet b4 = b3;
	cout << b4 << endl << endl;

	cout << "Operatorul=" << endl;
	cout << b1 << endl << endl;
	b2 = b1;
	cout << b2 << endl << endl;


	cout << "Operatorul++ - preincrementare" << endl << endl;
	cout << b1 << endl << endl;
	cout << b2 << endl << endl;
	b1 = ++b2;
	cout << b1 << endl << endl;
	cout << b2 << endl << endl;

	cout << "Operatorul ++ - postincrementare" << endl << endl;
	cout << b1 << endl << endl;
	cout << b3 << endl << endl;
	b1 = b3++;
	cout << b1 << endl << endl;
	cout << b3 << endl << endl;

	cout << "Operatorul <=" << endl << endl;
	cout << "Obiectul b1 are un pret mai mic fata de obiectul b2? (1-da 0-nu)" << (b1 <= b2) << endl;
	cout << endl << endl;

	cout << "Metode" << endl;
	cout << "Sunt biletele b1 si b2 de acelasi tip? " << endl;
	cout << b1.comparaTipBilete(b2) << endl << endl;
	cout << "Comparatea preturilor a doua bilete: " << endl;
	cout << b2.ComparaPret(b3) << endl << endl << endl;


	cout << "Clasa Locatie" << endl << endl;
	Locatie l;
	int vector1[] = { 20,30 };
	int vector2[] = { 550, 300, 240 };
	int vector3[] = { 200,144,50,7 };
	Locatie l1("Str Aviatorilor 1", "Hard Rock", 2, vector1);
	Locatie l2("Bulevardul Basarabia", "Arena nationala", 3, vector2);
	Locatie l3("Str Universitatii 314", "Teatrul National Bucuresti", 4, vector3);

	cout << "Getteri si setteri" << endl;
	cout << l.getId() << endl;
	cout << l.getAdresa() << endl;
	cout << l.getNume() << endl;
	cout << l.getRanduri() << endl;
	for (int i = 0; i < l.getRanduri(); i++)
	{
		cout << l.getLocuri()[i] << " ; ";
	}
	cout << endl;
	cout << endl << endl;
	cout << l1.getId() << endl;
	cout << l1.getAdresa() << endl;
	cout << l1.getNume() << endl;
	cout << l1.getRanduri() << endl;
	for (int i = 0; i < l1.getRanduri(); i++)
	{
		cout << l1.getLocuri()[i] << " ; ";
	}
	cout << endl;
	cout << endl << endl;
	cout << l2.getId() << endl;
	cout << l2.getAdresa() << endl;
	cout << l2.getNume() << endl;
	cout << l2.getRanduri() << endl;
	for (int i = 0; i < l2.getRanduri(); i++)
	{
		cout << l2.getLocuri()[i] << " ; ";
	}
	cout << endl;
	cout << endl << endl;
	cout << l3.getId() << endl;
	cout << l3.getAdresa() << endl;
	cout << l3.getNume() << endl;
	cout << l3.getRanduri() << endl;
	for (int i = 0; i < l3.getRanduri(); i++)
	{
		cout << l3.getLocuri()[i] << " ; ";
	}
	cout << endl;
	cout << endl << endl;

	l1.setAdresa("strada Herastrau 1");
	l1.setNume("Beraria H");
	l1.setLocuri(4, vector3);
	cout << l1.getId() << endl;
	cout << l1.getAdresa() << endl;
	cout << l1.getNume() << endl;
	cout << l1.getRanduri() << endl;
	for (int i = 0; i < l1.getRanduri(); i++)
	{
		cout << l1.getLocuri()[i] << " ; ";
	}
	cout << endl;
	cout << endl << endl;

	cout << "Operatorul<<" << endl;
	cout << l << endl << endl;
	cout << l1 << endl << endl;
	cout << l2 << endl << endl;
	cout << l3 << endl << endl;
	cout << endl << endl << endl;

	//cout << "Operatorul>>" << endl;
	//cout << l3 << endl;
	//cin >> l3;
	//cout << l3 << endl;

	cout << "Constructorul de copiere" << endl;
	cout << l3 << endl << endl;
	Locatie l4 = l3;
	cout << l4 << endl << endl;

	cout << "Operatorul=" << endl;
	cout << l2 << endl << endl;
	l3 = l2;
	cout << l3 << endl << endl;

	cout << "Operatorul index []" << endl;
	cout << "Numarul de locuri de pe pozitia 1 este: " << l2[1] << endl << endl;
	cout << "Numarul de locuri de pe pozitia -5 este: " << l2[-5] << endl << endl;
	cout << endl;

	cout << "Operatorul +=" << endl;
	l1 += 90;
	cout << l1 << endl << endl;

	cout << endl << endl << "Operatorul -=" << endl;
	l3 -= 0;
	cout << l3 << endl << endl;

	cout << "Metode" << endl;
	cout << "Capaciatatea locatiei este: " << endl;
	cout << l2.totalLocuri() << endl << endl;

	cout << "Locul minim per rand al locatiei 1 este: " << endl;
	cout << l1.locMinim() << endl;
	cout << "Locul maxim per rand al locatiei 3 este: " << endl;
	cout << l3.locMaxim() << endl;

	cout << "Metoda de eliminare din vector dupa valoare" << endl;
	cout << "Obiectul l1 inainte de eliminare:" << endl;
	cout << l1 << endl;
	l1.eliminaPretDupaValoare(20);
	cout << "Obiectul l1 dupa de eliminare:" << endl;
	cout << l1 << endl << endl;

	cout << "Clasa Eveniment" << endl << endl;
	Eveniment e;
	Eveniment e1("Irina Rimes", "Concert Irina Rimes si invitat special", 1, 3);
	Eveniment e2("Steaua Dinamo", "Meciul lunii", 0, 2);
	Eveniment e3("Lebada neagra", "Un spectacol perfect pentru sarbatori", 1, 5);
	cout << endl;

	cout << "Getteri si setteri" << endl;
	cout << e.getId() << endl;
	cout << e.getNume() << endl;
	cout << e.getDescriere() << endl;
	cout << e.getInvitatSpecial() << endl;
	cout << e.getDurata() << endl;
	cout << endl << endl;
	cout << e1.getId() << endl;
	cout << e1.getNume() << endl;
	cout << e1.getDescriere() << endl;
	cout << e1.getInvitatSpecial() << endl;
	cout << e1.getDurata() << endl;
	cout << endl << endl;
	cout << e2.getId() << endl;
	cout << e2.getNume() << endl;
	cout << e2.getDescriere() << endl;
	cout << e2.getInvitatSpecial() << endl;
	cout << e2.getDurata() << endl;
	cout << endl << endl;
	cout << e3.getId() << endl;
	cout << e3.getNume() << endl;
	cout << e3.getDescriere() << endl;
	cout << e3.getInvitatSpecial() << endl;
	cout << e3.getDurata() << endl;
	cout << endl << endl;


	cout << endl << endl;
	cout << endl << endl;

	e3.setNume("Spargatorul de nuci");
	e3.setInvitatSpecial(0);
	e3.setDescriere("Spectacol de balet perfect pentru sarbatori");
	e3.setDurata(6);
	cout << e3.getId() << endl;
	cout << e3.getNume() << endl;
	cout << e3.getDescriere() << endl;
	cout << e3.getInvitatSpecial() << endl;
	cout << e3.getDurata() << endl;
	cout << endl << endl;

	cout << "Operatorul<<" << endl;
	cout << e << endl << endl;
	cout << e1 << endl << endl;
	cout << e2 << endl << endl;
	cout << e3 << endl << endl;
	cout << endl << endl << endl;
	//cout << "Operatorul>>" << endl;
	//cout << e1 << endl;
	//cin >> e1;
	//cout << e1 << endl;
	cout << "Constructorul de copiere" << endl;
	cout << e2 << endl << endl;
	Eveniment e4 = e2;
	cout << e4 << endl << endl;

	cout << "Operatorul=" << endl;
	cout << e3 << endl << endl;
	e4 = e3;
	cout << e4 << endl << endl;

	cout << "Operatorul de negatie !" << endl;
	cout << e1 << endl << endl;
	!e1;
	cout << e1 << endl << endl;

	cout << "Operatorul de cast la string" << endl;
	cout << "Propozitia este: " << (string)e1 << endl << endl;

	cout << "Metode" << endl;
	cout << "Marim durata obiectului e2" << endl;
	cout << e2.marireDurata(1) << endl;

	cout << "Micsoram durata obiectului e3" << endl;
	cout << e3.micsorareDurata(1) << endl;


	return 0;
}
