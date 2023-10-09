
#ifndef DUOMENYS_H
#define DUOMENYS_H

#include <string>
#include <vector>
using namespace std;

struct Studentas {
    string Vardas, Pavarde;
    vector<int> NamuDarbai;
    int Egzaminas;
    float Vidurkis;
    double Mediana;
};

float GalutinisVidurkis(double suma, vector<int> duomenys, int egzaminas);
double Mediana(vector<int> duomenys);
double GalutinisMediana(double mediana, int egzaminas);

bool palygintiPagalPavarde(const Studentas &a, const Studentas &b);
bool palygintiPagalVarda(const Studentas &a, const Studentas &b);
//double Tarpinis (double M[], int k);
double vidutiniai (double M[], int k);
double finalinis (double A[], double B[], double C[], double D[], double E[], int testavimask);

#endif 
