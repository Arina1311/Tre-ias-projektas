
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

/*double Tarpinis (double M[], int k)
{
    double geriausias = M[0];
    for (int i = 1; i < k; i++) {
        if (M[i] < geriausias) {
            geriausias = M[i];
        }
    }
    return geriausias;
}
*/

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

