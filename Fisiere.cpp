#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Scoala {
private:
    string nume = "Necunoscut";
    char* adresa = nullptr;
    int nrElevi = 0;
    bool estePublica = true;

public:
    Scoala() {}

    Scoala(string nume, const char* adresa,
        int nrElevi, bool estePublica) {

        this->nume = nume;
        this->nrElevi = nrElevi;
        this->estePublica = estePublica;

        this->adresa = new char[strlen(adresa) + 1];
        strcpy_s(this->adresa, strlen(adresa) + 1, adresa);
    }

    ~Scoala() {
        if (this->adresa != nullptr) {
            delete[] this->adresa;
        }
    }

    Scoala(const Scoala& copie) {
        this->nume = copie.nume;
        this->nrElevi = copie.nrElevi;
        this->estePublica = copie.estePublica;

        if (copie.adresa != nullptr) {
            this->adresa = new char[strlen(copie.adresa) + 1];
            memcpy(this->adresa, copie.adresa, strlen(copie.adresa) + 1);
        }
        else {
            this->adresa = nullptr;
        }
    }

    friend void operator<<(ostream& out, Scoala s) {
        out << endl << "Nume scoala: " << s.nume;
        out << endl << "Nr elevi: " << s.nrElevi;
        out << endl << (s.estePublica ? "Institutie publica" : "Institutie privata");
        out << endl << (s.adresa != nullptr ? "Adresa: " + string(s.adresa) : "Adresa necunoscuta");
    }

    friend void operator<<(fstream& outFile, Scoala s) {
        outFile << s.nume << endl;
        outFile << s.nrElevi << endl;
        outFile << s.estePublica << endl;
        outFile << s.adresa << endl;
    }

    friend void operator>>(ifstream& inFile, Scoala& s) {
        inFile >> s.nume;
        inFile >> s.nrElevi;
        inFile >> s.estePublica;

        if (s.adresa != nullptr) {
            delete[] s.adresa;
            s.adresa = nullptr;
        }

        char buffer[50];
        inFile >> buffer;

        s.adresa = new char[strlen(buffer) + 1];
        strcpy_s(s.adresa, strlen(buffer) + 1, buffer);
    }
};

void main() {

    Scoala scoala1("LiceulNational", "StradaPrincipala", 850, true);

    fstream fileStream("Scoala.txt", ios::out);
    fileStream << scoala1;
    fileStream.close();

    Scoala copie;
    cout << copie;

    ifstream inputFileStream("Scoala.txt", ios::in);
    inputFileStream >> copie;
    inputFileStream.close();

    cout << copie;
}
