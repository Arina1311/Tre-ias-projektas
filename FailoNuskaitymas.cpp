#include "FailoNuskaitymas.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <numeric> 
#include <iostream>

vector<Studentas> SkaitytiDuomenisIsFailo(const string& fileName) {
    vector<Studentas> grupe;
    ifstream input(fileName); 

    try {
        if (!input.is_open()) {
            throw runtime_error("Nepavyko atidaryti failo."); 
        }
        string header;
        int n;

        try {
            if (getline(input, header)) {  //paimame eilute bandome ja irasyti i header
                istringstream iss(header); //padarome is header srauta
                vector<string> stulpeliai; 
                string pav; //saugomas kiekvienas išskirtas žodis iš header

                while (iss >> pav) {   //nuskaito kiekvieną žodį iš header, naudojant iss srautą
                    stulpeliai.push_back(pav);
                }

                n = stulpeliai.size() - 3;
            } else {
                throw runtime_error("Failas yra tuščias.");
            }

        } catch (const runtime_error &e) {
            cerr << e.what() << endl; 
            terminate();
        }

        while (!input.eof()) { //eof() funkcija tikrina, ar esame failo pabaigoje
            Studentas Laikinas;
            input >> Laikinas.Vardas >> Laikinas.Pavarde;
            for (int i = 0; i < n; i++) {
                int pazymys;
                input >> pazymys;
                Laikinas.NamuDarbai.push_back(pazymys);
            }
            input >> Laikinas.Egzaminas;

            int Nsuma = accumulate(Laikinas.NamuDarbai.begin(), Laikinas.NamuDarbai.end(), 0);

            Laikinas.Vidurkis = GalutinisVidurkis(Nsuma, Laikinas.NamuDarbai, Laikinas.Egzaminas);

            double TarpineMediana = Mediana(Laikinas.NamuDarbai);
            Laikinas.Mediana = GalutinisMediana(TarpineMediana, Laikinas.Egzaminas);

            grupe.push_back(Laikinas);
            Laikinas.NamuDarbai.clear();
        }
        input.close();
    }
     catch (const runtime_error &e) {
        cerr << e.what() << endl;
       terminate(); 
    }
    return grupe;
}
