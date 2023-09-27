#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib> 
#include <fstream>
#include <sstream>

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
//-------------Palyginimas pagal pavarde--------------
bool palygintiPagalPavarde(const Studentas& a, const Studentas& b) {
    return a.Pavarde < b.Pavarde;
}
//------------Palyginimas pagal varda-----------------
bool palygintiPagalVarda(const Studentas& a, const Studentas& b) {
    return a.Vardas < b.Vardas;
}
//----------------------------------------------------
int main() {

    Studentas Laikinas; 
    vector<Studentas> grupe;
    int StudentuSkaicius, NDSkaicius, NDSuma=0;
    char Pasirinkimas;

    char parinktis;
    cout <<"Iveskite raide (R), jei norite rašyti duomenis savarankiškai ir (F) jeigu norite nuskaityti iš failo: ";
    cin >> parinktis;

    //pasirinkimas is failo ar ranka
    if (parinktis == 'R' || parinktis == 'r'){
    
        cout << "Iveskite studentu skaiciu: ";
        cin >> StudentuSkaicius;

        char atsakymas;
        cout << "Pasirinkite ar norite patys irasyti namu darbus (S) ar sugeneruoti (A)?";
        cin >> atsakymas;

        //Pasirinkimas sugeneruoti ar ivesti
        if (atsakymas == 'A')
        {
            for (int i = 0; i < StudentuSkaicius; i++) 
            {   
            cout << "Iveskite varda ir pavarde studento: ";
            cin >> Laikinas.Vardas >> Laikinas.Pavarde;

            Laikinas.Vidurkis = 0.0;
            Laikinas.Mediana = 0.0;

            NDSkaicius = 0;

            // Generuojame atsitiktinius namų darbų balus
            int minBalas = 1; 
            int maxBalas = 10; 
            int baluSkaicius;
            cout << "Iveskite kiek norite pazymiu sugeneruoti: "; 
            cin >> baluSkaicius;

            for (int j = 0; j < baluSkaicius; j++) 
            {
                int atsitiktinisBalas = rand() % (maxBalas - minBalas + 1) + minBalas;
                Laikinas.NamuDarbai.push_back(atsitiktinisBalas);
                NDSuma += atsitiktinisBalas;
                NDSkaicius++;
            }

            // Generuojame atsitiktinį egzamino balą
            Laikinas.Egzaminas = rand() % (maxBalas - minBalas + 1) + minBalas;

            // Skaiciuojame galutini vidurkis
            Laikinas.Vidurkis = GalutinisVidurkis(NDSuma, Laikinas.NamuDarbai, Laikinas.Egzaminas);

            //Mediana
            double TarpineMediana = Mediana(Laikinas.NamuDarbai);
            Laikinas.Mediana = GalutinisMediana(TarpineMediana, Laikinas.Egzaminas);

            grupe.push_back(Laikinas);
            Laikinas.NamuDarbai.clear();
            }
        }
        else 
        {
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

            // Skaiciuojame galutini vidurkis
            Laikinas.Vidurkis = GalutinisVidurkis(NDSuma, Laikinas.NamuDarbai, Laikinas.Egzaminas);

            //Mediana
            double TarpineMediana = Mediana(Laikinas.NamuDarbai);
            Laikinas.Mediana = GalutinisMediana(TarpineMediana, Laikinas.Egzaminas);

            grupe.push_back(Laikinas);
            Laikinas.NamuDarbai.clear();
            }
        }
    }
    else {
        string FileName;
        cout << "Enter the name of the input file: ";
        cin >> FileName;

    ifstream input(FileName); // Open the input file
    if (!input.is_open()) {
        cerr << "Nepavyko atidaryti failo." << endl;
        return 1;
    }
        // Read the header line (column names)
        string header;
        int n;
        if (getline(input, header)) {
            istringstream iss(header);
            vector<string> stulpeliai;
            string token;

            while (iss >> token) {
                stulpeliai.push_back(token);
            }

            n = stulpeliai.size()-3;
        } 
        else {
            cerr << "The file is empty." << endl;
        }

    // Read data from the file
    while (!input.eof()) {
        input >> Laikinas.Vardas >> Laikinas.Pavarde;
        for (int i = 0; i < n; i++) {
            int pazymys;
            input >> pazymys;
            Laikinas.NamuDarbai.push_back(pazymys);
        }
        input >> Laikinas.Egzaminas;

        Laikinas.Vidurkis = GalutinisVidurkis(NDSuma, Laikinas.NamuDarbai, Laikinas.Egzaminas);

        double TarpineMediana = Mediana(Laikinas.NamuDarbai);
        Laikinas.Mediana = GalutinisMediana(TarpineMediana, Laikinas.Egzaminas);

        grupe.push_back(Laikinas);
        Laikinas.NamuDarbai.clear();
    }
    input.close(); 
    }

    //Leidziame vartotojui pasirinkti norima skaiciavimo buda
    cout << "Noredami apskaiciuoti vidurki iveskite (V) ar mediana (M) ";
    cin >> Pasirinkimas;

    ofstream output("rezultatai.txt"); // Create a new output file
    if (!output.is_open()) {
        cerr << "Failed to create the output file." << endl;
        return 1;
    }

    //Palyginimas ir rusiavimas pagal pavarde ir varda
    sort(grupe.begin(), grupe.end(), palygintiPagalPavarde);
    stable_sort(grupe.begin(), grupe.end(), palygintiPagalVarda);

    output << fixed << setprecision(2);
    output << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << (Pasirinkimas == 'V' ? "Galutinis(Vid.)" : "Galutinis(Med.)") << setw(15) << "Egzaminas" ;
    output << setw(15) << "Pazymiai" << endl;
    output << "---------------------" << "---------------------" << "---------------------" << "---------------------" << endl;

    for (auto &a : grupe) {
        output << left << setw(15) << a.Vardas << setw(15) << a.Pavarde << setw(20) << (Pasirinkimas == 'V' ? a.Vidurkis : a.Mediana) << setw(15) << a.Egzaminas;
        for (auto &z: a.NamuDarbai)
        output << z <<" ";
        output << endl;
    }

    output.close(); // Close the output file

    cout << "Rezultatai paruošti faile";
    return 0;
}
