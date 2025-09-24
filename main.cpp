// OP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>

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
    int pazymiu_sk;
    vector<int> darbu_pazymiai;
    int egzamino_pazymis;
    double galutinis_pazymis;
    double mediana;
};

double mediana(vector<int> x) {
    sort(x.begin(), x.end());
    int n = x.size();
    if (n % 2 == 0) {
        return ((double(x[n / 2]) + double(x[n / 2 - 1])) / 2);
    }
    else {
        return x[n/2];
    }
}


int main()
{   
    vector<studentas> grupe;
    int n;
    cout << "Studentu skaicius: ";
    cin >> n;
    studentas laikinas;
    for (int i = 0; i < n; i++) {
        cout << "Studentas nr. " << i + 1 << "\n";
        cout << "Vardas: ";
        cin >> laikinas.vardas;
        cout << "Pavarde: ";
        cin >> laikinas.pavarde;
        cout << "Pazymiu skaicius: ";
        cin >> laikinas.pazymiu_sk;
        int pazymis;
        int sum = 0;
        for (int j = 0; j < laikinas.pazymiu_sk; j++) {
            cout << "Pazymis nr. " << j + 1 << "\n";
            cin >> pazymis;
            laikinas.darbu_pazymiai.push_back(pazymis);
            sum += pazymis;
        }
        cout << "Egzamino pazymis: ";
        cin >> laikinas.egzamino_pazymis;
        laikinas.galutinis_pazymis = laikinas.egzamino_pazymis * 0.6 + double(sum) / double(laikinas.darbu_pazymiai.size()) * 0.4;
        cout << "Galutinis pazymis (Vid.): " << laikinas.galutinis_pazymis << "\n";
        vector<int> visi_pazymiai = laikinas.darbu_pazymiai;
        visi_pazymiai.push_back(laikinas.egzamino_pazymis);
        laikinas.mediana = mediana(visi_pazymiai);
        cout << "Galutinis pazymis (Med.): " << laikinas.mediana << endl;
        grupe.push_back(laikinas);
    }
    cout << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(15) << right << "Galutinis pazymis(Vid.) / Galutinis pazymis(Median.)" << "\n";
    for (int k = 0; k < grupe.size(); k++) {
        cout << setw(15) << left << grupe[k].vardas << setw(15) << left << grupe[k].pavarde << setw(23) << right << round(grupe[k].galutinis_pazymis * 100) / 100 <<setw(23) << right << grupe[k].mediana << endl;
    }
}