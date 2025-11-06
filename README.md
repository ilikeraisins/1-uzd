# Objektinis-programavimas



Sistemos parametrai:

* Intel(R) Core(TM) i5-9300HF CPU @ 2.40GHz (2.40 GHz);
* 8 GB RAM;
* SSD.



Testavimas:



1. Naudojant std::vector konteinerį trukmės vidurkiai:



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

<img width="1178" height="447" alt="vector 1000-1" src="https://github.com/user-attachments/assets/ea386d32-21cf-4fe3-81b0-642aa1384ec1" />

10000000 irašų:

<img width="1175" height="474" alt="vecctor 10000000" src="https://github.com/user-attachments/assets/b6163ef0-777e-49f4-b211-c2f98698793e" />





2.Naudojant std::list konteinerį trukmės vidurkiai:



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

<img width="1165" height="474" alt="list 1000" src="https://github.com/user-attachments/assets/167ed565-c5b3-4909-b242-9b1e8aced9b9" />

10000000 irašų:

<img width="1182" height="478" alt="list 10000000" src="https://github.com/user-attachments/assets/d0a59e69-aae6-4dba-ac6b-3b78b3cf9517" />


