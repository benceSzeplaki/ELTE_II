public class Guest 
{
    private String name;
    private int age;

    public Guest(String innit_name, int innit_age)
    {
        this.name = innit_name;
        this.age = innit_age;
    }

    public String getName()
    {
        return this.name;
    }

    public int getAge()
    {
        return this.age;
    }
}