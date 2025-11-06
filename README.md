# Objektinis-programavimas

Releasai:

1. v.pradine - sudaro, tik rankinis studentų duomenų įvedimas main.cpp faile;
2. v.pradine2 - pridėta galimybė generuoti atsitiktinius pažymius kiekvienam įvedamam studentui;
3. v0.1 - pridėta galimybė skaityti duomenis iš failo;
4. v0.2 - projektas išskaidytas į main.cpp, mylib.cpp ir main.h failus, pridėta galimybė generuoti failus, o skaitant iš failo studentus suskirstyti į dvi grupes, bei juo išrikiuoti pagal pasirinkta parametrą;
5. v0.3 - testuotas ir README.md faile aprašytas programos veikimas naudojant std::vector ir std::list konteinerius;
6. v1.0 - testuotas ir README.md faile aprašytas programos veikimas pagal 3 studentų suskirstymo į dvi grupes strategijas.


Diegimo ir paleidimo instrukcija:

1. Būtinos sąlygos:
	1) turėti c++ kompiliatorių ir cmake programą (versija nemažesnė nei 3.20) įdiegta;
	2) aplanke ,,1-uzd" turėtų būti aplankai ,,src", ,,Include" ir tekstinis failas ,,CMakeLists.txt";
2. Diegimo žingniai:
	1) aplanką 1-uzd atidaryti terminale;
	2) paleisti komandą ,,cmake .\CMakeLists.txt";
	3) paleisti komandą ,,cmake --install .";
	4) paleisti komandą ,,cmake --build .";
3. Paleidimas pirmas variantas:
	1) per terminala atidaryti ,,1-uzd" aplanke atsiradusi aplanką ,,Debug" paleidžiant komandą ,,cd .\Debug\";
	2) paleisti komandą ,,.\1-uzd.exe";
4. Paleidimas antras variantas:
	1) atidaryti ,,1-uzd" aplanke atsiradusi aplanką ,,Debug" naudojant failų naršyklę;
	2) paleisti programą "1-uzd";	

Naudojimo instrukcija:

1. Paleisti programa;
2. Pasirinkti ar duomenis skaityti ar generuoti failus su duomenimis:
	1) įvedus S pasirenkama skaityti duomenis;
		3. Pasirinkti ar duomenis skaityti iš failo ar įvesti juo ranka:
			1) įvedus T pasirenkama skaityti duomenis iš failo, kurie bus apdoroti ir išvedami į du skirtingus failus pagal studento galutini pažymį:,,GeraiBesimokantis" ir ,,BlogaiBesimokantys";
				4. Pasirinkti pagal kokį parametrą bus surūšiuoti duomenis išvedus juos į du skirtingus failus:
					1) įvedus G duomenys bus surūšiuoti pagal studentų galutinius pažymius;
					2) įvedus V duomenys bus surūšiuoti pagal studentų vardus;
					3) įvedus P duomenys bus surūšiuoti pagal studentų pavardes;
				5. Ekrane pasirodo programos veikimo etapų trukmės ir yra sukuriami failai ,,GeraiBesimokantis" ir ,,BlogaiBesimokantys";
			2) įvedus N pasirenkama duomenis vesti ranka;
				4. Įvedamas skaičius studentų, kurių duomenis norima įvesti;
				5. Kartojama įvesto studentų skaičiaus kartų:
				6. įvesti studento vardas;
				7. įvesti studento pavardė;
				8. pasirinkti ar studento pažymius vesti vienas po kito ar generuoti:
					1) įvedus V pasirenkama vesti pažymius vienas po kito:
						9. įvedinėjami pažymiai, įvedus 0 nustojama vesti;
						10. įvesti studento egzamino pažymį;
					2) įvedus G pasirenkama generuoti atsitiktinius pažymius;
				11. žingsniai 6-10 kartojami įvesto studentų skaičiau kartų;
				12. pasirinkti ar studentų suvestinės lentelėje bus studentų galutinis rezultatas skaičiuojamas pagal pažymių vidurkį, medianą ar abu;
					1) įvedus V lentelėje pasirodys rezultatas pagal vidurkį;
					2) įvedus M lentelėje pasirodys rezultatas pagal medianą;
					3) įvedus A lentelėje pasirodys rezultatai pagal abu skaičius;
				12. Išvedama studentų suvestinė su studentų vardais, pavardėmis ir pasirinktų galutiniu pažymiu; 
	2) įvedus G pasirenkama generuoti failus su duomenimis;
		3. Sugeneruojami failai su 1000, 10000, 100000, 1000000 ir 10000000 studentų duomenimis.

Perspėjimas: prieš skaitant duomenys iš failo, juos reikia sugeneruoti;


Testavimo sistemos parametrai:

* Intel(R) Core(TM) i5-9300HF CPU @ 2.40GHz (2.40 GHz);
* 8 GB RAM;
* SSD.


Testavimas:

1 strategija: Bendro konteinerio skaidymas į du to paties tipo konteinerius:

1) Naudojant std::vector konteinerį trukmės vidurkiai:



|Įrašų skaičius | Failo nuskaitymo trukmė | Duomenų surūšiavimo į dvi grupes trukmė | Duomenų įrašymo į failus trukmė | Viso          |

|---------------|-------------------------|-----------------------------------------|---------------------------------|---------------|

|1000           | 0.0022406               | 0.0054886                               | 0.0034225                       | 0.0140551     |

|10000          | 0.0050740               | 0.0399008                               | 0.0222786                       | 0.0706234     |

|100000         | 0.0321228               | 0.3813338                               | 0.193823                        | 0.6098418     |

|1000000        | 0.295096                | 3.952282                                | 1.989768                        | 6.239384      |

|10000000       | 3.094174                | 41.4041                                 | 23.45312                        | 67.95634      |

|---------------|-------------------------|-----------------------------------------|---------------------------------|---------------|

Pazydžiai:

1000 irašų:

<img width="1178" height="447" alt="1 vector 1000" src="https://github.com/user-attachments/assets/8d2a5774-b6db-4c7f-8eb5-db872889018c" />


10000000 irašų:

<img width="1175" height="474" alt="1 vector 10000000" src="https://github.com/user-attachments/assets/8da85035-6654-404b-b21a-327851821637" />






2)Naudojant std::list konteinerį trukmės vidurkiai:



|Įrašų skaičius | Failo nuskaitymo trukmė | Duomenų surūšiavimo į dvi grupes trukmė | Duomenų įrašymo į failus trukmė | Viso          |

|---------------|-------------------------|-----------------------------------------|---------------------------------|---------------|

|1000           | 0.0007699               | 0.0140059                               | 0.0056209                       | 0.0235656     |

|10000          | 0.0058724               | 0.1150582                               | 0.0315591                       | 0.154809      |

|100000         | 0.0339609               | 1.423548                                | 0.3196396                       | 1.779332      |

|1000000        | 0.3819712               | 17.5977                                 | 3.336886                        | 21.31868      |

|10000000       | 3.112888                | 249.0134                                | 58.9834                         | 311.1538      |

|---------------|-------------------------|-----------------------------------------|---------------------------------|---------------|


Pavyzdžiai:

1000 irašų:

<img width="1165" height="474" alt="1 list 1000" src="https://github.com/user-attachments/assets/cf9d4922-8c6e-4cfd-bda3-4dfb05100e1d" />


10000000 irašų:


<img width="1182" height="478" alt="1 list 10000000" src="https://github.com/user-attachments/assets/3921f24c-0858-421d-941b-77289d408177" />



2 strategija:

1) Naudojant std::vector konteinerį trukmės vidurkiai:


|Įrašų skaičius | Failo nuskaitymo trukmė | Duomenų surūšiavimo į dvi grupes trukmė | Duomenų įrašymo į failus trukmė | Viso          |

|---------------|-------------------------|-----------------------------------------|---------------------------------|---------------|

|1000           | 0.0046651               | 0.0061392                               | 0.0036483                       | 0.0178417     |

|10000          | 0.003715                | 0.043608                                | 0.0163485                       | 0.0661079     |

|100000         | 0.0342964               | 0.4261878                               | 0.1408882                       | 0.603858      |

|1000000        | 0.2983952               | 4.44801                                 | 1.489304                        | 6.238178      |

|10000000       | 3.10823                 | 48.75358                                | 15.88736                        | 67.75258      |

|---------------|-------------------------|-----------------------------------------|---------------------------------|---------------|

Pavyzdžiai:

1000 irašų:

<img width="1165" height="460" alt="2 vector 1000" src="https://github.com/user-attachments/assets/dae8ddc2-9163-4f0e-8171-b060803efae6" />

10000000 įrašų:


<img width="1171" height="472" alt="2 vector 10000000" src="https://github.com/user-attachments/assets/1c186eaf-216e-4d7f-ae7a-13bd2281488e" />


 2)Naudojant std::list konteinerį trukmės vidurkiai:



|Įrašų skaičius | Failo nuskaitymo trukmė | Duomenų surūšiavimo į dvi grupes trukmė | Duomenų įrašymo į failus trukmė | Viso          |

|---------------|-------------------------|-----------------------------------------|---------------------------------|---------------|

|1000           | 0.0007948               | 0.0143083                               | 0.0047713                       | 0.0221834     |

|10000          | 0.0039097               | 0.132647                                | 0.0243090                       | 0.1628828     |

|100000         | 0.0331337               | 1.676214                                | 0.238072                        | 1.949878      |

|1000000        | 0.298025                | 21.57356                                | 2.515094                        | 24,3888       |

|10000000       | 3.094384                | 259.643                                 | 34.89186                        | 297.65        |

|---------------|-------------------------|-----------------------------------------|---------------------------------|---------------|

Pavyzdžiai:

1000 irašų:


<img width="1178" height="452" alt="2 list 1000" src="https://github.com/user-attachments/assets/3397673b-4137-4ac5-9f26-a94c8aedabf0" />



10000000 įrašų:


<img width="1176" height="452" alt="2 list 10000000" src="https://github.com/user-attachments/assets/1ff73d0d-5083-4640-9da7-6900372a45d1" />





3 strategija naudojant tik std::vector konteinerį:


|Įrašų skaičius | Failo nuskaitymo trukmė | Duomenų surūšiavimo į dvi grupes trukmė | Duomenų įrašymo į failus trukmė | Viso          |

|---------------|-------------------------|-----------------------------------------|---------------------------------|---------------|

|1000           | 0.0007766               | 0.0045559                               | 0.0110817                       | 0,0181108     |

|10000          | 0.0042033               | 0.0369678                               | 0.0299963                       | 0.0584091     |

|100000         | 0.0305568               | 0.3589148                               | 0.1392758                       | 0.5306948     |

|1000000        | 0.3037752               | 3.949376                                | 1.413016                        | 5.6665        |

|10000000       | 3.247136                | 42.29478                                | 15.86184                        | 61.40678      |

|---------------|-------------------------|-----------------------------------------|---------------------------------|---------------|


Pavyzdžiai:

1000 įrašų:


<img width="1167" height="462" alt="3 vector 1000" src="https://github.com/user-attachments/assets/940b89d7-6d6d-459d-b0a6-024188120385" />


10000000 įrašų:


<img width="1197" height="466" alt="3 vector 10000000" src="https://github.com/user-attachments/assets/944cdeff-4132-46ba-98f1-76addf1e689b" />



Testavimo išvados:

1. Programa veikia sparčiau naudojant std::vector konteinerį negu std::list;
2. 3 strategija, kai naudojami tam tikri konteinerių metodai, šiek tiek spartesnė už kitas strategijas;
3. 1 ir 2 strategijų spartos žymiai nesiskiria.




