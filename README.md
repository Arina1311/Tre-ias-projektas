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

## **Nuorodą į nuotraukas su failų atminties naudojimu:** <br />
https://drive.google.com/drive/folders/1b8IdE8_pNSONs7pBUKtDEgICM11XkCUZ?usp=share_link

## **Išvada apie atminties naudojimą:** <br />
**std::vector** atveju greičiau veikia 1 ir 3 strategijos, tačiau jos sunaudoja daugiau atminties ~ 5,5 GB programos veikimo metu, atliekant paskirstymą į grupes, negu 2 strategija. Taip pat programa pradeda naudoti atmintį kai dirba su dideliais failais, kurie turi 1000000 ir 10000000 duomenų. **std::list** atveju atminties naudojimas yra panašus visų strategijų atveju, dirbant su dideliais duomenų kiekiais programa sunaudoja ~ 6 GB veikimo metu, nepriklausomai nuo to, kad greičiau programa veikia su 2 strategija.

# Naudojimo instrukcija: <br />
## Programos diegimo instrukcija:
- Iš GitHub repozitorijos parsisiųsti aplankalą **LIST_DIEGIMAS* ar **VECTOR_DIEGIMAS*, priklausomai nuo to, su kokiu konteineriu std::list arba std::vector norite dirbti;
- Aplankalas turi visus reikalingus failus, peržiūrėti programos kodą galima atidarius aplankalą **src*, kur surašyti failai su plėtiniu **cpp**, ir aplankalą **include*, kuriame rasite **h** failus;
- Paleisti programą reikalingas aplankalas **Debug*, kuriame rasite **exec** failą, kurį paleidus pasileis programa;
- Reikalingus tekdtinius failus reikia patalpinti toje vietoje, kur programa pati sukuria failus (tai reikia patikrinti).

## Programos paleidimo instrukcija:
****Programos tikslas:*** Programa apskaičiuoja studentų galutinius pažymius iš **n** skaičiaus namų darbų ir egzamino pažymio, pagal formulę **Galutinis pažymys = 0,6 * egzaminas + 0,4 * (namų darbų vidurkis)** pagal jūsų parinktą parametrą, vidurkį arba medianą, gali generuoti pati failus su pažymiais ir studentais, arba generuoti pažymius jau esamiems studentams, taip pat programa surušiuja pagal pasirinktą kriterijų studentus ir pagal poreikį paskirsto į dvį grupes (studentus kurie surinko teigiamą pažymį daugiau arba lygų 5 ir studentus, kurie gavo neigiamą pažymį. <br> 

- Pirmiausia programa paklausia pagal kurį parametrą **Vidurkis** arba **Mediana** jūs norite apskaičiuoti galutinį pažymį, jeigu norite skaičiuoti pagal vidurkį įveskite raidę "V" arba "v", jeigu pagal medianą įveskite raidę "M" arba "m";
- Jeigu yra poreikis sugeneruoti atsitiktinius studentų duomenys naujuose failuose įveskite raidę "T", jeigu nereikia tai - "N". Jeigu jūsų atsakymas yra "Taip", tai programa paprašys įvesti kiek studentų duomenų jūs norite sugeneruoti ir kiek pažymių jums reikia sugeneruoti visiems studentams (**įvestis priima tik sveikuosius skaičius**), tokiu būdu programa sugeneruos failą "studentai_n.txt", kur n yra jūsų ųvestas studentų skaičius;
- Kitame žingsnyje programa pasiūlo nuskaityti duoemys iš failo arba įvesti juos savarankiškai. Jei norite skaityti iš failo, tai įveskite "F" ir pasirinkite failą (su keliu) iš kurio skaitysite duomenis, jei norite įrašyti ranka, tai įveskite "R". Jei įvedimo metu pasirinkote įvesti ranka, tai galimi du variantai, įvesti studentų Vardą ir Pavardę ir savarankiškai įvesti namų darbų pažymius, kuriuos galite suvesti kiek reikia iki tol, kol paspausite du kartus ENTER bei egzamino pažymį, tam reikia paspausti "S". Jeigu turite studentų Vardą ir Pavardę bet norite sugeneruoti duomenys automatiškai kiekvienam iš jų, tai pasirinkite "S" ir kiekvienam studentui įrašykite kiek pažymių jam reikia sugeneruoti;
- Toliau reikia pasirinkti pagal ką norite rūšiuoti galutinius duomenys, jei pagal Vardą tai paspauskite "1", jei pagal Pavardę - "2", pagal Pažymį - "3";
- Jei norite paskirstyti studentus į dvi grupes pagal teigiamus ir neigiamus pažymius paspauskite "T", jei nereikia tai "N";
- Toliau reikia pasirinkti pagal kokia strategiją norite paskirstyti galutinius duomenys, jei pagal 1 strategiją, paspauskite "1", jei pagal 2 strategiją - "2", 3 strategiją Pažymį - "3";
- Programa baigta ir failai bus paruošti jūsų kompiuteryje.








