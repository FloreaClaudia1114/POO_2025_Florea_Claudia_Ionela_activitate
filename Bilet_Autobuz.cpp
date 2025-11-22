#define _CRT_SECURE_NO_WARNINGS
#include <iostream>;
#include <string>;

using namespace std;

class Autobuz {

private:
	const int idAutobuz;
	static int nrAutobuze;
	int capacitate;
	char* producator;
	int nrPersoaneImbarcate;

	//constructorul default 
public:
	Autobuz() :idAutobuz(nrAutobuze++) {

		capacitate = 0;
		producator = new char[strlen("Dacia") + 1];
		strcpy(this->producator, "Dacia");
		nrPersoaneImbarcate = 0;
	}

	//constructorul cu parametrii 
	//validarea parametrilor se face pe parametru fara this;


	Autobuz(int capacitate, const char* producator, int nrPersoaneImbarcate) :idAutobuz(nrAutobuze++) {

		this->capacitate = capacitate;
		this->producator = new char[strlen(producator) + 1];
		strcpy(this->producator, producator);
		if (nrPersoaneImbarcate < capacitate) {
			this->nrPersoaneImbarcate = nrPersoaneImbarcate;
		}
		else this->nrPersoaneImbarcate = 0;
	}

	//constructorul de copiere 

	Autobuz(Autobuz& a) :idAutobuz(nrAutobuze++) {
		this->capacitate = a.capacitate;
		this->producator = new char[strlen(a.producator) + 1];
		strcpy(this->producator, a.producator);
		if (nrPersoaneImbarcate < capacitate) {
			this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
		}
		else this->nrPersoaneImbarcate = 0;

	}
	//destructorul 

	~Autobuz() {
		delete[]this->producator;
	}
	//get si set pentru char* 

	char* getproducator() {
		return this->producator;
	}

	void setproducator(const char* producator_nou) {
		delete[]this->producator;
		this->producator = new char[strlen(producator_nou) + 1];
		strcpy(this->producator, producator_nou);

	}

	//nr persoane imbarcate get si set 
	//cand avem char* suntem obligati intotdeauna sa avem operatorul egal, must have!!1

	int getnrpersoaneImbarcate() {
		return this->nrPersoaneImbarcate;
	}

	void setnrPersoaneImbarcate(const int nrPersoaneImbarcate_noi) {

		if (nrPersoaneImbarcate_noi > capacitate) {
			this->nrPersoaneImbarcate = nrPersoaneImbarcate_noi;
		}
	}

	// operatorul egal 

	Autobuz& operator=(const Autobuz& a) {
		delete[]this->producator;
		this->producator = new char[strlen(a.producator) + 1];
		strcpy(this->producator, a.producator);
		if (nrPersoaneImbarcate < capacitate) {
			this->nrPersoaneImbarcate = a.nrPersoaneImbarcate;
		}
		else this->nrPersoaneImbarcate = 0;

		return *this;

	}

	//operatorul friend iostream plus ostream 

	friend ostream& operator<<(ostream& out, Autobuz& a) {
		out << a.idAutobuz << endl;
		out << a.capacitate << endl;
		out << a.producator << endl;
		out << a.nrPersoaneImbarcate << endl;

		return out;
	}

	// cu istream modificarul din consola un obiect deja existent, 

	friend istream& operator>>(istream& in, Autobuz& a) {
		cout << "Capacitatea de introdus este:" << endl;
		in >> a.capacitate;
		cout << "Producatorul este:" << endl;
		delete[]a.producator;
		char buffer[20];
		in >> buffer;
		a.producator = new char[strlen(buffer) + 1];
		strcpy(a.producator, buffer);
		cout << "Nr Persoanelor imbarcate este:" << endl;
		in >> a.nrPersoaneImbarcate;

		return in;


	}

};

int Autobuz::nrAutobuze = 0;

int main() {

	Autobuz a1;
	Autobuz a2(23, "Renault", 16);
	Autobuz a3(a2);
	cout << a1.getproducator() << endl;
	cout << a2.getproducator() << endl;

	//testam si afisam operatorul egal 
	a2 = a3;
	cout << a2 << endl;

	// afisam istream 

	cin >> a3;
	cout << a3 << endl;


}