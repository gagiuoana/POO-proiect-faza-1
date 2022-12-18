#define _CRT_SECURE_NO_WARNINGS 

#include<iostream> 
#include<string> 
#include<fstream> 
using namespace std; 


class Bilet {
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

	
	~Bilet()
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
		for (int i = 0; i < this->randuri; i++) {
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

class Eveniment {
private:
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
		rezultat = this->durata + valoare;
		return rezultat;
	}


	
	int micsorareDurata(int valoare) {
		int rezultat = 0;
		rezultat = this->durata - valoare;
		return rezultat;
	}

};


