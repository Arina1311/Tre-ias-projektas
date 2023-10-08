#include <iostream>
#include <fstream>
#include <numeric>
#include <cstdlib> 
#include "duomenys.h"
#include "FailoNuskaitymas.h"
#include "Isvedimas.h"

int main() {
    Studentas Laikinas; 
    vector<Studentas> grupe;
    int StudentuSkaicius;
    char Pasirinkimas;
    int StudSkaicius, NDk;

    char parinktis, generavimas;
    bool tinkamaParinktis = false; // Sukuriame kintamąjį, kuris žymės, ar parinktis tinkama

    ofstream matavimai("matavimai.txt", std::ios::app);
   
    cout << "Ar norite sugeneruoti atsitiktinius studentu duomenys (T/N): ";
    cin >> generavimas;
    if (generavimas == 'T' || generavimas == 't') {
        cout << "Iveskite kiek duomenu norite sugeneruoti: ";
        cin >> StudSkaicius;
        cout << "Iveskite kiek ND norite sugeneruoti: ";
        cin >> NDk;

        matavimai << StudSkaicius << " duomenu failas:" << endl;
        auto start = chrono::high_resolution_clock::now();
        KurimasDuomenu(StudSkaicius, NDk);

        auto end = std::chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;

        // Atspausdiname laiko trukmę
        matavimai << "- Failo su "<< StudSkaicius <<" duomenimis kurimo trukmė: " << duration.count() << endl;
        }

    while (!tinkamaParinktis) {
        cout << "Iveskite raide (R), jei norite rašyti duomenis savarankiškai, (F) jeigu norite nuskaityti iš failo: ";
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
            }

            // Generuojame atsitiktinį egzamino balą
            Laikinas.Egzaminas = rand() % (maxBalas - minBalas + 1) + minBalas;

            // Skaiciuojame galutini vidurkis
            Laikinas.Vidurkis = GalutinisVidurkis(accumulate(Laikinas.NamuDarbai.begin(), Laikinas.NamuDarbai.end(), 0), Laikinas.NamuDarbai, Laikinas.Egzaminas);

            //Mediana
            double TarpineMediana = Mediana(Laikinas.NamuDarbai);
            Laikinas.Mediana = GalutinisMediana(TarpineMediana, Laikinas.Egzaminas);

            grupe.push_back(Laikinas);
            Laikinas.NamuDarbai.clear();
            }
        }

        else {
            for (int i = 0; i < StudentuSkaicius; i++) 
            {
            cout << "Iveskite varda ir pavarde studento: ";
            cin >> Laikinas.Vardas >> Laikinas.Pavarde;

            Laikinas.Vidurkis = 0.0;
            Laikinas.Mediana = 0.0;

            cin.ignore();

            while (true) {
            cout << "Iveskite namu darbo pazymi arba pastauskite ENTER du kartus, kad pabaigtumete ivedima: ";
            string NDpaz;
            getline(cin, NDpaz);

            try {
                if (NDpaz.empty()) {
                    if (Laikinas.NamuDarbai.size() == 0) {
                        throw invalid_argument("Klaida. Reikalingas bent vienas namu darbas.");
                    }
                    break;
                }

                if (cin.fail()) {
                    throw invalid_argument("Klaida: Netinkama ivestis. Prašome ivesti skaiciu.");
                }

                int pazymys = stoi(NDpaz); //konvertuojama i int skaiciu

                Laikinas.NamuDarbai.push_back(pazymys);

            } catch (const invalid_argument &e) {
                cerr << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

            cout << "Iveskite egzamino pazymi: ";
            cin >> Laikinas.Egzaminas;

            // Skaiciuojame galutini vidurkis
            Laikinas.Vidurkis = GalutinisVidurkis(accumulate(Laikinas.NamuDarbai.begin(), Laikinas.NamuDarbai.end(), 0), Laikinas.NamuDarbai, Laikinas.Egzaminas);

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

    auto startNuskaitymas = chrono::high_resolution_clock::now();
    grupe = SkaitytiDuomenisIsFailo(FileName);
    auto endNuskaitymas = chrono::high_resolution_clock::now();
    chrono::duration<double> durationNuskaitymas = endNuskaitymas - startNuskaitymas;
    matavimai << "- Failo su "<< StudSkaicius <<" duomenimis nuskaitymo trukme: " << durationNuskaitymas.count() << endl;
    }

    //Palyginimas ir rusiavimas pagal pavarde ir varda, testavimas
    auto startSort = chrono::high_resolution_clock::now();
    sort(grupe.begin(), grupe.end(), palygintiPagalPavarde);
    stable_sort(grupe.begin(), grupe.end(), palygintiPagalVarda);
    auto endSort = chrono::high_resolution_clock::now();
    chrono::duration<double> durationSort = endSort - startSort;
    matavimai << "- Failo su "<< StudSkaicius <<" duomenimis, studentu rusiavimo trukme, su funkcija sort(): " << durationSort.count() << endl;


    //Leidziame vartotojui pasirinkti norima skaiciavimo buda
    cout << "Noredami apskaiciuoti vidurki iveskite (V) ar mediana (M) ";
    cin >> Pasirinkimas;

    vector<Studentas> vargsiukai;
    vector<Studentas> kietuoliai;

    cout << "Ar norite paskirstyti studentus pagal pazymius? (T/N): ";
    char ats;
    cin >> ats;

    if (ats == 'T' || ats == 't'){
    // Rusiavimo testavimas
    auto startRusiavimas = chrono::high_resolution_clock::now();

    for (const Studentas &studentas : grupe) {
    if (studentas.Vidurkis < 5.0) {
        vargsiukai.push_back(studentas); 
    } else {
        kietuoliai.push_back(studentas); 
    }
    }

    auto endRusiavimas = chrono::high_resolution_clock::now();
    chrono::duration<double> durationRusiavimas = endRusiavimas - startRusiavimas;
    matavimai << "- Failo su "<< StudSkaicius <<" duomenimis, studentu dalijimo i dvi grupes trukme: " << durationRusiavimas.count() << endl;

    // Pasiskirstymo testavimas
    auto startIsvedimasVarg = chrono::high_resolution_clock::now();
    RasymasIRezultatuFaila("vargsiukai.txt", Pasirinkimas, vargsiukai);
    auto endIsvedimasVarg = chrono::high_resolution_clock::now();
    chrono::duration<double> durationIsvedimasVarg = endIsvedimasVarg - startIsvedimasVarg;
    matavimai <<"- Failo su "<< StudSkaicius <<" duomenimis, isvedimo i vargsiuku faila trukme: " << durationIsvedimasVarg.count() << endl;

    auto startIsvedimasKiet = chrono::high_resolution_clock::now();
    RasymasIRezultatuFaila("kietuoliai.txt", Pasirinkimas, kietuoliai);
    auto endIsvedimasKiet = chrono::high_resolution_clock::now();
    chrono::duration<double> durationIsvedimasKiet = endIsvedimasKiet - startIsvedimasKiet;
    matavimai << "- Failo su "<< StudSkaicius <<" duomenimis, isvedimo i ketuoliu faila trukme: " << durationIsvedimasKiet.count() << endl;
    }

    else {
    RasymasIRezultatuFaila("rezultatai1.txt", Pasirinkimas, grupe);
    }

    matavimai << "-------------------------------------------------------------------" << endl << endl;
    matavimai.close();

    return 0;
}
