#include "main.h"
#include "mylib.cpp"

int main() {
    string pasirinkimas;
    cout << "Duomenis skaityti ar generuoti? (S/G) " << endl;
    cin >> pasirinkimas;

    if (pasirinkimas == "S") {
        list<studentas> grupe;
        cout << "Ar duomenis gauti is failo? (T/N) " << endl;
        cin >> pasirinkimas;

        if (pasirinkimas == "T") {
            cout << endl << "Be to, kad studentai rusiuojami pagal varda ir galutini pazymi, pagal ka dar rusiuoti? " << endl;
            cout << "(G - galutini pazymi, P - pavarde, V - varda)" << endl;
            cin >> pasirinkimas;

            timer tv;
            string eil;

            timer t;
            std::stringstream buffer = failo_skaitimas("1000studentai.txt");
            cout << "Failo nuskaitymas: " << t.elapsed() << endl;
          
            std::getline(buffer, eil);

            t.reset();
            while (buffer) {
                if (!buffer.eof()) {
                    std::getline(buffer, eil);
                    studentas laikinas = studentas_uzpildimas(eil);
                    grupe.push_back(laikinas);
                }
                else break;
            };

          
            list<studentas> geri(grupe.size());
            list<studentas> blogi(grupe.size());

            copy_if(grupe.begin(), grupe.end(), blogi.begin(), [](studentas x) {return x.galutinis < 5; });
            copy_if(grupe.begin(), grupe.end(), geri.begin(), [](studentas x) {return x.galutinis >= 5; });

            if (pasirinkimas == "V") {
                blogi.sort(palyginti_vardas);
                geri.sort(palyginti_vardas);
            }
            else if (pasirinkimas == "P") {
                blogi.sort(palyginti_pavarde);
                geri.sort(palyginti_pavarde);
            }
            else if (pasirinkimas == "G") {
                blogi.sort(palyginti_galutinis);
                geri.sort(palyginti_galutinis);
            }

            cout << "Duomenu rusiavimas: " << t.elapsed() << endl;

            t.reset();
            rasymas_i_faila(geri, "GeraiBesimokantys.txt");
            rasymas_i_faila(blogi, "BlogaiBesimokantys.txt");

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
