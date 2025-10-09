#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::left;
using std::right;
using std::vector;

struct studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> pazymiai;
    int egzaminas;
    double galutinis;
    double galutinis_mediana;
};

double mediana(vector<int>);
double vidurkis(vector<int>);
void lentele(vector<studentas>, string);
double galutinio_sk(double, int);
void generuoti_failus(int, int,string);
void rasymas_i_faila(vector<studentas>, string);

bool palyginti(studentas, studentas);
bool palyginti_egzaminas(studentas, studentas);
bool palyginti_mediana(studentas, studentas);
bool palyginti_pavarde(studentas, studentas);
void rusiuojam(vector<studentas>, int);

std::stringstream failo_skaitimas(string);
studentas studentas_uzpildimas(string);

bool geri_funk(studentas);
bool blogi_funk(studentas);

class timer;
