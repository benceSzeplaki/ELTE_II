# 📓 Assignement #5

Javítsuk ki a HIBÁS programo(ka)t!
  
Készítsünk a util csomagon belül egy IntVector osztályt, amely egészek sorozatát ábrázolja!  
Legyen egy tömb adattagja, amely a sorozatot tárolja. Adjunk az osztályhoz egy konstruktort,  
amely egy egészekből álló tömböt vár paraméterül (ennek tartalmát másolja le). Vegyünk fel egy add() metódust,  
mely a sorozat minden eleméhez hozzáad egy paraméterül kapott egész számot! Készítsünk egy toString() metódust is,  
mely felsorolja a számokat szóközzel elválasztva (használjon StringBuilder-t). Például: [1 2 3]  

util/IntVector.java:  
  
package util;  
  
public class IntVector   
{  
    int[] numbers;  
  
    IntVector(int[] numbers)   
    {  
        numbers = numbers;  
    }  
  
    public void add(int n)  
    {  
        for (int i = 0; i < numbers.length-1; i++)  
            numbers[i] += n;  
    }  
  
    public String toString()   
    {  
        return Arrays.toString(numbers);  
    }  
}  
IntVectorDemo.java:  
  
class IntVectorDemo   
{  
    public static void main(String[] args)   
    {  
        int[] ns = new int{1,2,3};  
        IntVector v = new IntVector(ns);  
        IntVector v2 = new IntVector(ns);  
  
        System.out.println(new int{1,2,3});  
        System.out.println(v);  
        System.out.println(v2);  
  
        System.out.println("v.add(1);");  
        v.add(1);  
        System.out.println(v);  
        System.out.println(v2);   
  
        System.out.println("ns[0] = 10;");  
        ns[0] = 10;  
        System.out.println(v);  
        System.out.println(v2);  
    }  
}  
