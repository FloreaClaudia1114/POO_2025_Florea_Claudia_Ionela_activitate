#include <iostream>
#include <string>

using namespace std;

class Vapor {

private:
	int capacitate;
	int nrPersoaneImbarcate;
	int* varstePasageri;
	const int idVapor;
	static int nrVapor;
	bool areOpriri;
	

public:
	Vapor() : idVapor(nrVapor++) {
		capacitate = 0;
		nrPersoaneImbarcate = 0;
		varstePasageri = nullptr;
		areOpriri = false;
	}

	
	Vapor(int capacitate, int nrPersoaneImabarcate, int* varstePasageri, bool areOpriri) :idVapor(nrVapor++) {
		this->capacitate = capacitate;
		if (nrPersoaneImabarcate <= capacitate) {
			this->nrPersoaneImbarcate = nrPersoaneImabarcate;
		}

		this->varstePasageri = new int[nrPersoaneImabarcate];
		for (int i = 0;i < this->nrPersoaneImbarcate;i++) {
			this->varstePasageri[i] = varstePasageri[i];
		}
		this->areOpriri = areOpriri;
	}
	
	~Vapor() {
		delete[]this->varstePasageri;
	};
	
	Vapor(const Vapor& v) :idVapor(nrVapor++) {
		this->capacitate = v.capacitate;
		if (nrPersoaneImbarcate <= capacitate) {
			this->nrPersoaneImbarcate = v.nrPersoaneImbarcate;
		} 

		this->varstePasageri = new int[nrPersoaneImbarcate];
		for (int i = 0;i < this->nrPersoaneImbarcate;i++) {
			this->varstePasageri[i] = v.varstePasageri[i];
		}
		this->areOpriri = v.areOpriri;

	}
	
	static int getnrVapor() {
		return nrVapor;
	}
	bool getareOpriri() {
		return this->areOpriri;
	}
	
	static void setnrVapor(int nrNouVapor) {
		nrVapor = nrNouVapor;
	}

	void setAreOpriri(bool areOpriri) {
		this->areOpriri = areOpriri;
	}
	
	Vapor& operator=(const Vapor& v) {
		if (this != &v) 
		{
			this->capacitate = v.capacitate;
			if (nrPersoaneImbarcate <= capacitate) {
				this->nrPersoaneImbarcate = v.nrPersoaneImbarcate;
			}

			delete[]this->varstePasageri;
			this->varstePasageri = new int[nrPersoaneImbarcate];
			for (int i = 0;i < this->nrPersoaneImbarcate;i++) {
				this->varstePasageri[i] = v.varstePasageri[i];
			}
			this->areOpriri = v.areOpriri;
		}

		return *this;
	};
	
	friend ostream& operator <<(ostream& out, Vapor& v) {
		out << v.capacitate << "," << v.nrPersoaneImbarcate << ";";
		if (v.varstePasageri != nullptr) {
			for (int i = 0;i < v.nrPersoaneImbarcate;i++) {
				out << v.varstePasageri[i] << ",";
			}


		}
		out << v.areOpriri << ";";
		return out;
	}

	

	float calculareVarstaMedie() {

		int suma = 0;
		for (int i = 0;i < nrPersoaneImbarcate;i++) {
			suma += varstePasageri[i];

		}
		return suma / nrPersoaneImbarcate;

	}

	

	int operator()() {
		return capacitate - nrPersoaneImbarcate;
	}
	

	operator int() {
		int nrMinori = 0;
		
		for (int i = 0;i < nrPersoaneImbarcate;i++) {
			if (varstePasageri[i] < 18) {
				nrMinori++;
			}
		}
		return nrMinori;
	}

};

int Vapor::nrVapor = 0;

int main() {
	Vapor v1;
	cout << v1 << endl;
    
	int varste[] = { 17,20,23,10,15,30 };
	Vapor v2(20, 6, varste, true);
	cout << v2 << endl;

	Vapor v3(v2);
	cout << v3 << endl;

	Vapor v4 = v3;
	cout << v4 << endl;

	cout << v2() << endl;

	int nrMinori = (int)v2;
	cout << nrMinori << endl;
}


