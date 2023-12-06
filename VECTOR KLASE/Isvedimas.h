#ifndef ISVEDIMAS_H
#define ISVEDIMAS_H

#include <list>
#include "duomenys.h"
#include <string>

void RasymasIRezultatuFaila(const string& failoPavadinimas, char Pasirinkimas, const vector<Studentas>& grupe);
void KurimasDuomenu(int &Skaicius, int &Kiekis);
void RasymasIEkrana (char Pasirinkimas, const vector<Studentas>& grupe);
#endif