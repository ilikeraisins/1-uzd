#include "main.h"
#include "mylib.cpp"


int main() {
    string pasirinkimas;
    cout << "Duomenis skaityti ar generuoti? (S/G) " << endl;
    cin >> pasirinkimas;

    if (pasirinkimas == "S") {
        vector<studentas> grupe;
        cout << "Ar duomenis gauti is failo? (T/N) " << endl;
        cin >> pasirinkimas;

        if (pasirinkimas == "T") {
            timer tv;
            string eil;

            timer t;
            std::stringstream buffer = failo_skaitimas("C:\\Users\\Monika\\source\\repos\\main\\main\\1000000studentai.txt");
            cout << "Failo nuskaitymas: " << t.elapsed() << endl;
          

            std::getline(buffer, eil);

            vector<studentas> geri;
            vector<studentas> blogi;

            t.reset();
            while (buffer) {
                if (!buffer.eof()) {
                    std::getline(buffer, eil);
                    studentas laikinas = studentas_uzpildimas(eil);
                    if (laikinas.galutinis >= 5.0) {
                        geri.push_back(laikinas);
                    }
                    else {
                        blogi.push_back(laikinas);
                    }
                }
                else break;
            };
            std::sort(blogi.begin(), blogi.end(), palyginti_egzaminas);
            std::sort(geri.begin(), geri.end(), palyginti_egzaminas);

            cout << "Duomenu rusiavimas: " << t.elapsed() << endl;

            t.reset();
            rasymas_i_faila(geri, "C:\\Users\\Monika\\source\\repos\\main\\main\\GeraiBesimokantys.txt");
            rasymas_i_faila(blogi, "C:\\Users\\Monika\\source\\repos\\main\\main\\BlogaiBesimokantys.txt");
            cout << "Failu isvedimas: " << t.elapsed() << endl << endl;
            cout << "Viso: " << tv.elapsed() << endl << endl;
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
        generuoti_failus(1000, 5, "C:\\Users\\Monika\\source\\repos\\main\\main\\1000studentai.txt");
        generuoti_failus(10000, 5, "C:\\Users\\Monika\\source\\repos\\main\\main\\10000studentai.txt");
        generuoti_failus(100000, 5, "C:\\Users\\Monika\\source\\repos\\main\\main\\100000studentai.txt");
        generuoti_failus(1000000, 5, "C:\\Users\\Monika\\source\\repos\\main\\main\\1000000studentai.txt");
        generuoti_failus(10000000, 5, "C:\\Users\\Monika\\source\\repos\\main\\main\\10000000studentai.txt");
    }
}
