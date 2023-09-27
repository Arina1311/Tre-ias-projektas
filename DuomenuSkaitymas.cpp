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
    bool tinkamaParinktis = false; // Sukuriame kintamąjį, kuris žymės, ar parinktis tinkama

    while (!tinkamaParinktis) {
        cout << "Iveskite raide (R), jei norite rašyti duomenis savarankiškai ir (F) jeigu norite nuskaityti iš failo: ";
    try {
        cin >> parinktis;
        if (parinktis != 'R' && parinktis != 'r' && parinktis != 'F' && parinktis != 'f') {
            throw invalid_argument("Netinkama parinktis. Įveskite 'R' arba 'F'.");
        }
        tinkamaParinktis = true; // Jei pasiekėme šią eilutę, tai parinktis yra tinkama
    } catch (const invalid_argument &e) {
        cerr << e.what() << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Valome įvestį
    }
    }

    //pasirinkimas is failo ar ranka
    if (parinktis == 'R' || parinktis == 'r'){
        try {
        cout << "Iveskite studentu skaiciu: ";
        cin >> StudentuSkaicius;

            if (cin.fail() || StudentuSkaicius <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Netinkamas studentu skaicius. Prašome įvesti teigiama sveikąjį skaičių.");
            }
        }   
        catch (const invalid_argument &e) {
            cerr << e.what() << endl;
            return 1;
        }

        char atsakymas;
        cout << "Pasirinkite ar norite patys irasyti namu darbus (S) ar sugeneruoti (A)?";
        try {
        cin >> atsakymas;
            if (atsakymas != 'S' && atsakymas != 's' && atsakymas != 'A' && atsakymas != 'a') {
                throw invalid_argument("Netinkama parinktis. Pasirinkite 'S' arba 'A'.");
            }
        } 
        catch (const invalid_argument &e) {
            cerr << e.what() << endl;
            return 1; 
        }

        //Pasirinkimas sugeneruoti ar ivesti
        if (atsakymas == 'A' || atsakymas == 'a')
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

            while (true) {
            cout << "Iveskite namu darbo pazymi arba pastauskite ENTER du kartus, kad pabaigtumete ivedima: ";
            string NDpaz;
            getline(cin, NDpaz);

            try {
                if (NDpaz.empty()) {
                    if (NDSkaicius == 0) {
                        throw invalid_argument("Klaida. Reikalingas bent vienas namu darbas.");
                    }
                    break;
                }

                int pazymys = stoi(NDpaz); //konvertuojama i int skaiciu

                if (cin.fail()) {
                    throw invalid_argument("Klaida: Netinkama ivestis. Prašome ivesti skaiciu.");
                }

                Laikinas.NamuDarbai.push_back(pazymys);
                NDSuma += pazymys;
                NDSkaicius++;

            } catch (const invalid_argument &e) {
                cerr << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
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

    else{
    string FileName;
    cout << "Iveskite failo pavadinima: ";
    cin >> FileName;

    ifstream input(FileName); // Bandom atidaryti failą

    try {
        if (!input.is_open()) {
            throw runtime_error("Nepavyko atidaryti failo."); // Sukeliame išimtį, jei atidarymas nepavyksta
        }

        // Skaitome pirma eilute su pavadinimais
        string header;
        int n;

        try {
            if (getline(input, header)) {
                istringstream iss(header); //istringstream klasės objektas, srautas
                vector<string> stulpeliai;
                string pav;

                while (iss >> pav) {
                    stulpeliai.push_back(pav);
                }

                n = stulpeliai.size() - 3;
            } else {
                throw runtime_error("Failas yra tuščias.");
            }
        } catch (const runtime_error &e) {
            cerr << e.what() << endl;
            return 1; // Grąžiname klaidos kodą
        }

        // Skaitome likusius duomenys is failo
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
    catch (const runtime_error &e) {
        cerr << e.what() << endl; // Spausdiname klaidos pranešimą
        return 1; // Grąžiname klaidos kodą
    }
    }

    //Palyginimas ir rusiavimas pagal pavarde ir varda
    sort(grupe.begin(), grupe.end(), palygintiPagalPavarde);
    stable_sort(grupe.begin(), grupe.end(), palygintiPagalVarda);

    //Leidziame vartotojui pasirinkti norima skaiciavimo buda
    cout << "Noredami apskaiciuoti vidurki iveskite (V) ar mediana (M) ";
    cin >> Pasirinkimas;

   ofstream output("rezultatai.txt"); // Kuriame nauja faila

    try {
    if (!output.is_open()) {
        throw runtime_error("Nepavuko sukurti failo su rezultatais."); 
    }

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

    output.close(); // Uzdarome
    cout << "Rezultatai paruošti faile";
    } 
    
    catch (const runtime_error &e) {
    cerr << e.what() << endl; 
    return 1; 
    }
    return 0;
}
