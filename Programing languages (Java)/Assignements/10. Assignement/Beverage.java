public class Beverage
{
    private String name;
    private int legalAge;

    public Beverage(String innit_name, int innit_legalAge)
    {
        if(innit_name == ""  || innit_legalAge < 0) throw new IllegalArgumentException();
        this.name = innit_name;
        this.legalAge = innit_legalAge;
    }

    public String getName()
    {
        return this.name;
    }

    public int getLegalAge()
    {
        return this.legalAge;
    }
}