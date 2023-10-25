
#include "duomenys.h"
#include <algorithm>

float GalutinisPazymis(list<int>& duomenys, int egzaminas, char pasirinkimas) {
    int kiekis = duomenys.size();
    float galutinis;
    
    if (pasirinkimas == 'V' || pasirinkimas == 'v') {
        // kitaip sudedame elementus
        double sumaDuomenu = 0.0;
        for (list<int>::iterator it = duomenys.begin(); it != duomenys.end(); ++it) {
            sumaDuomenu += *it;
        }
        galutinis = 0.4 * (sumaDuomenu / kiekis) + 0.6 * egzaminas;

    } else {
        list<int> duomenysKopija = duomenys;
        duomenysKopija.sort();
        int vid = kiekis / 2;

        list<int>::iterator it = duomenysKopija.begin(); // iteratoris it, rodo į pradžią.
        advance(it, vid); //Perstumiu iteratorių it per vid pozicijų, dabar jis rodo į vidurio elementą.

        if (kiekis % 2 == 0) {
            // If the list has an even number of elements, calculate the median
            int pirmas = *prev(it); //pirmas vid elem
            int antras = *it;  //antras vid elem
            galutinis = 0.4 * (pirmas + antras) / 2.0 + 0.6 * egzaminas;

        } else {
            galutinis = 0.4 * *it + 0.6 * egzaminas;
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

