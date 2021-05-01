//(c) feladat

package list;

public class NamedIntArrayList extends IntArrayList
{
    private String name;

    public NamedIntArrayList(String setName, int max)
    {
        super(max);
        name = new String(setName);
    }

    public NamedIntArrayList(String setName, int[] intArray)
    {
        super(intArray);
        name = new String(setName);
    }

    public String getName()
    {
        return name;
    }

    @Override
    public String toString()
    {
        return "Name of this list: "+ this.getName()+ System.lineSeparator() + "Contains: " + list.toString();
    }
}
