#include <iostream>
#include <string>
using namespace std;

class Ferma {
public:
    string nume;
    const double taxaPeHectar;
    static int totalFerme;
    double* suprafata;
};

class Cultura {
public:
    string tipPlanta;
    bool esteBio;
    const int nrRanduri;
    double* productie;
};

class Ingredient {
public:
    string denumire;
    double cantitate;
    static int totalIngrediente;
    double* pret;
    const int cod;
};