
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include <random>

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

int main() {
    vector<studentas> grupe;

    int n;
    cout << "Studentu skaicius: ";
    cin >> n;


    for (int i = 0; i < n; i++) {
        studentas laikinas;
        cout << "Studentas nr. " << i + 1 <<endl;
        cout << "Vardas: ";
        cin >> laikinas.vardas;
        cout << "Pavarde: ";
        cin >> laikinas.pavarde;

        cout << "Atsitiktinai sugeneruoti balus? (T/N) " << endl;
        string pasirinkimas;
        cin >> pasirinkimas;

        if (pasirinkimas == "T") {
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

        laikinas.galutinis = double(laikinas.egzaminas)*0.6 + (vidurkis(laikinas.pazymiai))*0.4;
        laikinas.galutinis = round(laikinas.galutinis * 100) / 100;
        cout << "Galutinis pazymis (Vid.): " << laikinas.galutinis << endl;

        laikinas.galutinis_mediana = double(laikinas.egzaminas) + double(mediana(laikinas.pazymiai))*0.4;
        cout << "Galutinis pazymis (Med.): " << laikinas.galutinis_mediana << endl;

        grupe.push_back(laikinas);
    }

    string pasirinkimas;
    cout << "Vesti lentele su vidurkiu, mediana arba abu (V/M/A): ";
    cin >> pasirinkimas;
    lentele(grupe, pasirinkimas);
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
        cout << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(15) << right << "Galutinis pazymis(Vid.) / Galutinis pazymis(Median.)" << "\n";
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

