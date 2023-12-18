# Testavimų aprašymas 

**Testavimo sistemos parametrai:** <br />
**CPU:** Apple M2, 8 Core CPU <br />
**RAM:** 8 Gb <br />
**HDD:** 256Gb SSD <br />

# Releas'ų aprašymas
## v0.1
1. Nuskaito duomenis iš failo bei priima dumenis įvestus ranka arba sugeneruotus ir tvarkingai juos apdoroja;
2. Programa papildyta išimčių gaudymo metodu TRY - CATCH;
3. Atliktas programos refactoring'as, kuris leidžia atskirai nagrinėti ir tvarkyti programos dalis failuose.

## v0.2
1. Programa savarankiškai generuoja failus, pagal naudotojo nustatymus;
2. Rezultatų failai duomenys pateikinėja atitinkamai pagal vardą pavardę ir galutinį pažymį, bei rūšiuojami pagal naudotojo parinktą parametrą, bei grupuoja į dvi grupes;
3. Programoje atliekamas pasirinktų funkcijų testavimas 5 kartus, failų kūrimas, nuskaitymas, rušiavimas ir paskirstymas, pateikiamas atlkirų funkcijų vidurkis bei bendras vidurkis.

## v0.3
1. Programa išskaidyta į dvį atskiras programas su List ir Vector tipo konteineriais;
2. List ir Vector konteinerių atveju rankinio įvedimo metu ekrane išvedamas objekto saugojimo atmintyje adresas;
3. Atliekamas testavimas su iš anksčiau sugeneruotais failais ir pateikti kelių testų laikų vidurkiai abejų konteinerių atveju.

## v1.0
1. List ir Vector konteinerių atveju realizuotos visos strategijos (1-3);
2. Buvo atliktas testavimas su iš anksčiau sugeneruotais failais ir pateiktas kelių testų laikų vidurkis abiejų konteinerių atveju;
3. Programai sukurtas diegimo CMake failas bei paleidimo proceso instrukciją.

## v1.1
1. Sukurta programa su Class struktūra;
2. Programa naudoja patobulinta greičiausią dalijimo į dvi grupes strategiją;
3. Programa ištestuota su optimizavimo flagais O1, O2 ir O3.

## v1.2
1. Realizuotas "Rule of three" metodas;
2. Realizuoti įvesties ir įšvesties operatoriai klasėje;
3. Perdengti įvesties ir išvesties metodai darbui su Studentas class.

## v1.5
1. Realizuota abstrakti klasė Žmogus;
2. Realizuota, kad Studento klasė yra išvestinė iš Žmogaus klasės ir joje įgyvendintas "Rule of three" metodas;
3. Programoje yra patikrinama, ar yra galimybė sukurti klasės Žmogus objektą.

## v2.0
1. Sukurta Doxygen dokumentacija;

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
**Programos tikslas:** Programa apskaičiuoja studentų galutinius pažymius iš **n** skaičiaus namų darbų ir egzamino pažymio, pagal formulę **Galutinis pažymys = 0,6 * egzaminas + 0,4 * (namų darbų vidurkis)** pagal jūsų parinktą parametrą, vidurkį arba medianą, gali generuoti pati failus su pažymiais ir studentais, arba generuoti pažymius jau esamiems studentams, taip pat programa surušiuja pagal pasirinktą kriterijų studentus ir pagal poreikį paskirsto į dvį grupes (studentus kurie surinko teigiamą pažymį daugiau arba lygų 5 ir studentus, kurie gavo neigiamą pažymį. <br> 

- Pirmiausia programa paklausia pagal kurį parametrą **Vidurkis** arba **Mediana** jūs norite apskaičiuoti galutinį pažymį, jeigu norite skaičiuoti pagal vidurkį įveskite raidę "V" arba "v", jeigu pagal medianą įveskite raidę "M" arba "m";
- Jeigu yra poreikis sugeneruoti atsitiktinius studentų duomenys naujuose failuose įveskite raidę "T", jeigu nereikia tai - "N". Jeigu jūsų atsakymas yra "Taip", tai programa paprašys įvesti kiek studentų duomenų jūs norite sugeneruoti ir kiek pažymių jums reikia sugeneruoti visiems studentams (**įvestis priima tik sveikuosius skaičius**), tokiu būdu programa sugeneruos failą "studentai_n.txt", kur n yra jūsų ųvestas studentų skaičius;
- Kitame žingsnyje programa pasiūlo nuskaityti duoemys iš failo arba įvesti juos savarankiškai. Jei norite skaityti iš failo, tai įveskite "F" ir pasirinkite failą (su keliu) iš kurio skaitysite duomenis, jei norite įrašyti ranka, tai įveskite "R". Jei įvedimo metu pasirinkote įvesti ranka, tai galimi du variantai, įvesti studentų Vardą ir Pavardę ir savarankiškai įvesti namų darbų pažymius, kuriuos galite suvesti kiek reikia iki tol, kol paspausite du kartus ENTER bei egzamino pažymį, tam reikia paspausti "S". Jeigu turite studentų Vardą ir Pavardę bet norite sugeneruoti duomenys automatiškai kiekvienam iš jų, tai pasirinkite "S" ir kiekvienam studentui įrašykite kiek pažymių jam reikia sugeneruoti;
- Toliau reikia pasirinkti pagal ką norite rūšiuoti galutinius duomenys, jei pagal Vardą tai paspauskite "1", jei pagal Pavardę - "2", pagal Pažymį - "3";
- Jei norite paskirstyti studentus į dvi grupes pagal teigiamus ir neigiamus pažymius paspauskite "T", jei nereikia tai "N";
- Toliau reikia pasirinkti pagal kokia strategiją norite paskirstyti galutinius duomenys, jei pagal 1 strategiją, paspauskite "1", jei pagal 2 strategiją - "2", 3 strategiją Pažymį - "3";
- Programa baigta ir failai bus paruošti jūsų kompiuteryje.

# Programos versija V1.1:
**Struct** ir **Class** vektoriaus atveju testavimo rezultatai naudojant greičiausia dalijimo strategiją **(3)**:

|         Vector(Struct)        |     100000    |    1000000    |         Vector(Class)         |     100000    |    1000000   |
|:-----------------------------:|:-------------:|:-------------:|:-----------------------------:|:-------------:|:------------:|
|Failo Nuskaitymas       | 1.07586886 s. |  3.2657213 s. |Failo Nuskaitymas       |  1.5432338 s.  |  4.05332 s. |
|Sort() veiksmas        |  0.4211282 s. |  0.1614838 s.  |Sort() veiksmas        |  0.4335954 s. |  3.843296 s. |
|Padalijimas į dvi grupes |  0.0383447 s. |  0.6047205 s. |Padalijimas į dvi grupes | 0.03993036 s. | 0.4424954 s. |
|Rašymas į vargščiukų failą  |  0.1644058 s. |  0.7435087 s.  |Rašymas į vargščiukų failą  |  0.1677366 s. |  1.848376 s. |
|Rašymas į kietuolių failą   |  0.1898104 s. |  0.9762628 s. |Rašymas į kietuolių failą   |  0.180565 s.  | 1.6300066 s. |
|Bendras        | 1.34658872 s. | 5.14697673 s. |Bendras       |  1.6229318 s. | 9.777604 s. |


**Struct** vektoriaus atveju testavimo su flagais rezultatai:

|         Vector(Struct)        |   100000 O1   |   100000 O2   |   100000 O3   |  1000000 O1  |   1000000 O2  |   1000000 O3  |
|:-----------------------------:|:-------------:|:-------------:|:-------------:|:------------:|:-------------:|:-------------:|
|Failo Nuskaitymas       |  0.1047336 s. |  0.1012521 s.  |  0.1029884 s. |  0.8945647 s. |   0.8684985 s.  |   0.8634867 s.  |
|Sort() veiksmas        | 0.0105355 s. | 0.0119087 s. | 0.0108290 s. |  0.0647678 s. |  0.0662287 s. |  0.0626851 s. |
|Padalijimas į dvi grupes | 0.0210280 s. | 0.0197281 s. | 0.0208310 s. | 0.1202604 s. |  0.1284925 s. |  0.1222045 s. |
|Rašymas į vargščiukų failą  |  0.0663365 s. |  0.0656367 s. |  0.0678912 s. |  0.6133744 s. |  0.6039154 s.  |  0.6090311s.  |
|Rašymas į kietuolių failą   |  0.0878979 s. |  0.0888083 s.  |  0.0890664 s. |  0.8782195 s. |  0.8799783 s.  |  0.8877255 s.  |
|Bendras        |  0.2905315 s. |  0.2873339 s. |  0.291606 s. | 2.4509265 s. | 2.4186210 s. | 2.4229285 s. |

**Išvada:** Su optimizavimo flagu **O2** programa su Struct struktūra ir vector dirba greičiausiai su dideliais duomenų kiekiais.

**Class** vektoriaus atveju testavimo su flagais rezultatai:

|         Vector(Class)         |   100000 O1   |   100000 O2  |   100000 O3  |   1000000 O1  |   1000000 O2  |   1000000 O3  |
|:-----------------------------:|:-------------:|:------------:|:------------:|:-------------:|:-------------:|:-------------:|
|Failo Nuskaitymas       |  0.1073417 s. | 0.1075639 s. | 0.1050410 s. |   0.9302178 s.  |   0.9164523 s.  |  0.8666101 s.  |
|Sort() veiksmas        |  0.0138788 s. |  0.0122416 s. | 0.0128199 s. |  0.0842912 s.  |  0.0766853 s.  |  0.0793048 s.  |
|Padalijimas į dvi grupes |  0.0240622 s. | 0.0212215 s. | 0.0245570 s. |  0.1370512 s. |  0.1271955 s. |  0.1300693 s. |
|Rašymas į vargščiukų failą  |  0.0646673 s.  | 0.0650587 s. |  0.0654038 s. |  0.6131768 s. |   0.6235871 s.  |  0.6318640 s.  |
|Rašymas į kietuolių failą   |  0.0858257 s. | 0.0854569 s. | 0.0879485 s. |   0.8755665 s.   |   0.8771652 s.  |   0.8864610 s.  |
|Bendras        | 0.2957751 s. | 0.2703213 s. | 0.2712133 s. | 2.5032525 s. | 2.6210854 s. | 2.4642400 s. |

**Išvada:** Su optimizavimo flagu **O3** programa su Class struktūra ir vector dirba greičiausiai su dideliais duomenų kiekiais.

Exec failo dydžiai priklausomai nuo panaudoto flago:
| Vector | Be flagu | O1      | O2      | O3      |
|--------|----------|---------|---------|---------|
| Struct | 303 KB   | 106 KB | 106 KB | 106 KB |
| Class  | 324 KB   | 106 KB | 106 KB | 106 KB |

# "Rule of three" įgyvendinimas klasėje
<img width="1470" alt="Rule Of Free" src="https://github.com/Arina1311/AntrasProjektas/assets/144428021/884f51e7-2262-46fb-8f02-71db9eae0afc">
Klasėje yra sukurti:<br />
1. Kopijavimo konstruktorius; <br />
2. Priskyrimo operatorius; <br />
3. Destruktorius. <br />

# Įvesties ir išvesties operatoriai klasėje
<img width="1470" alt="Ivestis" src="https://github.com/Arina1311/AntrasProjektas/assets/144428021/2b288d39-0ad4-4b25-ab97-2eeed48c21c1">
<img width="1470" alt="Ivestis 2" src="https://github.com/Arina1311/AntrasProjektas/assets/144428021/88841a85-592d-4f5b-98eb-cc2b80457b33">
<img width="1470" alt="Isvestis" src="https://github.com/Arina1311/AntrasProjektas/assets/144428021/9f55b96a-41bf-4b7d-b505-5b9e07b066c7">

# Įvesties ir išvesties realizavimas programoje
## Įvesties realizavimas main.cpp:
<img width="1470" alt="Realizavimas ivesties" src="https://github.com/Arina1311/AntrasProjektas/assets/144428021/27b0d876-e05a-40b6-82c9-2d44cdc5edc4">

Įvesties operatorius suveikia tuo metu, kai naudotojas nori savarankiškai sukurti studentams duomenis arba juos sugeneruoti programos pagalba.
## Išvesties realizavimas išvedimas.cpp funkcijose:
<img width="1470" alt="Realizavimas isvesties" src="https://github.com/Arina1311/AntrasProjektas/assets/144428021/50d00498-0e95-4ebf-a14b-0f61edd593bc">

Išvesties operatorius suveikia tuo metu, kai naudotojas prašo parodyti skaičiavimų rezultatą ekrane arba surašyti rezultatus į failą.

## Abstrakčios klasės Žmogus kūrimas ir klasės Studentas realizavimas kaip išvestinės klasės iš klasės Žmogus
Duomenys.h faile yra realizuota abstrakti klasė Žmogus su virtualiais metodais.<br />
<br />
<img width="736" alt="Снимок экрана 2023-12-09 в 15 11 23" src="https://github.com/Arina1311/AntrasProjektas/assets/144428021/26764cb0-48e1-4ea7-a955-b720ed4d27c9"><br />

Taip pat padaryta, kad klasė Studentas būtų klasės Žmogus išvestinė klasė su savo metodais, joje taip pat lieka įgyvendintas metodas "Rule of three".<br />
<br />
<img width="938" alt="Снимок экрана 2023-12-09 в 15 12 00" src="https://github.com/Arina1311/AntrasProjektas/assets/144428021/e7ff86d9-0b70-4f5d-aaea-dfb088d38272"><br />

Programoje yra tikrinama, ar galime sukurti iš karto Žmogaus klasės objektą, programa parodo klaidą, kad to neįmanoma padaryti.<br />
<br />
<img width="1244" alt="Снимок экрана 2023-12-09 в 15 04 05" src="https://github.com/Arina1311/AntrasProjektas/assets/144428021/1744c28d-c025-4d63-8b1e-8ecc6e6c56cf">

# Unit Testai
Testuoti programą buvo naudojamas Google Test Framework'as. <br />
Buvo sukurti tris testai:<br /><br />
**Įvesties testas:**<br /><br />
<img width="666" alt="Снимок экрана 2023-12-18 в 20 50 14" src="https://github.com/Arina1311/AntrasProjektas/assets/144428021/d4887dd2-f049-48ea-98b7-3c57dda95f93"><br /><br />
**Galutinio pažymio testas:**<br /><br />
<img width="928" alt="Снимок экрана 2023-12-18 в 20 50 38" src="https://github.com/Arina1311/AntrasProjektas/assets/144428021/398be04a-646e-4ced-907e-602b62c6a95b"><br /><br />
**Duomenų failo skatymo testas:**<br /><br />
<img width="680" alt="Снимок экрана 2023-12-18 в 20 50 51" src="https://github.com/Arina1311/AntrasProjektas/assets/144428021/0cd384a7-83c4-4f3b-beeb-2d677444d410"><br /><br />

Atlikus šiuos testus programa veikia teisingai ir praena visus testus: <br /><br />
<img width="508" alt="Снимок экрана 2023-12-18 в 20 48 55" src="https://github.com/Arina1311/AntrasProjektas/assets/144428021/8de4ff6b-2a9b-4d10-8f3a-cd0536a6eb9f"><br /><br />
Jeigu pakeisime įvesties laukiamą rezultatą taip: <br /><br />
<img width="452" alt="Снимок экрана 2023-12-18 в 20 51 22" src="https://github.com/Arina1311/AntrasProjektas/assets/144428021/8a07a303-ecb5-41e6-be9c-e892c4003870"><br /><br />
Tai pamatysime, kad vieno testo programa neišlaikė:<br /><br />
<img width="510" alt="Снимок экрана 2023-12-18 в 20 52 19" src="https://github.com/Arina1311/AntrasProjektas/assets/144428021/6c7fcf7d-62a2-4b47-8389-80cb391476f7"><br /><br />
