#include "duomenys.h"
#include <algorithm>
#include <vector>

float GalutinisPazymis(double suma, std::vector<int>& duomenys, int egzaminas, char pasirinkimas) {
    if (duomenys.empty()) {
        // Handle empty vector
        return 0.6 * egzaminas;
    }

    int kiekis = duomenys.size();
    float galutinis;

    if (pasirinkimas == 'V' || pasirinkimas == 'v') {
        galutinis = 0.4 * (suma / kiekis) + 0.6 * egzaminas;
    } else {
        std::vector<int> duomenysKopija = duomenys;
        std::sort(duomenysKopija.begin(), duomenysKopija.end());
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

double finalinis(double A[], double B[], double C[], double D[], double E[], int testavimask) {
    std::vector<double> F(testavimask);
    for (int i = 0; i < testavimask; i++) {
        F[i] = A[i] + B[i] + C[i] + D[i] + E[i];
    }

    if (F.empty()) {
        // Handle empty vector
        return 0.0;
    }

    double suma = 0;
    for (int k = 0; k < testavimask; k++) {
        suma += F[k];
    }

    double vidurkis = suma / testavimask;
    return vidurkis;
}

bool isVargsiukas(const Studentas &studentas) {
    return studentas.pazymys() < 5.0;
}
