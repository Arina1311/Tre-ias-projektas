#include "gtest/gtest.h"
#include "include/duomenys.h"
#include "include/FailoNuskaitymas.h"
#include "include/Isvedimas.h"
#include "src/duomenys.cpp"
#include "src/FailoNuskaitymas.cpp"
#include <iostream>
#include <fstream>
#include <vector>



TEST(StudentasTest, SettersAndGetters) {
    Studentas student;
    student.setvardas("Arina");
    student.setpavarde("Tichonovskaja");

    EXPECT_EQ("Arina", student.vardas());
    EXPECT_EQ("Tichonovskaja", student.pavarde());
}

TEST(GalutinioPazymoFuncijos, GalutinisPazymisTest) {

    vector<int> duomenys = {8, 9, 7};
    int egzaminas = 10;
    char pasirinkimas = 'V';

    float expected_result = 0.4 * (8 + 9 + 7) / 3 + 0.6 * 10;

    float result = GalutinisPazymis(accumulate(duomenys.begin(), duomenys.end(), 0), duomenys, egzaminas, pasirinkimas);

    EXPECT_FLOAT_EQ(expected_result, result);
}

TEST(DuomenuSkaitymoIsFailo, SkaitytiDuomenisIsFailoTest) {
   
    std::ofstream test_file("test_file.txt");
    test_file << "Vardas Pavarde ND1 ND2 ND3 Egz.\n";
    test_file << "Arina Tichonovskaja 6 9 6 10\n";
    test_file.close();
 
    string file_name = "test_file.txt";
    char pasirinkimas = 'V';

    vector<Studentas> result = SkaitytiDuomenisIsFailo(file_name, pasirinkimas);

    EXPECT_EQ(2, result.size());

    EXPECT_EQ("Arina", result[0].vardas());
    EXPECT_EQ("Tichonovskaja", result[0].pavarde());
}

int main (int argc, char **argv){
    testing::InitGoogleTest (&argc, argv);
    return RUN_ALL_TESTS ();
}

