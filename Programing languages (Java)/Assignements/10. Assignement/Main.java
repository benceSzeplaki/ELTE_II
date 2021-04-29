
public class Main 
{   
    static void toStringOrder(Bartender Joe, Adult a, Beverage b)
    {
        if(Joe.order(b, a))
        {
            System.out.println("\"The bartender can give " + b.getName() + " to " + a.getName() + "\"");
        }
        else
        {
            System.out.println("\"The bartender can NOT give " + b.getName() + " to " + a.getName() + "\"");
        }
    }

    static void toStringOrder(Bartender Joe, Minor m, Beverage b)
    {
        if(Joe.order(b, m))
        {
            System.out.println("\"The bartender can give " + b.getName() + " to " + m.getName() + "\"");
        }
        else
        {
            System.out.println("\"The bartender can NOT give " + b.getName() + " to " + m.getName() + "\"");
        }
    }
    public static void main(String[] args) 
    {
        Beverage cola = new Beverage("cola", 0);
        Beverage vine = new Beverage("vine", 18);
        Adult dad = new Adult("Bill Smith", 35);
        Minor kid = new Minor("Billy Jr. Smith", 10);
        Bartender Joe = new Bartender();
        toStringOrder(Joe, dad, cola);
        toStringOrder(Joe, kid, cola);
        toStringOrder(Joe, dad, vine);
        toStringOrder(Joe, kid, vine);
    }
}
