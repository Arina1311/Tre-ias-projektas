#ifndef DUOMENYS_H
#define DUOMENYS_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <cstdlib> 
#include <random>
using namespace std;

class Zmogus {
protected:
    string Vardas, Pavarde;

public:
    // Konstruktoriai   
    Zmogus(const string& vardas, const string& pavarde) :
             Vardas(vardas), Pavarde(pavarde) {}
    
    virtual ~Zmogus() = 0;

     //Geteriai
     virtual inline string vardas() const { return Vardas; }
     virtual inline string pavarde() const { return Pavarde; }

     //Setteriai
     virtual void setvardas(const string& naujasVardas) { Vardas = naujasVardas; }
     virtual void setpavarde(const string& naujaPavarde) { Pavarde = naujaPavarde; }
     virtual void informacija() const = 0;
 };

class Studentas {
private:
    string Vardas, Pavarde;
    vector<int> ND;
    int Egzaminas;
    float Pazymys;

public:
    // Konstruktoriai
    Studentas() : Vardas(" "), Pavarde(" "), Egzaminas(0), Pazymys(0) {}

    //Parametrizuotas
    Studentas(const string& vardas, const string& pavarde, const vector<int>& nd, int egzaminas, float pazymys)
        : Vardas(vardas), Pavarde(pavarde), ND(nd), Egzaminas(egzaminas), Pazymys(pazymys) {}

    
    // Kopijavimo konstruktorius
    Studentas(const Studentas& other)
        : Vardas(other.Vardas), Pavarde(other.Pavarde), ND(other.ND),
          Egzaminas(other.Egzaminas), Pazymys(other.Pazymys) {}


    // Priskyrimo operatorius
    Studentas& operator=(const Studentas& other) {
        if (this != &other) {
            Vardas = other.Vardas;
            Pavarde = other.Pavarde;
            ND = other.ND;
            Egzaminas = other.Egzaminas;
            Pazymys = other.Pazymys;
        }
        return *this;
    }

    //Destruktorius
    ~Studentas() {
        ND.clear();
    }

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

    
    float ApskaiciuotiGalutiniPazymi() {
        char Pasirinkimas;
        cout << "Pagal ka norite apskaiciuoti galutini pazymy V - vidurkis, M - mediana: ";
        cin >> Pasirinkimas;

        int kiekis = ND.size();
        float galutinis;

        if (Pasirinkimas == 'V' || Pasirinkimas == 'v') {
            galutinis = 0.4 * (accumulate(ND.begin(), ND.end(), 0) / kiekis) + 0.6 * Egzaminas;

        } else {
            vector<int> duomenysKopija = ND;
            sort(duomenysKopija.begin(), duomenysKopija.end());
            int dydis = duomenysKopija.size();
            int vid = dydis / 2;
            if (dydis % 2 == 0) {
                galutinis = 0.4 * (duomenysKopija[vid - 1] + duomenysKopija[vid]) / 2.0 + 0.6 * Egzaminas;
            } else {
                galutinis = 0.4 * duomenysKopija[vid] + 0.6 * Egzaminas;
            }
        }
        return galutinis;
    }

    // Įvesties operatorius
    friend istream& operator>>(istream& in, Studentas& student) {
       
            cout << "Iveskite varda ir pavarde studento: ";
            in >> student.Vardas >> student.Pavarde;
            
            char ats;
            cout << "Ar norite generuoti pazymius (T -taip, N - ne)? ";
            in >> ats;
            if (ats == 'T' || ats == 't'){
            // Generuojame atsitiktinius namų darbų balus
            int minBalas = 1;
            int maxBalas = 10;
            int baluSkaicius;
            cout << "Iveskite kiek norite pazymiu sugeneruoti: ";
            in >> baluSkaicius;

            mt19937 mt(1729);  
            uniform_int_distribution<int> dist(minBalas, maxBalas);

            for (int j = 0; j < baluSkaicius; j++) {
                int atsitiktinisBalas = dist(mt);
                student.NDPrideti(atsitiktinisBalas);
            }

            // Generuojame atsitiktinį egzamino balą
            int egzaminoBalas = dist(mt);
            student.setEgzaminas(egzaminoBalas); 

            vector<int> namu = student.namuDarbai();
            double suma = accumulate(namu.begin(),namu.end(),0);

            student.setPazymys(student.ApskaiciuotiGalutiniPazymi()) ;
            }
            else {
                in.ignore();

                while (true) {
                cout << "Iveskite namu darbo pazymi arba pastauskite ENTER du kartus, kad pabaigtumete ivedima: ";
                string NDpaz;
                getline(in, NDpaz);

                try {
                    if (NDpaz.empty()) {
                        if (student.namuDarbai().size() == 0) {
                            throw invalid_argument("Klaida. Reikalingas bent vienas namu darbas.");
                        }
                        break;
                    }

                    if (in.fail()) {
                        throw invalid_argument("Klaida: Netinkama ivestis. Prašome ivesti skaiciu.");
                    }

                    int pazymys = stoi(NDpaz); //konvertuojama i int skaiciu

                    student.NDPrideti(pazymys);

                } catch (const invalid_argument &e) {
                    cerr << e.what() << endl;
                    in.clear();
                    in.ignore(numeric_limits<streamsize>::max(), '\n');
                }
            }

                cout << "Iveskite egzamino pazymi: ";
                int egz;
                in >> egz;
                student.setEgzaminas(egz);
                
                vector<int> namu = student.namuDarbai();
                double suma = accumulate(namu.begin(),namu.end(),0);

                student.setPazymys(student.ApskaiciuotiGalutiniPazymi()) ;
            }

        return in;
    }


    // Išvesties operatorius
    friend ostream& operator<<(ostream& out, const Studentas& student) {
        out << left << setw(15) << student.Vardas << setw(15) << student.Pavarde << setw(20) << student.Pazymys << endl;
        return out;
    }

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

