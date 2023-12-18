#include <iostream>
#include <fstream>
#include <numeric>
#include <cstdlib> 
#include <random>
#include "duomenys.h"
#include "FailoNuskaitymas.h"
#include "Isvedimas.h"

int main() {
    //Studento klases objekto kurimas
    Studentas Studentas1;
    Studentas1.setvardas("Arina");
    Studentas1.setpavarde("Tichonovskaja");
    Studentas1.NDPrideti(10);
    Studentas1.NDPrideti(9);
    Studentas1.NDPrideti(8);
    Studentas1.NDPrideti(7);
    Studentas1.NDPrideti(8);
    Studentas1.setEgzaminas(10);

    Studentas Studentas2 = Studentas1;

    cout << "------------------------------------------------------" << endl;
    cout << endl;
    cout << "Informacija Studentas1: " << endl;
    Studentas1.informacija();
    cout << "------------------------------------------------------" << endl;
     cout << endl;
    cout << "Informacija Studentas2: " << endl;
    cout<< Studentas2 <<endl;
    cout << "------------------------------------------------------" << endl;

    //Parodome, kad Zmogus klases objektas negali but sukurtas
    //Zmogus Zmogus1("Arina", "Tichonovskaja");

    Studentas Laikinas; 
    vector<Studentas> grupe;
    int StudentuSkaicius;
    char Pasirinkimas;
    int StudSkaicius, NDk;

    char parinktis, generavimas;
    bool tinkamaParinktis = false; // Sukuriame kintamąjį, kuris žymės, ar parinktis tinkama

    ofstream matavimai("matavimai.txt");
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

            for (int i = 0; i < StudentuSkaicius; i++) 
            {   
                Studentas Laikinas;
                cin>> Laikinas;
                grupe.push_back(Laikinas);
                Laikinas.namuDarbai().clear();
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

    cout << "Ar norite isvesti duomenys i faila? (T/N): ";
    char ats2;
    cin >> ats2;
    cout << "Ar norite paskirstyti studentus pagal pazymius? (T/N): ";
    char ats;
    cin >> ats;
    
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

    if (ats2 == 'T' || ats2 == 't'){
        if (ats == 'T' || ats == 't') {
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
            RasymasIRezultatuFaila("rezultatai1.txt", Pasirinkimas, grupe);
        }
    } 
    else {
        if (ats == 'T' || ats == 't') {
            cout<<endl<<endl;
            cout<<"Vargsiukai"<<endl;
            RasymasIEkrana(Pasirinkimas, vargsiukai);
            cout<<endl<<endl;
            cout<<"Kietuoliai"<<endl;
            RasymasIEkrana(Pasirinkimas, kietuoliai);
        }
        
        else {
            cout<<endl<<endl;
            RasymasIEkrana(Pasirinkimas, grupe);
        }
    }

    double FinalinisLaikas = finalinis(M2,M3,M4,M5,M6,testuSkaicius);
    matavimai <<endl<< "Vidutinis " << StudSkaicius <<" irasu testo laikas, atlikus "<< testuSkaicius <<" testus: "<<FinalinisLaikas<< endl;
    matavimai << "-------------------------------------------------------------------" << endl << endl;
    matavimai.close();

    cout<<"Matavimai ir failai paruosti"<<endl;

    return 0;
}
