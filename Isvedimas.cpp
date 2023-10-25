#include "Isvedimas.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <random>
#include <chrono>

void RasymasIRezultatuFaila(const string& failoPavadinimas, char Pasirinkimas, const list<Studentas>& grupe) {
    ofstream output(failoPavadinimas); // Kuriame nauja faila

    try {
        if (!output.is_open()) {
            throw runtime_error("Nepavyko sukurti failo su rezultatais.");
        }

        output << fixed << setprecision(2);
        output << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << (Pasirinkimas == 'V' ? "Galutinis(Vid.)" : "Galutinis(Med.)") <<endl;
        output << "---------------------" << "---------------------" << "---------------------" << endl;

        for (const auto& studentas : grupe) {
            output << left << setw(15) << studentas.Vardas << setw(15) << studentas.Pavarde << setw(20) << studentas.Pazymys <<endl;
        }

        output.close(); // Uždarome
    } catch (const runtime_error& e) {
        cerr << e.what() << endl;
    } 
}


void KurimasDuomenu(int &StudSkaicius, int &NDk) {

    string fileName = "studentai_" + to_string(StudSkaicius) + ".txt";
    ofstream outputFile(fileName);

    if (!outputFile) {
        cerr << "Nepavyko atidaryti failo: " << fileName << endl;
        terminate();
    }

    // antrastes
    outputFile << left << setw(20) << "Vardas" << right << setw(20) << "Pavarde";
    for (int i = 1; i <= NDk; i++) {
        outputFile << right << setw(10) << "ND" + to_string(i);
    }
    outputFile << right << setw(10) << "Egz." << endl;
    
    mt19937 mt(1729);  
    uniform_int_distribution<int> dist(1, 10);

    for (int j = 1; j <= StudSkaicius; j++) {
        outputFile << left << setw(20) << "Vardas" + to_string(j) << right << setw(20) << "Pavarde" + to_string(j);

        for (int k = 0; k < NDk; k++) {
            int atsitiktinisBalas = dist(mt);
            outputFile << right << setw(10) << atsitiktinisBalas;
        }

        int atsitiktinisEgzaminas = dist(mt); 
        outputFile << right << setw(10) << atsitiktinisEgzaminas;

        if (j < StudSkaicius) {
            outputFile << endl; // Tik jei tai ne paskutinis studentas, pridedame naują eilutę
        }
    }
    outputFile.close();
}


