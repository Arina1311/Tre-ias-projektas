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

int main() {

    Studentas Laikinas; 
    vector<Studentas> grupe;
    int StudentuSkaicius, NDSkaicius;
    char Pasirinkimas;

    cout << "Iveskite studentu skaiciu: ";
    cin >> StudentuSkaicius;

   
    for (int i = 0; i < StudentuSkaicius; i++) {
        
        cout << "Iveskite varda ir pavarde studento: ";
        cin >> Laikinas.Vardas >> Laikinas.Pavarde;

        cout << "Iveskite namu darbu skaiciu: ";
        cin >> NDSkaicius;

        int NDVidurkis = 0; // Kiekvienam studentui naujas vidurkis

        for (int j = 0; j < NDSkaicius; j++) {
            int k;
            cout << "Iveskite " << j + 1 << " pazymi: ";
            cin >> k;
            Laikinas.NamuDarbai.push_back(k); // Tiknka jeigu reikie perziureti namu darbu rezultatus
            NDVidurkis += k;
        }

        NDVidurkis /= NDSkaicius; 

        cout << "Iveskite egzamino pazymi: ";
        cin >> Laikinas.Egzaminas;

        // Skaiciuojame galutini vidurki
        Laikinas.Vidurkis = Laikinas.Egzaminas * 0.6 + NDVidurkis * 0.4;

        // Skaiciuojame mediana, pirmiausia sorta atliekame teisingam duomenu isdestymui
        sort(Laikinas.NamuDarbai.begin(), Laikinas.NamuDarbai.end());
        int vid = NDSkaicius / 2;

        //Naudojame vektoriaus metodus
        if (NDSkaicius % 2 == 0) 
            Laikinas.Mediana = (Laikinas.NamuDarbai[vid - 1] + Laikinas.NamuDarbai[vid]) / 2.0;
        else 
            Laikinas.Mediana = Laikinas.NamuDarbai[vid];

        grupe.push_back(Laikinas);
        Laikinas.NamuDarbai.clear();
    }

    //Leidziame vartotojui pasirinkti norima skaiciavimo buda
    cout << "Noredami apskaiciuoti vidurki iveskite (V), mediana (M) ";
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
