# 📓 Homework #2
Feladat:  
Gyűjtsd ki egy szekvenciális inputfájlban rendezve tárolt egész számok közül azt, hogy melyik számból hány darab található!  
  
Elvárások:  
A feladatot egyedi felsorolóval oldd meg! (first(), next(), stb.) Ezt osztály segítségével, egy különálló fordítási egységben valósítsd meg!  
(Pl.: Legyen egy Enor classod egy enor.cpp -ben.) A feladat megoldásához a felsorolóra általánosított programozási tételeket használjátok!  
  
A feladat értékelése részben automatikus teszteléssel történik, ezért kérem, hogy a programotok az input fájl nevét parancssori argumentumként várja.   
Ezen felül a kimenetet konzolra írjátok, szigorúan a példán látható formátumban. (Azaz: "a szám amit vizsgáltál" szóköz "mennyi volt belőle" újsor)  
Mást ne írjatok ki a konzolra!  
  
Példa az input fájlra:  
0 0 0 1 1 1 1 1 1 3 3 3 6 6  
  
A fordítás ezzel fog történni:  
g++ -std=c++14 -pedantic -Wall *.cpp  
  
Példa a futtatásra:  
a.exe "input.txt"  
  
Példa az outputra:  
0 3  
1 6  
3 3  
6 2 
