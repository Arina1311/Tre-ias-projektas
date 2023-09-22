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
    int StudentuSkaicius, NDSkaicius, NDSuma=0;
    char Pasirinkimas;

    cout << "Iveskite studentu skaiciu: ";
    cin >> StudentuSkaicius;

   
    for (int i = 0; i < StudentuSkaicius; i++) 
    {   
        
        cout << "Iveskite varda ir pavarde studento: ";
        cin >> Laikinas.Vardas >> Laikinas.Pavarde;

        Laikinas.Vidurkis = 0.0;
        Laikinas.Mediana = 0.0;

        NDSkaicius = 0;

        cin.ignore();

        while (true) 
        { 
            cout << "Iveskite namu darbo pazymi arba pastauskite ENTER du kartus, kad pabaigtumete ivedima: ";
            string NDpaz;
            getline(cin, NDpaz);

            if (NDpaz.empty()) {
                if (NDSkaicius == 0) {
                    cerr << "Klaida. Reikalingas bent vienas namu darbas." << endl;
                    continue;
                }
                break;
            }   

            if (cin.fail()) {
                cerr << "Klaida: Netinkama ivestis. Prašome ivesti skaiciu." << endl;
                cin.clear();
                continue;
            }

            int rezultatas = stoi(NDpaz);
            Laikinas.NamuDarbai.push_back(rezultatas);
            NDSuma += rezultatas;
            NDSkaicius++;
        }
        cout << "Iveskite egzamino pazymi: ";
        cin >> Laikinas.Egzaminas;

        // Skaiciuojame galutini vidurki
        Laikinas.Vidurkis = GalutinisVidurkis(NDSuma, Laikinas.NamuDarbai, Laikinas.Egzaminas);

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

