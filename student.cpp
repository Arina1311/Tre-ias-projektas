#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Studentas {
    string Vardas, Pavarde;
    vector<int> NamuDarbai;
    int Egzaminas;
    float Vidurkis = 0.0;
    double Mediana;
};

//-----------------Galutinis su vidurkiu--------------
float GalutinisVidurkis (double suma, vector<int> duomenys, int egzaminas)
{
    int kiekis = duomenys.size();
    return 0.4 * (suma/kiekis) + 0.6 * egzaminas;
}

//-----------------------Mediana----------------------
double Mediana (vector<int> duomenys)
{
    sort(duomenys.begin(), duomenys.end());
    int dydys = duomenys.size();
    int vid = dydys/2;
        if (dydys % 2 == 0) 
            return (duomenys[vid - 1] + duomenys[vid]) / 2.0;
        else 
            return duomenys[vid];
        
}

//-----------------Galutinis su mediana---------------
double GalutinisMediana (double mediana, int egzaminas)
{
    return 0.4 * mediana + 0.6 * egzaminas;
}

//----------------------------------------------------


int main() {

    Studentas Laikinas; 
    vector<Studentas> grupe;
    int StudentuSkaicius, NDSkaicius;
    char Pasirinkimas;

    cout << "Iveskite studentu skaiciu: ";
    cin >> StudentuSkaicius;

   
    for (int i = 0; i < StudentuSkaicius; i++) 
    {
        cout << "Iveskite varda ir pavarde studento: ";
        cin >> Laikinas.Vardas >> Laikinas.Pavarde;

        cout << "Iveskite namu darbu skaiciu: ";
        cin >> NDSkaicius;

        double NDsuma = 0; // Kiekvienam studentui naujas vidurkis

        for (int j = 0; j < NDSkaicius; j++) 
        {
            int k;
            cout << "Iveskite " << j + 1 << " pazymi: ";
            cin >> k;
            Laikinas.NamuDarbai.push_back(k); // Tiknka jeigu reikie perziureti namu darbu rezultatus
            NDsuma += k;
        }

        cout << "Iveskite egzamino pazymi: ";
        cin >> Laikinas.Egzaminas;

        // Skaiciuojame galutini vidurkis
        Laikinas.Vidurkis = GalutinisVidurkis(NDsuma, Laikinas.NamuDarbai, Laikinas.Egzaminas);

        //Mediana
        double TarpineMediana = Mediana(Laikinas.NamuDarbai);
        Laikinas.Mediana = GalutinisMediana(TarpineMediana, Laikinas.Egzaminas);

        grupe.push_back(Laikinas);
        Laikinas.NamuDarbai.clear();

    }

    //Leidziame vartotojui pasirinkti norima skaiciavimo buda
    cout << "Noredami apskaiciuoti vidurki iveskite (V) ar mediana (M) ";
    cin >> Pasirinkimas;

    cout << fixed << setprecision(2);
    cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << (Pasirinkimas == 'V' ? "Galutinis (Vid.)" : "Galutinis (Med.)") << endl;
    
    cout << "---------------------" << "---------------------" << "---------------------" << endl;

    for (auto &a : grupe) 
    {
        cout << left << setw(15) << a.Vardas << setw(15) << a.Pavarde << setw(15) << (Pasirinkimas == 'V' ? a.Vidurkis : a.Mediana) << endl;
    }

    return 0;
}
