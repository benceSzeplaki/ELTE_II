# 📓 Assignement #3

3. feladatsor / 4. gyakorló feladat:  
- Készítsen egy game.utils.Vehicle osztályt, amellyel egy MultiPlayer-es játék járművét reprezentáljuk. 
- Egy járműnek van modelid-je (int), rendszáma (String), és két színállapota (color1, color2 int típusú adatok). 
- A rendszámhoz készítsen setter és getter metódusokat.
- Készítsen game.Player osztályt, amellyel egy MultiPlayer-es játék felhasználóját (játékos) reprezentálunk.  
Egy játékosnak van neve (String), IP-címe (String), egészségi állapota (int) és lehet járműve (game.utils.Vehicle) (ha nincsen, akkor tároljunk null értéket).  
- A játékos osztályhoz készítsen toString() metódust, amellyel sztringgé alakítjuk egy játékos legfontosabb információit:  
  - nevét  
  - IP-címét  
  - egészségi állapotát  
  - járművének rendszámát (ha van)  
- Készítsen game.Main főprogramot, amelyben példányosít legalább 3 járművet, legalább 2 játékost;  
 az egyik játékoshoz tartozzon jármű; írja ki a képernyőre a játékosok adatait.
