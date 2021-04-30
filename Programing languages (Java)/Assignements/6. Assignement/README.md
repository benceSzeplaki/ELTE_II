# 📓 Assignement #6  

Egy szöveges fájl minden sorában található egy egész szám, majd szóközzel elválasztva egész számok vesszővel elválasztott listája.  
  
Olvassa be a fájl sorait, majd döntse el, hogy az egész számok listájában van-e két olyan egész szám, amelyek összege az első oszlopban lévő szám.  
  
Az eredményeket írja ki egy szöveges fájlba: soronként a szám, amely összeg-felbontását keressük,  
majd szóközzel elválasztva a két listabeli szám, amelyek összege a vizsgált szám; ha nincs a listában két megfelelő egész, akkor a "none" sztringet írja a szám mellé.  
  
Például:  
  
in.txt:  

    7 2,5,-7,6,9  
    -2 2,5,-7,6,9  
    12 2,5,-7,6,9  

out.txt:  
  
    7 2 5  
    -2 5 -7  
    12 none  
  
Fordítás: javac fileInOut/oszlop1.java  
Futtatás: java fileInOut/oszlop1
