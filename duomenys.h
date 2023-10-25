
#ifndef DUOMENYS_H
#define DUOMENYS_H

#include <string>
#include <list>
using namespace std;

struct Studentas {
    string Vardas, Pavarde;
    list<int> NamuDarbai;
    int Egzaminas;
    float Pazymys;
};


float GalutinisPazymis(list<int>& duomenys, int egzaminas, char pasirinkimas);
bool palygintiPagalVarda(const Studentas &a, const Studentas &b);
bool palygintiPagalPavarde(const Studentas &a, const Studentas &b);
bool palygintiPagalPazymi(const Studentas &a, const Studentas &b);
double vidutiniai (double M[], int k);
double finalinis (double A[], double B[], double C[], double D[], double E[], int testavimask);

#endif 
