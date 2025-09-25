
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::left;
using std::right;
using std::vector;


struct studentas {
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    int egzaminas;
    double galutinis;
    double galutinis_mediana;
};

double mediana(vector<int>);
double vidurkis(vector<int>);
void lentele(vector<studentas>, string);
double galutinio_sk(double, int);

int main() {
    vector<studentas> grupe;

    string pasirinkimas;
    cout << "Ar duomenis gauti is failo? (T/N)? " << endl;
    cin >> pasirinkimas;

    if (pasirinkimas == "T") {
        std::ifstream fl;
        fl.open("C:\\Users\\Monika\\Downloads\\studentai10000.txt");
        string eil;
        string zod;
        getline(fl, eil);
        while (getline(fl, eil)) {
            studentas laikinas;
            std::stringstream dalys(eil);
            dalys >> laikinas.vardas >> laikinas.pavarde;
            for (int g = 0; g < 15; g++) {
                dalys >> zod;
                laikinas.pazymiai.push_back(stoi(zod));
            }
            dalys >> laikinas.egzaminas;

            laikinas.galutinis = round(galutinio_sk(vidurkis(laikinas.pazymiai), laikinas.egzaminas)*100)/100;
            laikinas.galutinis_mediana = galutinio_sk(mediana(laikinas.pazymiai), laikinas.egzaminas);
            grupe.push_back(laikinas);
        }
        lentele(grupe, "A");
    }
    else {
        int n;
        cout << "Studentu skaicius: ";
        cin >> n;
       
        for (int i = 0; i < n; i++) {
            studentas laikinas;
            cout << "Studentas nr. " << i + 1 << endl;
            cout << "Vardas: ";
            cin >> laikinas.vardas;
            cout << "Pavarde: ";
            cin >> laikinas.pavarde;

            cout << "Pazymius ivesti po viena ar generuoti? (V/G) " << endl;
            string pasirinkimas1;
            cin >> pasirinkimas1;

            if (pasirinkimas1 == "G") {
                int sk;

                std::random_device seed;
                std::mt19937 gen{ seed() };
                std::uniform_int_distribution<> dist(1, 10);

                cout << "Namu darbu pazymiu skaicius: ";
                cin >> sk;

                for (int j = 0; j < sk; j++) {
                    laikinas.pazymiai.push_back(dist(gen));
                }
                laikinas.egzaminas = dist(gen);
            }
            else {
                int pazymis = 1;
                cout << "Veskite pazymius (0 jeigu norite nustoti vesti): " << endl;
                while (pazymis) {
                    cin >> pazymis;
                    if (pazymis != 0) {
                        laikinas.pazymiai.push_back(pazymis);
                    }
                }
                cout << "Egzamino pazymis: ";
                cin >> laikinas.egzaminas;
            }


            laikinas.galutinis = galutinio_sk(vidurkis(laikinas.pazymiai),laikinas.egzaminas);
            laikinas.galutinis = round(laikinas.galutinis * 100) / 100;
            laikinas.galutinis_mediana = galutinio_sk(mediana(laikinas.pazymiai),laikinas.egzaminas);
            grupe.push_back(laikinas);
        }

        string pasirinkimas;
        cout << "Vesti lentele su vidurkiu, mediana arba abu (V/M/A): ";
        cin >> pasirinkimas;
        lentele(grupe, pasirinkimas);
    }
}


void lentele(vector<studentas> x, string y) {
    if (y == "V") {
        cout << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(15) << right << "Galutinis pazymis(Vid.)" << endl;
        for (int m = 0; m < x.size(); m++) {
            cout << setw(15) << left << x[m].vardas << setw(15) << left << x[m].pavarde << setw(17) << right << x[m].galutinis << endl;
        }
    }
    else if (y == "M") {
        cout << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(15) << right << "Galutinis pazymis(Median.)" << endl;
        for (int m = 0; m < x.size(); m++) {
            cout << setw(15) << left << x[m].vardas << setw(15) << left << x[m].pavarde << setw(17) << right << x[m].galutinis_mediana << endl;
        }
    }
    else if (y == "A") {
        cout << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(15) << right << "Galutinis pazymis(Vid.) / Galutinis pazymis(Median.)" << endl;
        int t = 0;
        while (t < 80) {
            cout << "-";
            t++;
        }
        cout << endl;
        for (int m = 0; m < x.size(); m++) {
            cout << setw(15) << left << x[m].vardas << setw(15) << left << x[m].pavarde << setw(17) << right << x[m].galutinis << setw(26) << right << x[m].galutinis_mediana << endl;
        }
    }
}

double mediana(vector<int> x) {
    sort(x.begin(), x.end());

    int n = x.size();
    if (n % 2 == 0) {
        return (double)(x[(n-1)/2] + x[n/2])/2.0;
    }
    return (double)x[n / 2];
}

double vidurkis(vector<int> x) {
    double suma = 0;
    for (int i = 0; i < x.size(); i++) {
        suma = suma + double(x[i]);
    }
    return suma/x.size();
}

double galutinio_sk(double x, int y) {
    return (x * 0.4 + double(y) * 0.6);
}

