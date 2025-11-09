#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class Farmacie {
private:
    const int CODUnic;
    static int contor;
    char* adresa;
    int nrMedicamente;
    float* preturiMedicamente;

public:
    // --- Constructor fara parametri ---
    Farmacie() : CODUnic(++contor) {
        adresa = new char[strlen("Necunoscuta") + 1];
        strcpy(adresa, "Necunoscuta");
        nrMedicamente = 0;
        preturiMedicamente = nullptr;
    }

    // --- Constructor cu parametri ---
    Farmacie(const char* adresa, int nrMedicamente, const float* preturi) : CODUnic(++contor) {
        if (adresa == nullptr || nrMedicamente < 0) {
            throw invalid_argument("Parametrii invalizi!");
        }
        this->adresa = new char[strlen(adresa) + 1];
        strcpy(this->adresa, adresa);

        this->nrMedicamente = nrMedicamente;
        if (nrMedicamente > 0) {
            preturiMedicamente = new float[nrMedicamente];
            for (int i = 0; i < nrMedicamente; i++) {
                preturiMedicamente[i] = preturi[i];
            }
        }
        else {
            preturiMedicamente = nullptr;
        }
    }

    // --- Constructor de copiere ---
    Farmacie(const Farmacie& f) : CODUnic(++contor) {
        adresa = new char[strlen(f.adresa) + 1];
        strcpy(adresa, f.adresa);
        nrMedicamente = f.nrMedicamente;

        if (nrMedicamente > 0) {
            preturiMedicamente = new float[nrMedicamente];
            for (int i = 0; i < nrMedicamente; i++)
                preturiMedicamente[i] = f.preturiMedicamente[i];
        }
        else {
            preturiMedicamente = nullptr;
        }
    }

    // --- Destructor ---
    ~Farmacie() {
        delete[] adresa;
        delete[] preturiMedicamente;
    }

    // --- Operator de atribuire ---
    Farmacie& operator=(const Farmacie& f) {
        if (this != &f) {
            delete[] adresa;
            delete[] preturiMedicamente;

            adresa = new char[strlen(f.adresa) + 1];
            strcpy(adresa, f.adresa);

            nrMedicamente = f.nrMedicamente;

            if (nrMedicamente > 0) {
                preturiMedicamente = new float[nrMedicamente];
                for (int i = 0; i < nrMedicamente; i++)
                    preturiMedicamente[i] = f.preturiMedicamente[i];
            }
            else {
                preturiMedicamente = nullptr;
            }
        }
        return *this;
    }

    // --- Getteri si setteri ---
    const char* getAdresa() const { return adresa; }
    void setAdresa(const char* a) {
        if (a != nullptr) {
            delete[] adresa;
            adresa = new char[strlen(a) + 1];
            strcpy(adresa, a);
        }
    }

    int getNrMedicamente() const { return nrMedicamente; }
    int getCODUnic() const { return CODUnic; }

    // --- Metoda getNrMedicamenteIeftine ---
    int getNrMedicamenteIeftine(float prag) const {
        int nr = 0;
        for (int i = 0; i < nrMedicamente; i++)
            if (preturiMedicamente[i] < prag)
                nr++;
        return nr;
    }

    // --- Operator > ---
    bool operator>(const Farmacie& f) const {
        return nrMedicamente > f.nrMedicamente;
    }

    // --- Operator [] ---
    float operator[](int index) const {
        if (index >= 0 && index < nrMedicamente)
            return preturiMedicamente[index];
        throw out_of_range("Index invalid!");
    }

    // --- Operator << ---
    friend ostream& operator<<(ostream& out, const Farmacie& f) {
        out << "Farmacie [COD: " << f.CODUnic << "]\n";
        out << "Adresa: " << f.adresa << "\n";
        out << "Numar medicamente: " << f.nrMedicamente << "\nPreturi: ";
        for (int i = 0; i < f.nrMedicamente; i++)
            out << f.preturiMedicamente[i] << " ";
        out << "\n";
        return out;
    }

    // --- Operator >> ---
    friend istream& operator>>(istream& in, Farmacie& f) {
        char buffer[100];
        cout << "Introdu adresa: ";
        in >> ws;
        in.getline(buffer, 100);

        cout << "Introdu numarul de medicamente: ";
        in >> f.nrMedicamente;

        delete[] f.adresa;
        delete[] f.preturiMedicamente;

        f.adresa = new char[strlen(buffer) + 1];
        strcpy(f.adresa, buffer);

        if (f.nrMedicamente > 0) {
            f.preturiMedicamente = new float[f.nrMedicamente];
            cout << "Introdu preturile medicamentelor:\n";
            for (int i = 0; i < f.nrMedicamente; i++)
                in >> f.preturiMedicamente[i];
        }
        else {
            f.preturiMedicamente = nullptr;
        }

        return in;
    }
};

// --- Initializare atribut static ---
int Farmacie::contor = 0;


int main() {
    float preturi1[] = { 12.5, 20.0, 8.9 };
    Farmacie f1("Str. Lalelelor 10", 3, preturi1);

    Farmacie f2;
    cin >> f2;

    cout << "\n--- Afisare farmacii ---\n";
    cout << f1 << endl;
    cout << f2 << endl;

    cout << "Nr medicamente ieftine (<15 lei) in f1: " << f1.getNrMedicamenteIeftine(15) << endl;

    if (f1 > f2)
        cout << "Prima farmacie are mai multe medicamente.\n";
    else
        cout << "A doua farmacie are mai multe sau egale medicamente.\n";

    cout << "Pretul primului medicament din f1: " << f1[0] << " lei\n";

    return 0;
}
