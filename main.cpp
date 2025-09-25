
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
vector<int> nd_ivedimas();
double sume(vector<int>);


int main() {
    vector<studentas> grupe;

    int n;
    cout << "Studentu skaicius: ";
    cin >> n;

    studentas laikinas;

    for (int i = 0; i < n; i++) {
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

            cout << "Namų darbų pažymių skaičius: ";
            cin >> sk;

            for (int j = 0; j < sk; j++) {
                laikinas.pazymiai.push_back(dist(gen));
            }
            laikinas.egzaminas = dist(gen);
        }
        else {
            laikinas.pazymiai = nd_ivedimas();
            cout << "Egzamino pazymis: ";
            cin >> laikinas.egzaminas;
        }

        laikinas.galutinis = (laikinas.egzaminas * 0.6) + (suma(laikinas.pazymiai) / double(laikinas.pazymiai.size()) * 0.4);
        cout << "Galutinis pazymis (Vid.): " << laikinas.galutinis << endl;

        vector<int> visi_pazymiai = laikinas.pazymiai;
        visi_pazymiai.push_back(laikinas.egzaminas);
        laikinas.galutinis_mediana = mediana(visi_pazymiai);
        cout << "Galutinis pazymis (Med.): " << laikinas.galutinis_mediana << endl;
        grupe.push_back(laikinas);
    }


    cout << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(15) << right << "Galutinis pazymis(Vid.) / Galutinis pazymis(Median.)" << "\n";
    for (int k = 0; k < grupe.size(); k++) {
       cout << setw(15) << left << grupe[k].vardas << setw(15) << left << grupe[k].pavarde << setw(23) << right << round(grupe[k].galutinis * 100) / 100 << setw(23) << right << grupe[k].galutinis_mediana << endl;
    }
}


double mediana(vector<int> x) {
    sort(x.begin(), x.end());
    int n = x.size();
    if (n % 2 == 0) {
        return ((double(x[n / 2]) + double(x[n / 2 - 1])) / 2);
    } 
    else {
        return x[n / 2];
    }
}

vector<int> nd_ivedimas() {
    int pazymis;
    vector<int> pazymiai;
    cout << "Veskite pažymius: " << endl;
    while (true) {
        cin >> pazymis;
        if (pazymis == 0) {
            break;
        }
        pazymiai.push_back(pazymis);
    }
    return pazymiai;
}

double suma(vector<int> x) {
    double suma = 0;
    for (int i = 0; i < x.size(); i++) {
        suma = suma + double(x[i]);
    }
    return suma;
}

