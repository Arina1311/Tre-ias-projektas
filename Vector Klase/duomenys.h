#ifndef DUOMENYS_H
#define DUOMENYS_H

#include <string>
#include <vector>
using namespace std;

class Studentas {
    private:
    string Vardas, Pavarde;
    vector<int> ND;
    int Egzaminas;
    float Pazymys;

public:
    // Konstruktoriai
    Studentas() : Egzaminas(0), Pazymys(0) { }

    //Destruktorius
    ~Studentas() = default;

    // Get'eriai - gauti
    inline string vardas() const { return Vardas; }
    inline string pavarde() const { return Pavarde; }
    inline vector<int> namuDarbai() const { return ND; }
    inline int egzaminas() const { return Egzaminas; }
    inline float pazymys() const { return Pazymys; }

    // Setteriai - pakeisti
    inline void setVardas(const string& naujasVardas) { Vardas = naujasVardas; }
    inline void setPavarde(const string& naujaPavarde) { Pavarde = naujaPavarde; }
    inline void setNamuDarbai(const vector<int>& naujiND) { ND = naujiND; }
    inline void setEgzaminas(int naujasEgzaminas) { Egzaminas = naujasEgzaminas; }
    inline void setPazymys(float naujasPazymys) { Pazymys = naujasPazymys; }

    void NDPrideti(int pazymys) {
        ND.push_back(pazymys);
    }

    vector<int> getND() const {
        return ND;
    }
};

// Funkcijos liko tokios pat
float GalutinisPazymis(double suma, vector<int>& duomenys, int egzaminas, char pasirinkimas);
bool palygintiPagalVarda(const Studentas &a, const Studentas &b);
bool palygintiPagalPavarde(const Studentas &a, const Studentas &b);
bool palygintiPagalPazymi(const Studentas &a, const Studentas &b);
double vidutiniai(double M[], int k);
double finalinis(double A[], double B[], double C[], double D[], double E[], int testavimask);
bool isVargsiukas(const Studentas &studentas);

#endif  // DUOMENYS_H

