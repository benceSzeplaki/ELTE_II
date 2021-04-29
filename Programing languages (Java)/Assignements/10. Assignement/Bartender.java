public class Bartender 
{
    public boolean order(Beverage b, Adult a)
    {
        return true;
    }

    public boolean order(Beverage b, Minor m)
    {
        if(b.getLegalAge() == 18) { return false; }
        else { return true; }
    }
}