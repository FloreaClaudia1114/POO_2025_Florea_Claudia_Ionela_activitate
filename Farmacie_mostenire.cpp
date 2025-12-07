#include <iostream>
#include <string>
using namespace std;

class ExceptieCustom : public exception {
public:
    ExceptieCustom(const char* mesaj) : exception(mesaj) {}
};

class Medicament {
private:
    string denumire;
    float pret;
    int cantitate;
    static const float PRET_MINIM;

public:
    Medicament() {
        denumire = "Nedefinit";
        pret = 0;
        cantitate = 0;
    }

    Medicament(string denumire, float pret, int cantitate) {
        this->denumire = denumire;
        if (pret < PRET_MINIM) {
            throw ExceptieCustom("Pret invalid");
        }
        else {
            this->pret = pret;
        }
        this->cantitate = cantitate;
    }

    virtual void afisare() {
        cout << "Denumire: " << denumire
            << "\nPret: " << pret
            << "\nCantitate: " << cantitate << "\n";
    }

    virtual string getTip() = 0;
};

const float Medicament::PRET_MINIM = 1;

class MedicamentRaceala : public Medicament {
private:
    string substantaActiva;

public:
    MedicamentRaceala() : Medicament() {
        substantaActiva = "Nedefinita";
    }

    MedicamentRaceala(string denumire, float pret, int cantitate, string substanta)
        : Medicament(denumire, pret, cantitate)
    {
        substantaActiva = substanta;
    }

    void afisare() {
        Medicament::afisare();
        cout << "Substanta activa: " << substantaActiva << "\n\n";
    }

    string getTip() {
        return substantaActiva;
    }
};

int main() {
    Medicament* lista[3];
    lista[0] = new MedicamentRaceala("Parasinus", 25, 10, "Paracetamol");
    lista[1] = new MedicamentRaceala("Nurofen", 30, 5, "Ibuprofen");
    lista[2] = new MedicamentRaceala("Coldrex", 22, 8, "Paracetamol");

    for (int i = 0; i < 3; i++) {
        lista[i]->afisare();
        delete lista[i];
    }

    return 0;
}
