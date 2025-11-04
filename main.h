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

#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::left;
using std::right;
using std::vector;

using std::list;

struct studentas {
    string vardas;
    string pavarde;
    list<int> pazymiai;
    int egzaminas;
    double galutinis;
    double galutinis_mediana;
};

double mediana(list<int>);
double vidurkis(list<int>);
void lentele(list<studentas>, string);
double galutinio_sk(double, int);
void generuoti_failus(int, int,string);
void rasymas_i_faila(list<studentas>, string);

bool palyginti(studentas, studentas);
bool palyginti_egzaminas(studentas, studentas);
bool palyginti_mediana(studentas, studentas);
bool palyginti_pavarde(studentas, studentas);


std::stringstream failo_skaitimas(string);
studentas studentas_uzpildimas(string);

class timer;
