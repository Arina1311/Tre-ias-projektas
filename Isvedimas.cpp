#include "Isvedimas.h"
#include <iostream>
#include <fstream>
#include <iomanip>

void RasymasIRezultatuFaila(const string& failoPavadinimas, char Pasirinkimas, const vector<Studentas>& grupe) {
    ofstream output(failoPavadinimas); // Kuriame nauja faila

    try {
        if (!output.is_open()) {
            throw runtime_error("Nepavyko sukurti failo su rezultatais.");
        }

        output << fixed << setprecision(2);
        output << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(20) << (Pasirinkimas == 'V' ? "Galutinis(Vid.)" : "Galutinis(Med.)") <<endl;
        output << "---------------------" << "---------------------" << "---------------------" << endl;

        for (const auto& studentas : grupe) {
            output << left << setw(15) << studentas.Vardas << setw(15) << studentas.Pavarde << setw(20) << (Pasirinkimas == 'V' ? studentas.Vidurkis : studentas.Mediana) <<endl;
        }

        output.close(); // Uždarome
        cout << "Rezultatai paruošti faile" << endl;
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
    outputFile << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    for (int i = 1; i <= NDk; i++) {
        outputFile << setw(7) << "ND" + to_string(i);
    }
     outputFile << setw(7) << "Egz." << endl;

    for (int j = 1; j <= StudSkaicius; j++) {
        outputFile <<left << setw(20) << "Vardas"+ to_string(j)<<setw(20)<< "Pavarde" + to_string(j);

        for (int k = 0; k < NDk; k++) {
             outputFile << setw(7) << rand() % 10 + 1;
        }
        outputFile << setw(7) << rand() % 10 + 1 << endl;
    }
    outputFile.close();
    cout << "Sugeneruotas " << StudSkaicius << " studentu duomenu failas " << fileName << endl;
}

