# 📓 Exam #1

A kitűzött feladatra készítsen objektum elvű megoldást C++ nyelven az alábbi szempontok alapján:  
- programjának ciklusai tanult programozási tételekből származzanak  
- használjon osztályt a szöveges állomány olvasásához  
- a szöveges állományt csak egyszer nyithatja meg olvasásra, és nem használhat a szöveges állomány sorainak számától függő méretű programváltozót  
- programja az eredményt felhasználóbarát módon jelenítse meg  
- programja ne csak az érvényes tesztesetekre működjön helyesen, hanem az üres fájl, és a nem létező fájl esetét is kezelje le  

Megfelelt szint (közepes):  
A Tappancs Kutyamenhely az örökbefogadások adatait egy szöveges állományban tárolja.  
Az állomány minden sora egy dátummal kezdődik (EEEE.HH.NN formátumú sztring), amelyet egy vagy több örökbefogadás adatai követnek.  
Egy örökbefogadás az örökbefogadó nevéből (két sztring, szóközzel elválasztva), a kutya fajtájából, a kutya nevéből (mindkettő szóköz nélküli sztring),  
és a kutya életkorából (pozitív egész) áll. Egy soron belül az adatokat szóközök és/vagy tabulátorjelek választják el.  
Feltehetjük, hogy az állomány sorai a megadott formában vannak, ugyanaz a dátum nem szerepelhet egynél több sorban.  
  
Példa az input fájl soraira:  
"2021.04.07 Techno Kolos pumi Pamacs 2 Am Erika labrador Mancs 1"  
"2021.04.08 Metall Ica vizsla Foltos 4"  
  
Adjon meg egy olyan napot, amelyre igaz, hogy az aznap örökbefogadott összes labrador legalább 2 éves!  
  
Kiváló szint (jeles):   
Tekintsük az előző feladatban szereplő szöveges állományt az alábbi módosításokkal.  
A kiskutyákért felelős államtitkár indítványozására a Tappancs Kutyamenhely ötletét alapul véve létrehoztak  
egy szöveges állományt, melyben az ország összes kutyamenhelyének örökbefogadásait tartják számon.  
A menhelyek beazonosíthatósága miatt a szöveges állomány sorai először a menhely azonosítóját, utána egy dátumot,  
majd az aznapi örökbefogadások adatait tartalmazzák. Ugyanazon menhelyhez tartozó örökbefogadások így több sorban helyezkednek el,   
de egy dátumhoz tartozó örökbefogadások adatai egyetlen sorban, továbbá feltehetjük, hogy az állomány sorai a menhelyek azonosítói szerint rendezettek.  
  
Példa az input fájl soraira:  
TAPP 2021.04.07 Techno Kolos pumi Pamacs 2 Am Erika labrador Mancs 1  
TAPP 2021.04.08 Metall Ica vizsla Foltos 4  
KUTY 2021.04.07 Ipsz Ilonka pitbull Cuki 3 Wincs Eszter csivava Rex 5  
  
Írja ki azoknak a menhelyeknek az azonosítóját, amelyekre igaz, hogy minden nap, amikor onnan fogadtak örökbe, legalább 2 kutyát fogadtak örökbe.  
  
