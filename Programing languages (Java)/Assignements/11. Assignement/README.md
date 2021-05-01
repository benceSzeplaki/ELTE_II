# 📓 Assignement #11

Készítsen egész számok listáját reprezentáló adatszerkezetet IntList néven.  
Egy (a) részfeladat keretében készítse el az adatszerkezet hagyományos, tömbökön alapuló megoldását.  
  
- a  
Az IntList osztálynak adattagokban tárolja az IntList aktuális és maximális méretét.  
A maximális méretet a konstruktor állítja be. Az osztálynak legyen egy add() metódusa, amellyel egy int típusú adatot tehetünk be az IntList-be.  
Írjon concat() függvényt, amely egy másik IntList referenciát vár paraméterként, és ha az aktuális IntList elég nagy,  
akkor a végéhez fűzi a paraméterként kapott IntList-ben található egészeket. Ha az IntList nem elég nagy elemek hozzáadásakor,  
akkor a metódusok dobjanak IllegalStateException-t. Írjon toString() metódust, amely vesszővel elválasztva felsorolja az IntList elemeit.  
Amennyiben az IntList üres, akkor a toString() az "empty" sztringet adja vissza. Írjon removeItemsGreaterThan() metódust,  
amely paraméterként egy egész számot (limit) fogad, és az IntList csak azon elemeit hagyja meg, amelyek nem nagyobbak limit-nél.  
  
- b  
A (b) részfeladat ugyanezt az adatszerkezetet valósítsa meg ArrayList vagy LinkedList használatával (milyen előnyei vannak a (b) megoldásnak az (a) megoldással szemben?)  
Az IntList-nek legyen olyan konstruktora, amely egész számok tömbjével inicializálja az újonnan létrehozott IntList-et. Írjon getData() metódust,  
amely visszatér a tárolt számok listájával. Vigyázzon arra, hogy a metódus ne szivárogtassa ki az osztály belső állapotát.  
  
- c  
A (c) részfeladatban származtasson NamedIntList néven osztályt a (b) feladatban megírt IntList osztályból.  
Egy egészek listájának mostantól legyen neve is, a NamedIntList osztály tárolja egy sztring adattagban.  
Írjon konstruktorokat, amelyek egy nevet illetve egy nevet és egy egészeket tartalmazó tömböt fogadnak, majd ezen adatokkal inicializálja a létrejött NamedIntList objektumot.  
Definiálja felül az ősosztálytól örökölt toString() metódust úgy, hogy a sztringben tüntesse fel a NamedIntList nevét is.  
