
#include "duomenys.h"
#include <algorithm>

float GalutinisPazymis(double suma, vector<int>& duomenys, int egzaminas, char pasirinkimas) {
    int kiekis = duomenys.size();
    float galutinis;
    
    if (pasirinkimas == 'V' || pasirinkimas == 'v') {
        galutinis = 0.4 * (suma / kiekis) + 0.6 * egzaminas;
    } else {
        vector<int> duomenysKopija = duomenys;
        sort(duomenysKopija.begin(), duomenysKopija.end());
        int dydis = duomenysKopija.size();
        int vid = dydis / 2;
        if (dydis % 2 == 0) {
            galutinis = 0.4 * (duomenysKopija[vid - 1] + duomenysKopija[vid]) / 2.0 + 0.6 * egzaminas;
        } else {
            galutinis = 0.4 * duomenysKopija[vid] + 0.6 * egzaminas;
        }
    }

    return galutinis;
}
bool palygintiPagalPazymi(const Studentas &a, const Studentas &b) {
    return a.Pazymys < b.Pazymys;
}

bool palygintiPagalPavarde(const Studentas &a, const Studentas &b) {
    return a.Pavarde < b.Pavarde;
}

bool palygintiPagalVarda(const Studentas &a, const Studentas &b) {
    return a.Vardas < b.Vardas;
}

double vidutiniai (double M[], int k)
{
    double sumav=0;
    for (int i = 0; i < k; i++) {
        sumav += M[i];
    }
    double vid = sumav / k;
    return vid;
}

double finalinis(double A[], double B[], double C[], double D[], double E[], int testavimask) {
    double F[testavimask];
    for (int i = 0; i < testavimask; i++) {
        F[i] = A[i] + B[i] + C[i] + D[i] + E[i];
    }

    double suma = 0;
    for (int k = 0; k < testavimask; k++) {
        suma += F[k];
    }

    double vidurkis = suma / testavimask;
    return vidurkis;
}

bool isVargsiukas(const Studentas &studentas) {
                    return studentas.Pazymys < 5.0;
                }


