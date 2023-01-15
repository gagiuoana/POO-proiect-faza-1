#define _CRT_SECURE_NO_WARNINGS 

#include<iostream> 
#include<string> 
#include<fstream> 
#include<vector>
#include<map>
using namespace std; 


class Interface
{
	virtual void FunctieVirtualPura() = 0;
};

class Bilet
{
private:
	const int id;
	string participant;
	char* tipBilet;
	float pret;
	bool codQR;
public:
	static int contor;


	Bilet() :id(contor++) {
		this->participant = "Anonim";
		this->tipBilet = new char[strlen("necunoscut") + 1];
		strcpy(this->tipBilet, "necunoscut");
		this->pret = 0;
		this->codQR = 0;
	}
	
	Bilet(string participant, const char* tipBilet, float pret, bool codQR) :id(contor++) {
		this->participant = participant;
		this->tipBilet = new char[strlen(tipBilet) + 1];
		strcpy(this->tipBilet, tipBilet);
		this->pret = pret;
		this->codQR = codQR;
	}

	
	~Bilet ()
	{
		if (this->tipBilet != NULL)
		{
			delete[]this->tipBilet;
		}
	}

	
	const int getId()
	{
		return this->id;
	}
	string getParticipant()
	{
		return this->participant;
	}
	const char* getTipBilet()
	{
		return this->tipBilet;
	}

	float getPret()
	{
		return this->pret;
	}

	bool getCodQR()
	{
		return this->codQR;
	}

	void setParticipant(string participantNou)
	{
		this->participant = participantNou;
	}
	void setTipBilet(const char* BiletNou)
	{
		if (this->tipBilet != NULL)
		{
			delete[]this->tipBilet;
		}
		this->tipBilet = new char[strlen(BiletNou) + 1];
		strcpy(this->tipBilet, BiletNou);

	}

	void setPret(float pretNou)
	{
		this->pret = pretNou;
	}

	void setCodQR(bool codQRNou)
	{
		this->codQR = codQRNou;
	}

	friend ostream& operator<<(ostream& out, Bilet& b)
	{
		out << "Id: " << b.id << endl;
		out << "Nume participant: " << b.participant << endl;
		out << "Tipul biletului: " << b.tipBilet << endl;
		out << "Cod QR " << b.codQR << endl;
		out << "Pret bilet: " << b.pret << endl;
		return out;
	}
	
	Bilet(const Bilet& b) :id(b.id)
	{
		this->participant = b.participant;
		this->tipBilet = new char[strlen(b.tipBilet) + 1];
		strcpy(this->tipBilet, b.tipBilet);
		this->codQR = b.codQR;
		this->pret = b.pret;
	}

	
	Bilet& operator=(const Bilet& b)
	{
		if (this->tipBilet != NULL)
		{
			delete[]this->tipBilet;
		}

		this->participant = b.participant;
		this->tipBilet = new char[strlen(b.tipBilet) + 1];
		strcpy(this->tipBilet, b.tipBilet);
		this->codQR = b.codQR;
		this->pret = b.pret;
		return *this;
	}

	
	friend istream& operator>>(istream& in, Bilet& b)
	{
		if (b.tipBilet != NULL)
		{
			delete[]b.tipBilet;
		}

		cout << "Numele participantului la eveniment este: " << endl;
		in >> b.participant;
		cout << "Tipul biletului achizitionat este: " << endl;
		char aux[50];
		in >> aux;
		b.tipBilet = new char[strlen(b.tipBilet) + 1];
		strcpy(b.tipBilet, aux);
		cout << "Pretul biletului este: " << endl;
		in >> b.pret;
		cout << "Biletul poate fi validat prin cod QR: " << endl;
		in >> b.codQR;
		return in;

	}

	
	Bilet& operator++()
	{
		this->pret++;
		return*this;
	}

	
	Bilet operator++(int)
	{
		Bilet copie = *this;
		this->pret++;
		return copie;
	}

	
	bool operator<=(Bilet& b)
	{
		if (this->pret <= b.pret)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	

	bool comparaTipBilete(Bilet& b)
	{
		if (strcmp(this->tipBilet, b.tipBilet) == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	bool ComparaPret(Bilet& b)
	{
		if (this->pret < b.pret)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	
	friend ofstream& operator<<(ofstream& file, Bilet& b)
	{
		file << b.id << endl;
		file << b.participant << endl;
		file << b.tipBilet << endl;
		file << b.pret << endl;
		file << b.codQR << endl;
		return file;
	}

	friend ifstream& operator>>(ifstream& file, Bilet& b)
	{
		delete[]b.tipBilet;
		file >> b.tipBilet;
		char aux[50];
		file >> aux;
		b.tipBilet = new char[strlen(aux) + 1];
		strcpy(b.tipBilet, aux);
		file >> b.participant;
		file >> b.pret;
		file >> b.codQR;
		return file;
	}
	
	
	void scriereBinar(fstream& file)
	{
		int nrLitereParticipant = this->participant.size();
	file.write((char*)&nrLitereParticipant, sizeof(int));
	file.write(this->participant.c_str(), nrLitereParticipant);
		int numarLitereTipBilet = strlen(this->tipBilet);
		file.write((char*)&numarLitereTipBilet, sizeof(int));
		for (int i = 0; i < numarLitereTipBilet; i++)
		{
			file.write((char*)&this->tipBilet[i], sizeof(char));
		}
		file.write((char*)&this->pret, sizeof(float));
		file.write((char*)&this->codQR, sizeof(bool));

	}
	

	void citireBinar(fstream& file)
	{
		int nrLitereParticipant;
		file.read((char*)&nrLitereParticipant, sizeof(int));
		string aux;
		aux.resize(nrLitereParticipant);
		file.read((char*)aux.c_str(), nrLitereParticipant);
		this->participant = aux;
		int numarLitereTipBilet;
		file.read((char*)&numarLitereTipBilet, sizeof(int));
		this->tipBilet = new char[numarLitereTipBilet + 1]; // terminator \0
		for (int i = 0; i < numarLitereTipBilet; i++)
		{
			file.read((char*)&this->tipBilet[i], sizeof(char));
		}
		this->tipBilet[numarLitereTipBilet] = '\0';
	 	file.read((char*)&this->pret, sizeof(float));
		file.read((char*)&this->codQR, sizeof(bool));
	}

};


class Locatie {
private:
	const int id;
	string adresa;
	char* nume;
	int randuri;
	int* locuri;
public:
	static int contor;


	
	Locatie() :id(contor++) {
		this->adresa = "necunoscuta";
		this->nume = new char[strlen("necunoscut") + 1];
		strcpy(this->nume, "necunoscut");
		this->randuri = 0;
		this->locuri = 0;
	}
	
	Locatie(string adresa, const char* nume, int randuri, int* locuri) :id(contor++) {
		this->adresa = adresa;
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->randuri = randuri;
		this->locuri = new int[this->randuri];
		for (int i = 0; i < this->randuri; i++) {
			this->locuri[i] = locuri[i];
		}
	}

	
	~Locatie()
	{
		if (this->nume != NULL)
		{
			delete[]this->nume;
		}
		if (this->locuri != NULL)
		{
			delete[]this->locuri;
		}
	}

	
	const int getId()
	{
		return this->id;
	}
	string getAdresa()
	{
		return this->adresa;
	}
	const char* getNume()
	{
		return this->nume;
	}

	int getRanduri()
	{
		return this->randuri;
	}

	int* getLocuri()
	{
		return this->locuri;
	}

	void setAdresa(string adresaNoua)
	{
		this->adresa = adresaNoua;
	}
	void setNume(const char* numeNou)
	{
		if (this->nume != NULL)
		{
			delete[]this->nume;
		}
		this->nume = new char[strlen(numeNou) + 1];
		strcpy(this->nume, numeNou);

	}

	void setLocuri(int randuriNoi, int* locuriNoi) 
	{
		if (this->locuri != NULL)
		{
			delete[]this->locuri;
		}
		this->randuri = randuriNoi;
		this->locuri = new int[this->randuri];
		for (int i= 0; i < this->randuri; i++) {
			this->locuri[i] = locuriNoi[i];
		}
	}

	
	friend ostream& operator<<(ostream& out, Locatie& l)
	{
		out << "Id: " << l.id << endl;
		out << "Adresa: " << l.adresa << endl;
		out << "Nume locatie: " << l.nume << endl;
		out << "Numar de randuri " << l.randuri << endl;
		out << "Numar de locuri pe rand: " << endl;
		for (int i = 0; i < l.randuri; i++) {
			out << l.locuri[i] << endl;
		}
		return out;
	}
	
	Locatie(const Locatie& l) :id(l.id)
	{
		this->adresa = l.adresa;
		this->nume = new char[strlen(l.nume) + 1];
		strcpy(this->nume, l.nume);
		this->randuri = l.randuri;
		this->locuri = new int[this->randuri];
		for (int i = 0; i < l.randuri; i++) {
			this->locuri[i] = l.locuri[i];
		}
	}

	
	Locatie& operator=(const Locatie& l)
	{
		if (this->nume != NULL)
		{
			delete[]this->nume;
		}
		if (this->locuri != NULL)
		{
			delete[]this->locuri;
		}
		this->adresa = l.adresa;
		this->nume = new char[strlen(l.nume) + 1];
		strcpy(this->nume, l.nume);
		this->randuri = l.randuri;
		this->locuri = new int[this->randuri];
		for (int i = 0; i < l.randuri; i++) {
			this->locuri[i] = l.locuri[i];
		}
		return *this;
	}

	
	friend istream& operator>>(istream& in, Locatie& l)
	{
		if (l.nume != NULL)
		{
			delete[]l.nume;
		}
		if (l.locuri != NULL)
		{
			delete[]l.locuri;
		}
		cout << "Adresa locatiei este: " << endl;
		in >> l.adresa;
		cout << "Numele locatiei: " << endl;
		char aux[50];
		in >> aux;
		l.nume = new char[strlen(l.nume) + 1];
		strcpy(l.nume, aux);
		cout << "Numarul de randuri al locatiei este: " << endl;
		in >> l.randuri;
		l.locuri = new int[l.randuri];
		for (int i = 0; i < l.randuri; i++) {
			cout << "Numarul de locuri al locatiei este: " << endl;
			in >> l.locuri[i];
		}
		return in;

	}

	
	float operator[](int pozitieDorita)
	{
		if (pozitieDorita >= 0 && pozitieDorita < this->randuri)
		{
			return this->locuri[pozitieDorita];
		}
		else
		{
			return -1;
		}
	}

	Locatie& operator+=(float locNou)
	{
		
		Locatie copie = *this; 

		
		if (this->locuri != NULL)
		{
			delete[] this->locuri;
		}

		
		this->randuri = this->randuri + 1;
		this->locuri = new int[this->randuri];

		
		for (int i = 0; i < this->randuri - 1; i++)
		{
			this->locuri[i] = copie.locuri[i];
		}

		
		this->locuri[this->randuri - 1] = locNou;

		return *this;
	}


	Locatie& operator -= (int pozitieDorita)
	{
		
		Locatie copie = *this; 

		
		if (this->locuri != NULL)
		{
			delete[] this->locuri;
		}

		
		this->randuri = this->randuri - 1;
		this->locuri = new int[this->randuri];

		
		
		for (int i = 0; i < pozitieDorita; i++)
		{
			this->locuri[i] = copie.locuri[i];
		}
		for (int i = pozitieDorita + 1; i < this->randuri + 1; i++)
		{
			this->locuri[i - 1] = copie.locuri[i];
		}

		return *this;
	}

	
	int totalLocuri()
	{
		int rezultat = 0;
		for (int i = 0; i < this->randuri; i++)
		{
			rezultat = rezultat + this->locuri[i];
		}

		return rezultat;
	}

	

	int locMaxim()
	{
		int max = this->locuri[0];
		for (int i = 1; i < this->randuri; i++)
		{
			if (max < this->locuri[i])
			{
				max = this->locuri[i];
			}
		}
		return max;
	}

	int locMinim()
	{
		int min = this->locuri[0];
		for (int i = 1; i < this->randuri; i++)
		{
			if (min > this->locuri[i])
			{
				min = this->locuri[i];
			}
		}

		return min;
	}

	
	void eliminaPretDupaValoare(int valDorita)
	{
		
		Locatie copie = *this; 

		
		if (this->locuri != NULL)
		{
			delete[] this->locuri;
		}

		
		int nr = 0;
		for (int i = 0; i < this->randuri; i++)
		{
			if (valDorita == copie.locuri[i])
			{
				nr = nr + 1;
			}
		}
		this->randuri = this->randuri - nr;
		this->locuri = new int[this->randuri];
		int poz = 0;
		for (int i = 0; i < copie.randuri; i++)
		{
			if (valDorita != copie.locuri[i])
			{
				this->locuri[poz] = copie.locuri[i];
				poz = poz + 1;
			}
		}
	}
};

class Eveniment : public Interface {
protected:
	const int id;
	char* nume;
	string descriere;
	bool invitatSpecial;
	int durata;
public:
	static int contor;
	
	
	Eveniment() :id(contor++) {
		this->nume = new char[strlen("necunoscut") + 1];
		strcpy(this->nume, "necunoscut");
		this->descriere = "nu exista descriere";
		this->invitatSpecial = 0;
		this->durata = 0;
	}
	
	Eveniment(const char* nume, string descriere, bool invitatSpecial, int durata) :id(contor++) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->descriere = descriere;
		this->invitatSpecial = invitatSpecial;
		this->durata = durata;
	}

	
	~Eveniment()
	{
		if (this->nume != NULL)
		{
			delete[]this->nume;
		}
	}

	
	const int getId()
	{
		return this->id;
	}
	
	const char* getNume()
	{
		return this->nume;
	}

	string getDescriere()
	{
		return this->descriere;
	}

	bool getInvitatSpecial()
	{
		return this->invitatSpecial;
	}

	int getDurata()
	{
		return this->durata;
	}

	void setNume(const char* numeNou)
	{
		if (this->nume != NULL)
		{
			delete[]this->nume;
		}
		this->nume = new char[strlen(numeNou) + 1];
		strcpy(this->nume, numeNou);

	}

	void setDescriere(string descriereNoua)
	{
		this->descriere = descriereNoua;
	}

	void setInvitatSpecial(bool invitatSpecialNou)
	{
		this->invitatSpecial = invitatSpecialNou;
	}

	void setDurata(int durataNoua)
	{
		this->durata = durataNoua;
	}

	
	friend ostream& operator<<(ostream& out, Eveniment& e)
	{
		out << "Id: " << e.id << endl;
		out << "Nume eveniment: " << e.nume << endl;
		out << "Descrierea evenimentului: " << e.descriere << endl;
		out << "Invitat special la eveniment: " << e.invitatSpecial << endl;
		out << "Durata evenimentului este: " << e.durata << endl;
		return out;
	}
	
	Eveniment(const Eveniment& e) :id(e.id)
	{
		this->nume = new char[strlen(e.nume) + 1];
		strcpy(this->nume, e.nume);
		this->descriere = e.descriere;
		this->invitatSpecial = e.invitatSpecial;
		this->durata = e.durata;
	}

	
	Eveniment& operator=(const Eveniment& e)
	{
		if (this->nume != NULL)
		{
			delete[]this->nume;
		}
		this->nume = new char[strlen(e.nume) + 1];
		strcpy(this->nume, e.nume);
		this->descriere = e.descriere;
		this->invitatSpecial = e.invitatSpecial;
		this->durata = e.durata;
		return *this;
	}

	
	friend istream& operator>>(istream& in, Eveniment& e)
	{
		if (e.nume != NULL)
		{
			delete[]e.nume;
		}
		cout << "Numele evenimentului: " << endl;
		char aux[50];
		in >> aux;
		e.nume = new char[strlen(e.nume) + 1];
		strcpy(e.nume, aux);
		cout << "Descrierea evenimentului: " << endl;
		in >> e.descriere;
		cout << "Participa la eveniment un invitat special: " << endl;
		in >> e.invitatSpecial;
		cout << "Durata evenimentului este: " << endl;
		in >> e.durata;
		return in;

	}

	
	friend void operator!(Eveniment& e)
	{
		if (e.invitatSpecial == 1)
		{
			e.invitatSpecial = 0;
		}
		else
		{
			e.invitatSpecial = 1;
		}
	}

	operator string()
	{
		string propozitie = "Descrierea evenimentului la care o persoana doreste sa participe este: " + this->descriere;
		return propozitie;
	}


	
	int marireDurata(int valoare) {
		int rezultat = 0;
		rezultat= this->durata + valoare;
		return rezultat;
	}


	
	int micsorareDurata(int valoare) {
		int rezultat = 0;
		rezultat = this->durata - valoare;
		return rezultat;
	}

	
	void FunctieVirtualPura()
	{
		cout << "Clasa Eveniment nu mai este abstracta" << endl;
	}

	
	virtual int AdaugaDurata(int adaos)
	{
		int rezultat;
		rezultat = this->durata + adaos;
		return rezultat;
	}
	virtual string returneazaClasa()
	{
		return "Suntem in clasa de baza Eveniment";
	}

	
	friend ofstream& operator<<(ofstream& file, Eveniment& e)
	{
		file << e.nume << endl;
		file << e.descriere << endl;
		file << e.invitatSpecial << endl;
		file << e.durata << endl;
		return file;
	}
	 
	friend ifstream& operator>>(ifstream& file, Eveniment &e)
	{
		delete[]e.nume;
		file >> e.nume;
		char aux[50];
		file >> aux;
		e.nume = new char[strlen(aux) + 1];
		strcpy(e.nume, aux);
		file >> e.descriere;
		file >> e.invitatSpecial;
	  file >> e.durata;
		return file;
	}

	void ScriereBinar(fstream& file)
	{
		int nrLitereDescriere = this->descriere.size();
		file.write((char*)&nrLitereDescriere, sizeof(int));
		file.write(this->descriere.c_str(), nrLitereDescriere);
		int nrLitereNume = strlen(this->nume);
		file.write((char*)&nrLitereNume, sizeof(int));
		for (int i = 0; i < nrLitereNume; i++)
		{
			file.write((char*)&this->nume[i], sizeof(char));
		}
	 file.write((char*)&this->durata, sizeof(int));
	 file.write((char*)&this->invitatSpecial, sizeof(bool));
	}

	void CitireBinar(fstream& file)
	{
		delete[]this->nume;
		int nrLitereDescriere;
		file.read((char*)&nrLitereDescriere, sizeof(int));
		string aux;
		aux.resize(nrLitereDescriere);
		file.read((char*)aux.c_str(), nrLitereDescriere);
		this->descriere = aux;
		int nrLitereNume;
		file.read((char*)&nrLitereNume, sizeof(int));
		this->nume = new char[nrLitereNume + 1]; // terminator \0
		for (int i = 0; i < nrLitereNume; i++)
		{
			file.read((char*)&this->nume[i], sizeof(char));
		}
		this->nume[nrLitereNume] = '\0';
	  file.read((char*)&this->durata, sizeof(int));
	  file.read((char*)&this->invitatSpecial, sizeof(bool));
	}


};

class EvenimentPrivat : public Eveniment {
	int capacitateMaxima;
	float taxaSuplimentara;
	bool servireMasa;

public:
	
	EvenimentPrivat() :Eveniment() {
		this->capacitateMaxima = 0;
		this->taxaSuplimentara = 0;
		this->servireMasa = 0;
	}

	
	EvenimentPrivat(int capacitateMaxima, float taxaSuplimentara, bool servireMasa, const char* nume, string descriere, bool invitatSpecial, int durata) : Eveniment(nume, descriere, invitatSpecial, durata) {
		this->capacitateMaxima = capacitateMaxima;
		this->taxaSuplimentara = taxaSuplimentara;
		this->servireMasa = servireMasa;
	}

	
	~EvenimentPrivat()
	{

	}

	
	int getCapacitateMaxima() {
		return this->capacitateMaxima;
	}

	float getTaxaSuplimentara() {
		return this->taxaSuplimentara;
	}

	bool getServireMasa() {
		return this->servireMasa;
	}

	void setCapacitateMaxima(int CapacitateMaximaNoua) {
		this->capacitateMaxima = CapacitateMaximaNoua;
	}

	void setTaxaSuplimentara(float taxaSuplimentaraNoua) {
		this->taxaSuplimentara = taxaSuplimentaraNoua;
	}

	void setServireMasa(bool servireMasaNoua) {
		this->servireMasa = servireMasaNoua;
	}

	
	EvenimentPrivat(const EvenimentPrivat& p) :Eveniment(p)
	{
		this->capacitateMaxima = p.capacitateMaxima;
		this->taxaSuplimentara = p.taxaSuplimentara;
		this->servireMasa = p.servireMasa;
	}

	
	EvenimentPrivat& operator=(const EvenimentPrivat& p)
	{
		Eveniment::operator=(p);
		this->capacitateMaxima = p.capacitateMaxima;
		this->taxaSuplimentara = p.taxaSuplimentara;
		this->servireMasa = p.servireMasa;
		return *this;
	}

	
	friend ostream& operator<<(ostream& out, EvenimentPrivat& p)
	{
		out << (Eveniment&)p;
		out << "Capacitatea maxima a evenimentului: " << p.capacitateMaxima << endl;
		out << "Taxa suplimentara a evenimentului privat: " << p.taxaSuplimentara << endl;
		out << "Se serveste masa la eveniment: " << p.servireMasa;
		return out;
	}

	
	friend istream& operator>>(istream& in, EvenimentPrivat& p)
	{
		in >> (Eveniment&)p;
		cout << "Capacitatea maxima: " << endl;
		in >> p.capacitateMaxima;
		cout << "Taxa suplimentara: " << endl;
		in >> p.taxaSuplimentara;
		cout << "Servire masa: " << endl;
		in >> p.servireMasa;
		return in;
	}

	
	friend ofstream& operator<<(ofstream& file, EvenimentPrivat& p)
	{
		file << (Eveniment&)p;
		file << p.capacitateMaxima << endl;
		file << p.taxaSuplimentara << endl;
		file << p.servireMasa << endl;
		return file;
	}
	friend ifstream& operator>>(ifstream& file, EvenimentPrivat& p)
	{
		file >> (Eveniment&)p;
		file >> p.capacitateMaxima;
		file >> p.taxaSuplimentara;
		file >> p.servireMasa;
		return file;
	}

	
	int AdaugaDurata(int adaos)
	{
		int rezultat;
		rezultat = this->durata + adaos + 50;
		return rezultat;
	}
	string returneazaClasa()
	{
		return "Suntem in clasa derivata EvenimentPrivat";
	}

};

int Bilet::contor = 1;
int Locatie::contor = 1;
int Eveniment::contor = 1;

void Meniu()
{
	cout << "MENIU";
	cout << " 1.Acceseaza Bilet \n";
	cout << " 2.Selecteaza Bilet si introduce in cos \n";
	cout << " 3.Sterge Bilet din cos \n";
	cout << " 4.Completeaza informatii Participant \n";
	cout << " 5.Comanda Bilet \n";
}
void AcceseazaBilet()
{
	cout << "Ai selectat AcceseazaBilet : \n";
}

void StergeBilet()
{
	cout << "Ai selectat StergeBilet :\n";
}
void Date()
{
	cout << "Completeaza datele participantului :\n";
}
void ComandaBilet ()
{
	cout << "Ai selectat ComandaBilet :\n";
}


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

	cout<< "Operatorul ++ - postincrementare" << endl << endl;
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
	cout << b1.comparaTipBilete(b2) << endl<<endl;
	cout << "Comparatea preturilor a doua bilete: " << endl;
	cout << b2.ComparaPret(b3) << endl << endl << endl;


	cout << "Clasa Locatie" << endl << endl;
	Locatie l;
	int vector1[] = { 20,30 };
	int vector2[] = { 550, 300, 240 };
	int vector3[] = { 200,144,50,7 };
	Locatie l1("Str Aviatorilor 1","Hard Rock", 2, vector1);
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
	l1.setLocuri(4,vector3);
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
	cout << "Numarul de locuri de pe pozitia 1 este: " << l2[1] << endl<<endl;
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
	cout << l2.totalLocuri() << endl<<endl;

	cout << "Locul minim per rand al locatiei 1 este: " << endl;
	cout << l1.locMinim() << endl;
	cout << "Locul maxim per rand al locatiei 3 este: " << endl;
	cout << l3.locMaxim() << endl;

	cout << "Metoda de eliminare din vector dupa valoare" << endl;
	cout << "Obiectul l1 inainte de eliminare:" << endl;
	cout << l1 << endl;
	l1.eliminaPretDupaValoare(20);
	cout << "Obiectul l1 dupa de eliminare:" << endl;
	cout << l1 << endl<<endl;

	cout << "Clasa Eveniment" << endl << endl;
	Eveniment e;
	Eveniment e1("Irina Rimes","Concert Irina Rimes si invitat special", 1,3);
	Eveniment e2("Steaua Dinamo","Meciul lunii", 0,2);
	Eveniment e3("Lebada neagra","Un spectacol perfect pentru sarbatori", 1,5);
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
	cout << "Propozitia este: " << (string)e1<<endl<<endl;

	cout << "Metode" << endl;
	cout << "Marim durata obiectului e2" << endl;
	cout << e2.marireDurata(1) << endl;

	cout << "Micsoram durata obiectului e3" << endl;
	cout << e3.micsorareDurata(1) << endl;


	cout << "Functie virtual pura" << endl << endl;
	e1.FunctieVirtualPura();

	cout << "Clasa EvenimentPrivat" << endl << endl;
	EvenimentPrivat p;
	EvenimentPrivat p1(50, 200, 1, "Irina Rimes", "Concert Irina Rimes si invitat special", 1, 3);
	EvenimentPrivat p2(100, 50, 0, "Steaua Dinamo", "Meciul lunii", 0, 2);
	EvenimentPrivat p3(20, 300, 1, "Lebada neagra", "Un spectacol perfect pentru sarbatori", 1, 5);

	cout << "Getteri" << endl;
	cout << "Capacitate maxima: " << p1.getCapacitateMaxima() << endl;
	cout << "Taxa suplimentara: " << p1.getTaxaSuplimentara() << endl;
	cout << "Servire masa: " << p1.getServireMasa() << endl;
	cout << p1.getId() << endl;
	cout << p1.getNume() << endl;
	cout << p1.getDescriere() << endl;
	cout << p1.getInvitatSpecial() << endl;
	cout << p1.getDurata() << endl;
	cout << endl << endl;
	cout << "Capacitate maxima: " << p2.getCapacitateMaxima() << endl;
	cout << "Taxa suplimentara: " << p2.getTaxaSuplimentara() << endl;
	cout << "Servire masa: " << p2.getServireMasa() << endl;
	cout << p2.getId() << endl;
	cout << p2.getNume() << endl;
	cout << p2.getDescriere() << endl;
	cout << p2.getInvitatSpecial() << endl;
	cout << p2.getDurata() << endl;
	cout << endl << endl;
	cout << "Capacitate maxima: " << p3.getCapacitateMaxima() << endl;
	cout << "Taxa suplimentara: " << p3.getTaxaSuplimentara() << endl;
	cout << "Servire masa: " << p3.getServireMasa() << endl;
	cout << p3.getId() << endl;
	cout << p3.getNume() << endl;
	cout << p3.getDescriere() << endl;
	cout << p3.getInvitatSpecial() << endl;
	cout << p3.getDurata() << endl;
	cout << endl << endl;

	cout << "Setteri" << endl << endl;
	p2.setCapacitateMaxima(110);
	p2.setTaxaSuplimentara(10);
	p2.setServireMasa(0);
	p2.setNume("Meci Fotbal");
	p2.setDescriere("Meci de fotbal intre Steaua si Dinamo");
	p2.setInvitatSpecial(0);
	p2.setDurata(1);
	cout << "Capacitate maxima: " << p2.getCapacitateMaxima() << endl;
	cout << "Taxa suplimentara: " << p2.getTaxaSuplimentara() << endl;
	cout << "Servire masa: " << p2.getServireMasa() << endl;
	cout << p2.getId() << endl;
	cout << p2.getNume() << endl;
	cout << p2.getDescriere() << endl;
	cout << p2.getInvitatSpecial() << endl;
	cout << p2.getDurata() << endl;
	cout << endl << endl;

	cout << "Operatorul <<" << endl;
	cout << p << endl;
	cout << p1 << endl;
	cout << p2 << endl;
	cout << p3 << endl;

	cout << "Operatorul >>" << endl;
	//cout << p1 << endl << endl;
	//cin >> p1;
	//cout << p1 << endl;

	cout << "Constructorul de copiere" << endl;
	cout << p3 << endl << endl;
	EvenimentPrivat p4 = p3;
	cout << p4 << endl << endl;

	cout << "Operatorul =" << endl;
	cout << p2 << endl << endl;
	p1 = p2;
	cout << p1 << endl << endl;


	cout << "Operatorul de negatie !" << endl;
	cout << p1 << endl << endl;
	!p1;
	cout << p1 << endl << endl;

	cout << "Metode" << endl;
	cout << "Marim durata obiectului p2" << endl;
	cout << p2.marireDurata(1) << endl;

	cout << "Micsoram durata obiectului p1" << endl;
	cout << p1.micsorareDurata(1) << endl << endl;

	cout << "Metode virtuale" << endl << endl;
	cout << e1.returneazaClasa() << endl << endl;
	cout << p1.returneazaClasa() << endl << endl;
	cout << e1.AdaugaDurata(2) << endl << endl;
	cout << p1.AdaugaDurata(3) << endl << endl;

	cout << "Apelare fisiere" << endl;
	
	ofstream file1("Bilet.txt", ios::out);
	
	file1 << b1;
	
	file1.close();

	
	ifstream file2("Bilet.txt", ios::in);
	
	file2 >> b;
	
	file2.close();

	cout << b1 << endl << endl;
	cout << b << endl << endl;

	
	fstream file3("Bilet.bin", ios::binary | ios::out);
	
	b1.scriereBinar(file3);
	
	file3.close();

	
	fstream file4("Bilet.bin", ios::binary | ios::in);
	
	b.citireBinar(file4);
	
	file4.close();

	cout << b1 << endl << endl;
	cout << b << endl << endl;

	
	ofstream file7("Eveniment.txt", ios::out);

	file7 << e1;
	
	file7.close();

	
	ifstream file8("Eveniment.txt", ios::in);
	
	file8 >> e;
	
	file8.close();

	
	fstream file9("Eveniment.bin", ios::binary | ios::out);
	
	e1.ScriereBinar(file9);
	
	file9.close();

	
	fstream file10("Eveniment.bin", ios::binary | ios::in);
	
	//e.CitireBinar(file10);
	
	//file10.close();

	//cout << e1 << endl << endl;
	//cout << e<< endl << endl;

	
	
	ofstream file5("EvenimentPrivat.txt", ios::out);
	
	file5 << p1;
	
	file5.close();

	
	ifstream file6("EvenimentPrivat.txt", ios::in);
	
	file6 >> p;
	
	file6.close();

	cout << p1 << endl << endl;
	cout << p << endl << endl;

	cout << "STL DE TIP CONTAINER" << endl << endl;
	cout << "Vector" << endl;
	
	cout << "VECTOR" << endl;
	vector<Bilet> vectorBilet;
	vectorBilet.push_back(b1);
	vectorBilet.push_back(b2);
	vectorBilet.push_back(b3);
	vector<Bilet>::iterator vectIt;
	for (vectIt = vectorBilet.begin(); vectIt != vectorBilet.end(); vectIt++) {
		cout << *vectIt << endl;
	}
	cout << "Numar elemente din vectorul STL vectorBilet este:" << vectorBilet.size() << endl;
	
	
	vectorBilet.pop_back();
	cout << endl << endl;
	for (int i = 0; i < vectorBilet.size(); i++)
	{
		cout << vectorBilet[i] << " ; ";
	}

	cout << "Numar elemente din vectorul STL vectorBilet este:" << vectorBilet.size() << endl;
	cout << endl << endl << endl;



	Meniu();
	int yourchoice;
	string confirm;
	do
	{
		cout << "Enter your choice(1-5):";
		cin >> yourchoice;
		switch (yourchoice)
		{
		case 1: AcceseazaBilet(); break;
		case 2: StergeBilet(); break;
		case 3: Date(); break;
		case 4: ComandaBilet(); break;
		default: cout << "invalid"; break;
		}
		cout << "Press w or W to continue:";
		cin >> confirm;
	} while (confirm == "w" || confirm == "W");


	return 0;
}
