
#include "duomenys.h"
#include <algorithm>

float GalutinisVidurkis(double suma, vector<int> duomenys, int egzaminas) {
    int kiekis = duomenys.size();
    return 0.4 * (suma / kiekis) + 0.6 * egzaminas;
}

double Mediana(vector<int> duomenys) {
    sort(duomenys.begin(), duomenys.end());
    int dydis = duomenys.size();
    int vid = dydis / 2;
    if (dydis % 2 == 0)
        return (duomenys[vid - 1] + duomenys[vid]) / 2.0;
    else
        return duomenys[vid];
}

double GalutinisMediana(double mediana, int egzaminas) {
    return 0.4 * mediana + 0.6 * egzaminas;
}

bool palygintiPagalPavarde(const Studentas &a, const Studentas &b) {
    return a.Pavarde < b.Pavarde;
}

bool palygintiPagalVarda(const Studentas &a, const Studentas &b) {
    return a.Vardas < b.Vardas;
}
