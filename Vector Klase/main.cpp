#include <iostream>
#include <fstream>
#include <numeric>
#include <cstdlib> 
#include <random>
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

    ofstream matavimai("matavimai3.txt", std::ios::app);
    matavimai << fixed;

    int testuSkaicius = 5;
    double M1[testuSkaicius], M2[testuSkaicius],  M3[testuSkaicius],  M4[testuSkaicius],  M5[testuSkaicius],  M6[testuSkaicius];

    cout << "Noredami apskaiciuoti vidurki iveskite (V) ar mediana (M) ";
    cin >> Pasirinkimas;
   
    cout << "Ar norite sugeneruotu atsitiktinius studentu duomenys (T/N): ";
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
        chrono::duration<double> duration = end - start; //Chrono bibliotekos tipas, skirtas saugoti laiko trukmę su slankiojo kablelio skaičiais
       
        // Atspausdiname laiko trukmę
        cout << "- Failo su "<< StudSkaicius <<" duomenimis kurimo trukmė: " << setprecision(10) << duration.count() << endl; //duration.count() - grazina laika sekundemis
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
            string vard, pav;
            cout << "Iveskite varda ir pavarde studento: ";
            cin >> vard >> pav;
            
            Laikinas.setVardas(vard);
            Laikinas.setPavarde(pav);

            // Generuojame atsitiktinius namų darbų balus
            int minBalas = 1;
            int maxBalas = 10;
            int baluSkaicius;
            cout << "Iveskite kiek norite pazymiu sugeneruoti: ";
            cin >> baluSkaicius;

            mt19937 mt(1729);  
            uniform_int_distribution<int> dist(minBalas, maxBalas);

            for (int j = 0; j < baluSkaicius; j++) {
                int atsitiktinisBalas = dist(mt);
                Laikinas.NDPrideti(atsitiktinisBalas);
            }

            // Generuojame atsitiktinį egzamino balą
            int egzaminoBalas = dist(mt);
            Laikinas.setEgzaminas(egzaminoBalas); 

            vector<int> namu = Laikinas.namuDarbai();
            double suma = accumulate(namu.begin(),namu.end(),0);

            Laikinas.setPazymys(GalutinisPazymis(suma, namu, Laikinas.egzaminas(), Pasirinkimas)) ;

            grupe.push_back(Laikinas);
            Laikinas.namuDarbai().clear();
            }
        }

        else {
            for (int i = 0; i < StudentuSkaicius; i++) 
            {
            cout << "Iveskite varda ir pavarde studento: ";
            string pav, vard;
            cin >> vard >> pav;
            Laikinas.setVardas(vard);
            Laikinas.setPavarde(pav);
            cin.ignore();

            while (true) {
            cout << "Iveskite namu darbo pazymi arba pastauskite ENTER du kartus, kad pabaigtumete ivedima: ";
            string NDpaz;
            getline(cin, NDpaz);

            try {
                if (NDpaz.empty()) {
                    if (Laikinas.namuDarbai().size() == 0) {
                        throw invalid_argument("Klaida. Reikalingas bent vienas namu darbas.");
                    }
                    break;
                }

                if (cin.fail()) {
                    throw invalid_argument("Klaida: Netinkama ivestis. Prašome ivesti skaiciu.");
                }

                int pazymys = stoi(NDpaz); //konvertuojama i int skaiciu

                Laikinas.NDPrideti(pazymys);

            } catch (const invalid_argument &e) {
                cerr << e.what() << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

            cout << "Iveskite egzamino pazymi: ";
            int egz;
            cin >> egz;
            Laikinas.setEgzaminas(egz);

            vector<int> namu = Laikinas.namuDarbai();
            double suma = accumulate(namu.begin(),namu.end(),0);
            
            Laikinas.setPazymys(GalutinisPazymis(suma, namu, Laikinas.egzaminas(), Pasirinkimas));
            grupe.push_back(Laikinas);
            Laikinas.namuDarbai().clear();
            }
        }
    }

    else{

    string FileName;
    cout << "Iveskite failo pavadinima: ";
    cin >> FileName;

        for (int t=0; t < testuSkaicius; t++){
        auto startNuskaitymas = chrono::high_resolution_clock::now();
        
        grupe = SkaitytiDuomenisIsFailo(FileName, Pasirinkimas);
        
        auto endNuskaitymas = chrono::high_resolution_clock::now();
        chrono::duration<double> durationNuskaitymas = endNuskaitymas - startNuskaitymas;
        M2[t] = durationNuskaitymas.count();
        }

    double testas2 = vidutiniai(M2,testuSkaicius);
    matavimai << "- Failo su "<< StudSkaicius <<" duomenimis nuskaitymo trukme: " << setprecision(10) << testas2 << endl;
    }

    //Palyginimas ir rusiavimas, testavimas
        int kriterijus;
        cout << "Irasykite numeri pagal ka norite rusiuoti (1 - Vardas, 2 - Pavarde, 3 - Pazymys): ";
        cin >> kriterijus;

        for (int t=0; t < testuSkaicius; t++){
        auto startSort = chrono::high_resolution_clock::now();
        
            switch (kriterijus)
            {
            case 1:
                sort(grupe.begin(), grupe.end(), palygintiPagalVarda);
                break;
            case 2:
                sort(grupe.begin(), grupe.end(), palygintiPagalPavarde);
                break;
            case 3:
                sort(grupe.begin(), grupe.end(), palygintiPagalPazymi);
                break;
            default:
            cerr << "Neteisingas rusiavimo kriterijus: " << kriterijus << endl;
            return 1;
            }

        auto endSort = chrono::high_resolution_clock::now();
        chrono::duration<double> durationSort = endSort - startSort;
        M3[t] = durationSort.count();
        }

    double testas3 = vidutiniai(M3,testuSkaicius);
    matavimai << "- Failo su "<< StudSkaicius <<" duomenimis, studentu rusiavimo trukme, su funkcija sort(): " << setprecision(10)<< testas3 << endl;

    vector<Studentas> vargsiukai;
    vector<Studentas> kietuoliai;

    cout << "Ar norite paskirstyti studentus pagal pazymius? (T/N): ";
    char ats;
    cin >> ats;

    if (ats == 'T' || ats == 't'){
    // Rusiavimo testavimas
    //3 strategija
    vector<Studentas> vargsiukai;
    vector<Studentas> kietuoliai;

    auto startRusiavimas = chrono::high_resolution_clock::now();

    // Naudojame std::partition, kad suskirstytume studentus pagal sąlyga
    auto partitionPoint = partition(grupe.begin(), grupe.end(), isVargsiukas);

    // Kopijuojame vargsiukus į atitinkamą vektorių
    copy(grupe.begin(), partitionPoint, back_inserter(vargsiukai));

    // Kopijuojame kietuolius į atitinkamą vektorių
    copy(partitionPoint, grupe.end(), back_inserter(kietuoliai));

    auto endRusiavimas = chrono::high_resolution_clock::now();
    chrono::duration<double> durationRusiavimas = endRusiavimas - startRusiavimas;
    float M43 = durationRusiavimas.count();

    matavimai << "- Failo su " << StudSkaicius << " duomenimis, studentų dalijimo į dvi grupes trukmė: " << setprecision(10) << M43 << endl;

    for (int t=0; t < testuSkaicius; t++){
        auto startIsvedimasVarg = chrono::high_resolution_clock::now();
        RasymasIRezultatuFaila("vargsiukai.txt", Pasirinkimas, vargsiukai);
        
        auto endIsvedimasVarg = chrono::high_resolution_clock::now();
        chrono::duration<double> durationIsvedimasVarg = endIsvedimasVarg - startIsvedimasVarg;
        M5[t] = durationIsvedimasVarg.count();
        }

        double testas53 = vidutiniai(M5,testuSkaicius);
        matavimai <<"- Failo su "<< StudSkaicius <<" duomenimis, isvedimo i vargsiuku faila trukme: " << setprecision(10) << testas53 << endl;

        for (int t=0; t < testuSkaicius; t++){
            auto startIsvedimasKiet = chrono::high_resolution_clock::now();
            RasymasIRezultatuFaila("kietuoliai.txt", Pasirinkimas, kietuoliai);

            auto endIsvedimasKiet = chrono::high_resolution_clock::now();
            chrono::duration<double> durationIsvedimasKiet = endIsvedimasKiet - startIsvedimasKiet;
            M6[t] = durationIsvedimasKiet.count();
            }

        double testas63 = vidutiniai(M6,testuSkaicius);
        matavimai << "- Failo su "<< StudSkaicius <<" duomenimis, isvedimo i ketuoliu faila trukme: " << setprecision(10) << testas63 << endl;
   }

    else {
    if (parinktis == 'R' || parinktis == 'r')
        RasymasIRezultatuFailaSav("rezultatai1.txt", Pasirinkimas, grupe);
        else 
        RasymasIRezultatuFaila("rezultatai1.txt", Pasirinkimas, grupe);
    }

    double FinalinisLaikas = finalinis(M2,M3,M4,M5,M6,testuSkaicius);
    matavimai <<endl<< "Vidutinis " << StudSkaicius <<" irasu testo laikas, atlikus "<< testuSkaicius <<" testus: "<<FinalinisLaikas<< endl;
    matavimai << "-------------------------------------------------------------------" << endl << endl;
    matavimai.close();

    cout<<"Matavimai ir failai paruosti"<<endl;

    return 0;
}
