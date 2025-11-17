#define _CRT_SECURE_NO_WARNINGS
#include <iostream>;
#include <string>;

using namespace std;

class Farmacie {
private:
	int const CODUnic;
	static int contorCod;
	char* adresa;
	int nrMedicamente;
	float* preturiMedicamente;



public:
	Farmacie() :CODUnic(contorCod++) {
		this->adresa = new char[strlen("adresa") + 1];
		strcpy(this->adresa, "adresa");
		nrMedicamente = 0;
		preturiMedicamente = nullptr;
	}



	Farmacie(int nrMedicamente, const char* adresa, float* preturiMedicamente) :CODUnic(contorCod++) {
		this->adresa = new char[strlen(adresa) + 1];
		strcpy(this->adresa, adresa);
		this->nrMedicamente = nrMedicamente;


		if (nrMedicamente > 0) {
			this->preturiMedicamente = new float[nrMedicamente];
			for (int i = 0;i < nrMedicamente;i++) {
				this->preturiMedicamente[i] = preturiMedicamente[i];
			}
		}
		else preturiMedicamente = nullptr;

	}


	Farmacie(Farmacie& f) :CODUnic(contorCod++) {
		this->adresa = new char[strlen(f.adresa) + 1];
		strcpy(this->adresa, f.adresa);
		this->nrMedicamente = f.nrMedicamente;


		if (nrMedicamente > 0) {
			this->preturiMedicamente = new float[f.nrMedicamente];
			for (int i = 0;i < nrMedicamente;i++) {
				this->preturiMedicamente[i] = f.preturiMedicamente[i];
			}
		}
		else preturiMedicamente = nullptr;
	}


	~Farmacie() {
		delete[]this->adresa;
		delete[]this->preturiMedicamente;
	}


	char* getadresa() {
		return adresa;
	}

	void setadresa(const char* adresanoua) {
		delete[]this->adresa;
		this->adresa = new char[strlen(adresa) + 1];
		strcpy(this->adresa, adresa);

	}



	int getnrMedicamente() {
		return nrMedicamente;
	}



	int getCODUnic() {
		return CODUnic;
	}



	void setpreturiMedicamente(float* preturiMedicamente, int nrMedicamente) {
		delete[]this->preturiMedicamente;
		this->nrMedicamente = nrMedicamente;
		if (nrMedicamente > 0) {
			this->preturiMedicamente = new float[nrMedicamente];
			for (int i = 0;i < nrMedicamente;i++) {
				this->preturiMedicamente[i] = preturiMedicamente[i];
			}
		}
		else preturiMedicamente = nullptr;
	}


	Farmacie& operator=(Farmacie& f) {

		delete[]this->adresa;
		delete[]this->preturiMedicamente;


		this->adresa = new char[strlen(f.adresa) + 1];
		strcpy(this->adresa, f.adresa);
		this->nrMedicamente = f.nrMedicamente;


		if (nrMedicamente > 0) {
			this->preturiMedicamente = new float[f.nrMedicamente];
			for (int i = 0;i < nrMedicamente;i++) {
				this->preturiMedicamente[i] = f.preturiMedicamente[i];
			}
		}
		else preturiMedicamente = nullptr;
		return *this;
	}


	friend ostream& operator <<(ostream& out, const Farmacie& f) {
		out << f.CODUnic << endl;
		out << f.adresa << endl;
		out << f.nrMedicamente << endl;
		for (int i = 0;i < f.nrMedicamente; i++) {
			out << f.preturiMedicamente[i] << endl;
		}
		return out;
	}


};
int Farmacie::contorCod = 0;

int main() {
	Farmacie f1;
	cout << f1 << endl;

	Farmacie f2(2, "Strada Compex", new float[2] {25, 100});
	cout << f2 << endl;

}