
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
void generuoti_failus(int, int, string);
void isvedimas_i_faila(vector<studentas>, string);

bool palyginti(studentas a, studentas b);

int main() {
    string pasirinkimas;
    cout << "Duomenis skaityti ar generuoti? (S/G) " << endl;
    cin >> pasirinkimas;

    if (pasirinkimas == "S") {
        cout << "Ar duomenis gauti is failo? (T/N) " << endl;
        cin >> pasirinkimas;

        if (pasirinkimas == "T") {
            vector<studentas> grupeGerai;
            vector<studentas> grupeBlogai;

            std::stringstream buffer;
            string eil;
            string zod;

            std::ifstream fl("C:\\Users\\Monika\\source\\repos\\main\\main\\100000studentai.txt");
            buffer << fl.rdbuf();
            fl.close();
            
            studentas laikinas;
            std::getline(buffer, eil);

            while (buffer) {
                if (!buffer.eof()) {
                    std::getline(buffer, eil);

                    std::stringstream dalys(eil);

                    dalys >> laikinas.vardas >> laikinas.pavarde;

                    while (dalys >> zod) {
                        laikinas.pazymiai.push_back(std::stoi(zod));
                    }
                    laikinas.egzaminas = laikinas.pazymiai.back();
                    laikinas.pazymiai.pop_back();

                    laikinas.galutinis = round(galutinio_sk(vidurkis(laikinas.pazymiai), laikinas.egzaminas) * 100) / 100;
                    laikinas.galutinis_mediana = galutinio_sk(mediana(laikinas.pazymiai), laikinas.egzaminas);

                    if (laikinas.galutinis < 5.0) {
                        grupeBlogai.push_back(laikinas);
                    }
                    else {
                        grupeGerai.push_back(laikinas);
                    }
                    laikinas.pazymiai.clear();
                }
                else break;
            };
            
            std::sort(grupeGerai.begin(), grupeGerai.end(), palyginti);
            std::sort(grupeBlogai.begin(), grupeBlogai.end(), palyginti);

            isvedimas_i_faila(grupeGerai, "Geraibesimokantis.txt");
            isvedimas_i_faila(grupeBlogai, "Blogaibesimokantis.txt");
        }
        else {
            vector<studentas> grupe;

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

                cout << "Pazymius ivedami ar generuojami? (V/G) " << endl;
                string pasirinkimas1;
                cin >> pasirinkimas1;

                if (pasirinkimas1 == "G") {
                    int sk;

                    std::random_device seed;
                    std::mt19937 gen{ seed() };
                    std::uniform_int_distribution<> dist(1, 10);

                    cout << "Pazymiu skaicius: ";
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


                laikinas.galutinis = galutinio_sk(vidurkis(laikinas.pazymiai), laikinas.egzaminas);
                laikinas.galutinis = round(laikinas.galutinis * 100) / 100;
                laikinas.galutinis_mediana = galutinio_sk(mediana(laikinas.pazymiai), laikinas.egzaminas);
                grupe.push_back(laikinas);
            }

            string pasirinkimas;
            cout << "Vesti lentele su vidurkiu, mediana arba abeim? (V/M/A): ";
            cin >> pasirinkimas;
            lentele(grupe, pasirinkimas);
        }
    }
    else {
        generuoti_failus(1000,5,"1000studentai.txt");
        generuoti_failus(10000, 5, "10000studentai.txt");
        generuoti_failus(100000, 5, "100000studentai.txt");
        //generuoti_failus(1000000, 5, "1000000studentai.txt");
        //generuoti_failus(10000000, 5, "10000000studentai.txt");
    }
}

void isvedimas_i_faila(vector<studentas> x, string failo_vardas) {
    string visas;
    for (int i = 0; i < x.size(); i++) {
        studentas laik = x[i];
        visas += laik.vardas + " " + laik.pavarde + " " + std::to_string(laik.galutinis) + " " + std::to_string(laik.galutinis_mediana) + "\n";
    }
    std::ofstream out_f(failo_vardas);
    out_f << visas;
    out_f.close();
}

void lentele(vector<studentas> x, string y) {
    std::sort(x.begin(), x.end(), palyginti);
    cout << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(15) << right;
    if (y == "V") {
        cout << "Galutinis pazymis(Vid.)" << endl;
        for (int m = 0; m < x.size(); m++) {
            cout << setw(15) << left << x[m].vardas << setw(15) << left << x[m].pavarde << setw(17) << right << x[m].galutinis << endl;
        }
    }
    else if (y == "M") {
        cout << "Galutinis pazymis(Median.)" << endl;
        for (int m = 0; m < x.size(); m++) {
            cout << setw(15) << left << x[m].vardas << setw(15) << left << x[m].pavarde << setw(17) << right << x[m].galutinis_mediana << endl;
        }
    }
    else if (y == "A") {
        cout << "Galutinis pazymis(Vid.) Galutinis pazymis(Median.)" << endl;
        for (int a = 0; a < 80; a++) {
            cout << "-";
        }
        cout << endl;
        for (int m = 0; m < x.size(); m++) {
            cout << setw(15) << left << x[m].vardas << setw(15) << left << x[m].pavarde << setw(24) << left << x[m].galutinis << left << x[m].galutinis_mediana << endl;
        }
    }
}

void generuoti_failus(int studentu_sk, int darbu_sk, string failo_vardas) {
    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> dist(1, 10);

    string visas;

    for (int i = 1; i <= studentu_sk; i++) {
        string str;
        str += "\n";
        str += "Vardas" + std::to_string(i) + " " + "Pavarde" + std::to_string(i);
        for (int j = 0; j <= darbu_sk; j++) {
            str += " " + std::to_string(dist(mt));
        }
        visas += str;
    }
    std::ofstream out_f(failo_vardas);
    out_f << visas;
    out_f.close();
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

bool palyginti(studentas a, studentas b) {
    if (a.vardas != b.vardas) {
        return a.vardas > b.vardas;
    }
    return a.galutinis > b.galutinis;
}