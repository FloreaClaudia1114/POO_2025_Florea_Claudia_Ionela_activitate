#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

class Baterie {
private:
    string tipIntrare;
    int greutate;
    char* producator;
public:
    int capacitate;
    static int nrBaterii;

    Baterie() {
        this->tipIntrare = "";
        this->capacitate = 0;
        this->greutate = 0;
        this->producator = nullptr;
    }

    Baterie(string tipIntrre, int getCapacitate,
        int getGreutate, const char* producator) {

        this->tipIntrare = tipIntrre;
        this->capacitate = getCapacitate;
        this->greutate = getGreutate;

        if (producator != nullptr) {
            this->producator = new char[strlen(producator) + 1];
            strcpy_s(this->producator, strlen(producator) + 1, producator);
        }
        else {
            this->producator = nullptr;
        }
    }

    Baterie(const Baterie& b) {
        this->tipIntrare = b.tipIntrare;
        this->capacitate = b.capacitate;
        this->greutate = b.greutate;

        if (b.producator != nullptr) {
            this->producator = new char[strlen(b.producator) + 1];
            strcpy_s(this->producator, strlen(b.producator) + 1, b.producator);
        }
        else {
            this->producator = nullptr;
        }
    }

    ~Baterie() {
        delete[] this->producator;
    }

    Baterie& operator=(const Baterie& b) {
        if (this == &b) return *this;

        delete[] this->producator;

        this->tipIntrare = b.tipIntrare;
        this->capacitate = b.capacitate;
        this->greutate = b.greutate;

        if (b.producator != nullptr) {
            this->producator = new char[strlen(b.producator) + 1];
            strcpy_s(this->producator, strlen(b.producator) + 1, b.producator);
        }
        else {
            this->producator = nullptr;
        }

        return *this;
    }

    string getTipIntrare() { return this->tipIntrare; }
    int getCapacitate() { return this->capacitate; }
    int getGreutate() { return this->greutate; }
    char* getProducator() { return this->producator; }

    friend ostream& operator<<(ostream& out, const Baterie& b) {
        out << b.tipIntrare << " " << b.capacitate << " "
            << b.greutate << " ";
        if (b.producator) out << b.producator;
        return out;
    }

    Baterie& operator+=(int add) {
        this->capacitate += add;
        return *this;
    }

    Baterie& operator-=(int scad) {
        this->capacitate -= scad;
        return *this;
    }
};

int Baterie::nrBaterii = 0;

int main() {
    Baterie b1("Intrare tip A", 7500, 250, "Samsung");
    Baterie b2("Intrare tip C", 10000, 500, "Xiaomi");

    cout << b1 << endl;
    cout << b2 << endl;

    b1 += 200;
    b2 -= 1500;

    cout << b1.getCapacitate() << endl;
    cout << b2.getCapacitate() << endl;

    return 0;
}
