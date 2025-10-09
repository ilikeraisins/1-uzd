#include "main.h"


studentas studentas_uzpildimas(string eil) {
    studentas laikinas;
    string zod;
    std::stringstream dalys(eil);

    dalys >> laikinas.vardas >> laikinas.pavarde;

    while (dalys >> zod) {
        laikinas.pazymiai.push_back(std::stoi(zod));
    }
    laikinas.egzaminas = laikinas.pazymiai.back();
    laikinas.pazymiai.pop_back();
    laikinas.pazymiai.resize(laikinas.pazymiai.size());

    laikinas.galutinis = round(galutinio_sk(vidurkis(laikinas.pazymiai), laikinas.egzaminas) * 100) / 100;
    laikinas.galutinis_mediana = galutinio_sk(mediana(laikinas.pazymiai), laikinas.egzaminas);
    return laikinas;
}

std::stringstream failo_skaitimas(string failo_vardas) {
    std::stringstream buffer;
    string eil;
    string zod;

    std::ifstream fl(failo_vardas);
    buffer << fl.rdbuf();
    fl.close();
    return buffer;
}

void rasymas_i_faila(vector<studentas> x, string failo_vardas) {
    string visas;
    string galut_v;
    string galut_m;
    for (int i = 0; i < x.size(); i++) {
        studentas laik = x[i];
        galut_v = std::to_string(laik.galutinis).substr(0,4);
        galut_m = std::to_string(laik.galutinis_mediana).substr(0,4);
        visas += laik.vardas + " " + laik.pavarde + " " + galut_v + " " + galut_m + "\n";
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
    std::ofstream file(failo_vardas);
    file << visas;
    file.close();
}

double mediana(vector<int> x) {
    sort(x.begin(), x.end());

    int n = x.size();
    if (n % 2 == 0) {
        return (double)(x[(n - 1) / 2] + x[n / 2]) / 2.0;
    }
    return (double)x[n / 2];
}

double vidurkis(vector<int> x) {
    double suma = 0;
    for (int i = 0; i < x.size(); i++) {
        suma = suma + double(x[i]);
    }
    return suma / x.size();
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

bool palyginti_egzaminas(studentas a, studentas b) {
    if (a.vardas != b.vardas) {
        return a.vardas > b.vardas;
    }
    if (a.galutinis != b.galutinis) {
        return a.galutinis > b.galutinis;
    }
    return a.egzaminas > b.egzaminas;
}

bool palyginti_pavarde(studentas a, studentas b) {
    if (a.vardas != b.vardas) {
        return a.vardas > b.vardas;
    }
    if (a.galutinis != b.galutinis) {
        return a.galutinis > b.galutinis;
    }
    return a.pavarde > b.pavarde;
}

bool palyginti_mediana(studentas a, studentas b) {
    if (a.vardas != b.vardas) {
        return a.vardas > b.vardas;
    }
    if (a.galutinis != b.galutinis) {
        return a.galutinis > b.galutinis;
    }
    return a.galutinis_mediana > b.galutinis_mediana;
}



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
        return durationDouble( hrClock::now() - start).count();
    }
};