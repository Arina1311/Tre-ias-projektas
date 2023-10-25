# Pirmas Projektas
**Testavimų aprašymas:**

Testavimas atliekamas su **std::vector**, lentelė sudaryta pagal penkis sugeneruotus failus: studentai_1000.txt, studentai_10000.txt, studentai_100000.txt, studentai_1000000.txt, studentai_10000000.txt.

| Testavimas/ Failas         |      1000     |     10000    |    100000    |    1000000   |  10000000  |
|----------------------------|:-------------:|:------------:|:------------:|:------------:|:----------:|
| Failo nuskaitymas          | 0.00787 s. | 0.03766 s. |  0.32828 s. |  3.22125 s.  |  34.94401 s. |
| Rūšiavimas sort()          | 0.00127 s. | 0.01023 s. |  0.06100 s. |  0.64080 s.  |  7.30717 s. |
| Padalijimas į dvi grupes   | 0.00165 s. | 0.01902 s. | 0.08262 s. |  0.61509 s. | 5.77035 s. |
| Rašymas į vargščiukų failą | 0.00228 s. | 0.01075 s. | 0.06806 s. |  0.68643 s. | 7.94382 s. |
| Rašymas į kietuolių failą  | 0.00224 s. |  0.00989 s. |  0.09472 s.  |  0.95830 s. | 11.70412 s. |
| Bendras                    |  0.01532 s. |  0.08756 s. |  0.63471 s.  |  6.12189 s.  | 67.66949 s. |

Testavimas atliekamas su **std::list**, lentelė sudaryta pagal tuos pačius penkis sugeneruotus failus: studentai_1000.txt, studentai_10000.txt, studentai_100000.txt, studentai_1000000.txt, studentai_10000000.txt.

| Testavimas/ Failas         |      1000     |     10000    |    100000    |    1000000   |  10000000  |
|----------------------------|:-------------:|:------------:|:------------:|:------------:|:----------:|
| Failo nuskaitymas          | 0.00739 s. | 0.03549 s. |  0.30431 s. |  3.31936 s.  |  33.58994 s. |
| Rūšiavimas sort()          | 0.00163 s. | 0.00982 s. |  0.05976 s. |  0.69089 s.  |  7.78976 s. |
| Padalijimas į dvi grupes   | 0.00234 s. | 0.01712 s. | 0.09135 s. |  0.61253 s. | 7.09117 s. |
| Rašymas į vargščiukų failą | 0.00296 s. | 0.01018 s. | 0.06704 s. |  0.67556 s. | 9.02433 s. |
| Rašymas į kietuolių failą  | 0.00285 s. |  0.00977 s. |  0.09464 s.  |  0.99026 s. | 12.67260 s. |
| Bendras                    |  0.01719 s. |  0.08240 s. |  0.61712 s.  |  6.28862 s.  | 70.16782 s. |

**Atskirų programos funkcijų veikimo laikas su std::vector ir std::list:**
- Studentų rūšiavimas į dvi grupes/kategorijas: nežymiai greičiau programa paskirsto į dvi grupes duomenis su **std::vector** duomenų tipu,  kai turime didelį duomenų kiekį.
- Duomenų įrašymas į failus: nežymiai greičiau programa įrašo duomenis į failus grupes su **std::vector** duomenų tipu, kai turime didelį duomenų kiekį.

Iš lentelių matome, kad std::vector ir std::list testavimų laikai sugeneruotų failų yra panašūs, su 10000 ir 100000 duomenų kiekiu std::list dirba greičiau, o std::vector dirba greičiau su 1000, 1000000 ir 10000000. 

**Bendra išvada:**
Galime daryti **išvada**, kad nežymiai **greičiau** dirba **std::vector**, nes didesnius duomenų kiekius programa apdoroja greičiau. Didžiausias skirtumas (sekundėmis) matomas kai programa apdoroja 10000000 duomenų failą, skirtumas yra ~ 2.5 sek. 

**Testavimo sistemos parametrai:**
**CPU:** Apple M2, 8 Core CPU
**RAM:** 8 Gb
**HDD:** 256Gb SSD



