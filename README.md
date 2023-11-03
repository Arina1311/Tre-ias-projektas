# Testavimų aprašymas

**Testavimo sistemos parametrai:** <br />
**CPU:** Apple M2, 8 Core CPU <br />
**RAM:** 8 Gb <br />
**HDD:** 256Gb SSD <br />

## std::vector 3 strategijų testavimo laikų aprašymas:

Testavimas atliekamas su **std::vector**,  lentelė sudaryta pagal penkis sugeneruotus failus ir jų vidurkius: studentai_1000.txt, studentai_10000.txt, studentai_100000.txt, studentai_1000000.txt, studentai_10000000.txt.

| Testavimas/ Failas         |      1000     |     10000    |    100000    |    1000000   |  10000000  |
|----------------------------|:-------------:|:------------:|:------------:|:------------:|:----------:|
| 1 strategija          | 0.00193 s. | 0.01168 s. |  0.08132 s. |  0.57863 s.  |  4.97047 s. |
| 2 strategija           | 0.05707 s. | 2.84885 s. |  6.06195 s. |  32.65493 s.  |  54.76543 s. |
| 3 strategija | 0.00137 s. | 0.00808 s. | 0.08069 s. |  0.57624 s. | 4.09822 s. |

**Greičiausiai veikianti strategija:** Su didesniu duomenų kiekiu **3 strategija**, patobulinta pagal 1 strategiją, veikia sparčiau, negu 1 ir 2, 2 strategija veikia žymiai lėčiau. Galima padaryti išvadą, kad **3 strategija**, veikianti pagal principą išskaidyti duomenys į du atskirus vektorius su std::partition ir std::copy funkcijomis yra greitesnė ir efektivesne std::vector atveju.

## std::list 3 strategijų testavimo laikų aprašymas:

Testavimas atliekamas su **std::list**,  lentelė sudaryta pagal penkis sugeneruotus failus ir jų vidurkius: studentai_1000.txt, studentai_10000.txt, studentai_100000.txt, studentai_1000000.txt, studentai_10000000.txt.

| Testavimas/ Failas         |      1000     |     10000    |    100000    |    1000000   |  10000000  |
|----------------------------|:-------------:|:------------:|:------------:|:------------:|:----------:|
| 1 strategija          | 0.00222 s. | 0.01961 s. |  0.02517 s. |  0.60923 s.  |  20.45866 s. |
| 2 strategija           | 0.00115 s. | 0.01450 s. |  0.08881 s. |  0.58310 s.  |  5.01998 s. |
| 3 strategija | 0.00213 s. | 0.01776 s. | 0.10514 s. |  0.73475 s. | 8.70372 s. |

**Greičiausiai veikianti strategija:** Su didesniu duomenų kiekiu *2 strategija** veikia sparčiau, negu 1 ir 3, 1 strategija veikia žymiai lėčiau. Galima padaryti išvadą, kad **2 strategija**, veikianti pagal principą pašalinti duomenys iš pradinio sąrašo, kurie netenkina sąlygos ir nukopijuoti į naują sąrašą yra efektivesnis būdas std::list atveju.


## **Bendra išvada:** <br />
Galime daryti **išvada**, kad teisingos strategijos parinkimas ir jos efektyvumas priklauso nuo konteinerio, iš gautų testų matinee, kad pašalinimas ir kopijavimas į vieną konteinerį veikia greičiau std::list atveju, o duomenų paskirstymas į dvį grupes veiai efektyviau su std::vector.
