#include "FailoNuskaitymas.h"
#include "duomenys.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <numeric> 
#include <iostream>

vector<Studentas> SkaitytiDuomenisIsFailo(const string& fileName, char Pasirinkimas) {
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
            string vard, pav;
            input >> vard;
            Laikinas.setVardas(vard);
            input >> pav;
            Laikinas.setPavarde(pav);

            for (int i = 0; i < n; i++) {
                int pazymys;
                input >> pazymys;

                Laikinas.NDPrideti(pazymys);
            }

            
            int egz;
            input >> egz;
            Laikinas.setEgzaminas(egz);

            vector <int> namu = Laikinas.namuDarbai();
            int suma = accumulate(namu.begin(), namu.end(), 0);
        
            Laikinas.setPazymys(GalutinisPazymis(suma, namu, Laikinas.egzaminas(), Pasirinkimas));

            grupe.push_back(Laikinas);
            Laikinas.namuDarbai().clear();
        }
        input.close();
    }
     catch (const runtime_error &e) {
        cerr << e.what() << endl;
       terminate(); 
    }
    return grupe;
}
