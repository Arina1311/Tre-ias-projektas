#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Studentas {
    string Vardas, Pavarde;
    vector<int> NamuDarbai;
    int Egzaminas;
    float Vidurkis = 0.0;
};

int main() {

    Studentas Laikinas; 
    vector<Studentas> grupe;
    int StudentuSkaicius, NDSkaicius;

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

        Laikinas.Vidurkis = Laikinas.Egzaminas * 0.6 + NDVidurkis * 0.4;

        grupe.push_back(Laikinas);
        Laikinas.NamuDarbai.clear();
    }

    cout << fixed << setprecision(2);
    cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis (Vid.)" << endl;
    cout << "---------------------" << "---------------------" << "---------------------" << endl;

    for (auto &a : grupe) {
        cout << left << setw(15) << a.Vardas << setw(15) << a.Pavarde << setw(15) << a.Vidurkis << endl;
    }

    return 0;
}
