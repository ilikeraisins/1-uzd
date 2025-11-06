#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>
#include <chrono>
#include <vector>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::left;
using std::right;
using std::list;
using std::vector;

struct studentas {
    string vardas;
    string pavarde;
    vector<int>pazymiai;
    //list<int> pazymiai;
    int egzaminas;
    double galutinis;
    double galutinis_mediana;
};

double mediana(vector<int> /*list<int>*/);
double vidurkis(/*list<int>*/ vector<int>);

void lentele(vector<studentas> /*list<studentas>*/, string);
double galutinio_sk(double, int);
void generuoti_failus(int, int,string);
void rasymas_i_faila(vector<studentas> /*list<studentas>*/, string);

bool palyginti(studentas, studentas);
bool palyginti_vardas(studentas, studentas);
bool palyginti_pavarde(studentas, studentas);
bool palyginti_galutinis(studentas, studentas);

std::stringstream failo_skaitimas(string);
studentas studentas_uzpildimas(string);

class timer {
    using hrClock = std::chrono::high_resolution_clock;
    using durationDouble = std::chrono::duration<double>;
private:
    std::chrono::time_point<hrClock> start;
public:
    timer() : start{ hrClock::now() } {}
    void reset() {
        start = hrClock::now();
    }
    double elapsed() const {
        return durationDouble(hrClock::now() - start).count();
    }
};
