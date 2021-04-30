# 📓 Assignement #10

Egy kávéház működését fogjuk szimulálni. A pultos (Bartender) szolgálja ki a vendégeket (Guest).  
Vendégekből két típust különböztetünk meg, mindketten a Guest osztályból származnak: Adult és Minor.  
A pultos különböző italokat (Beverage) adhat el a vendégeknek. Először valósítsa meg a Beverage osztályt, ami az alábbi mezőkkel és metódusokkal rendelkezik:  
  
 - name, egy nemüres sztring  
 - legalAge, pozitív egész   
   
Írjon egy konstruktort, amely minden tagváltozó értékét megkapja és beállítja azokat.  
A konstruktor dobjon IllegalArgumentException-t, ha valamelyik argumentum nem megfelelő. A tagváltozókhoz írjon gettereket.  

A Guest osztálynak két protected láthatóságú adattagja van:

 - szöveg típusú név (name)  
 - int típusú kor (age)  

Mindkét adattag legyen elérhető gettereken keresztül.  
  
A pultos rendelkezzen egy nyilvános metódussal:  
  
order(Beverage, Guest), amely boolean értékű változóval tér vissza.  
Akkor térjen vissza hamissal, ha az ital legalAge attribútuma 18 és a Guest nem Adult  
