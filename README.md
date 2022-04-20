# FZ-Pirma-uzduotis
Fausto Žiliajevo githubas
https://github.com/FaustasZil/FZ-Pirma-uzduotis/tree/v0.5-list  

2022-02-20: Įkelta pradinė v0.1 versija  
2022-02-21: Pridetas pasirinkimas tarp medianos ir vidurkio, nd duomenys saugomi vektoriuje  
2022-02-21: Pridetas random pažymių generavimas  
2022-03-01: User experience, bei žmonės dabar irgi laikomi vektoriuje  
2022-03-01: Apsauga  
2022-03-06: Pradine v0.2 versija  
2022-03-07: v0.2 sort + formatavimas  
2022-03-07: v0.3 su failu handlinimu  
2022-03-20: v0.4 pradine versija  
2022-03-22: Failu dalinimo bei uztrukto laiko pataisymas (v0.4.1)  
2022-03-29: v0.5 list ir deque versijos 
2022-04-18: Aptvarkyti for loopai vektoriu ir deque versijom  
2022-04-19: v1.0 versija su abiem strategijom  
  
Naudojimo instrukcijos:  
1. Atsidarius terminala root folderije, ivesti "make", spausti Enter  
2. Susikompiliavus programai, paleisti .exe faila  
  
skaiciavimai imti pagal mediana  
  
v1.0 Pirma strategija:
  
vector 
  
nuskaitymas(1m, 10m): 2,56s, 24,35s  
dalinimas(1m, 10m): 0,19s, 1,99s  
rusiavimas(1m, 10m): 3,82s, 50,32s  
       laimingu rasymas(1m, 10m): 0,76s, 8,35s  
       nelaimingu rasymas(1m, 10m): 0,53s, 5,84s  
       programa(1m, 10m): 7,86s, 90,85s  
  
list   
  
nuskaitymas(1m, 10m): 2,37s, 24,62s  
       dalinimas(1m, 10m): 0,24s, 2,47s  
       rusiavimas(1m, 10m): 1,67s, 21,37s  
       laimingu rasymas(1m, 10m): 0,92s, 10,21s  
       nelaimingu rasymas(1m, 10m): 0,69s, 6,56s  
       programa(1m, 10m): 5,89s, 65,23s 
  
deque  
  
nuskaitymas(1m, 10m): 2,52s, 25,74s  
       dalinimas(1m, 10m): 0,19s, 1,87s  
       rusiavimas(1m, 10m): 4,54s, 57,05s  
       laimingu rasymas(1m, 10m): 0,9s, 10,04s  
       nelaimingu rasymas(1m, 10m): 0,62s, 6,66s  
       programa(1m, 10m): 8,77s, 101,36s  
   
v1.0 Antra strategija:
  
vector 
  
  nuskaitymas(1m, 10m): 2,35s, 23,87s  
       dalinimas(1m, 10m): 0,21s, 2,48s  
       rusiavimas(1m, 10m): 3,73s, 45,22s  
       laimingu rasymas(1m, 10m): 0,73s, 7,46s  
       nelaimingu rasymas(1m, 10m): 0,51s, 5,64s  
       programa(1m, 10m): 7,53s, 84,67s 
    
list   
  
nuskaitymas(1m, 10m): 2,41s, 23,95s  
       dalinimas(1m, 10m): 0,35s, 3,49s  
       rusiavimas(1m, 10m): 1,67s, 19,88s  
       laimingu rasymas(1m, 10m): 0,85s, 8,71s  
       nelaimingu rasymas(1m, 10m): 0,62s, 6,25s  
       programa(1m, 10m): 5,89s, 62,28s  
  
deque  
  
nuskaitymas(1m, 10m): 2,41s, 23,83s  
       dalinimas(1m, 10m): 0,29s, 2,98s  
       rusiavimas(1m, 10m): 4,33s, 49,43s  
       laimingu rasymas(1m, 10m): 0,96s, 8,82s  
       nelaimingu rasymas(1m, 10m): 0,64s, 6,31s  
       programa(1m, 10m): 8,63s, 91,36s  
  
Apibendrinus, 2 strategija efektyvesne, list greiciausias.    

CPU Intel Core i7-8700 3.2GHz  
RAM 16GB DD4 
SSD KINGSTON SA400S37240G  
