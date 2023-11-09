#ifndef ISVEDIMAS_H
#define ISVEDIMAS_H

#include <list>
#include "duomenys.h"
#include <string>

void RasymasIRezultatuFaila(const string& failoPavadinimas, char Pasirinkimas, const list<Studentas>& grupe);
void KurimasDuomenu(int &Skaicius, int &Kiekis);
void RasymasIRezultatuFailaSav(const string& failoPavadinimas, char Pasirinkimas, const list<Studentas>& grupe);
#endif