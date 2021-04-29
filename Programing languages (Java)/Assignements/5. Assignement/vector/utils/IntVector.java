package vector.utils;

public class IntVector
{
    int[] numbers;

    public IntVector(int[] newNumbers) 
    {
        this.numbers = new int[newNumbers.length];
        for(int i = 0; i < newNumbers.length; i++)
        {
            this.numbers[i] = newNumbers[i];
        }
    }

    public void add(int n) 
    {
        for (int i = 0; i < numbers.length; i++)
        {
            this.numbers[i] += n;
        }
    }

    public String toString() 
    {
        StringBuilder newString = new StringBuilder();
        newString.append("[");
        for(int i = 0; i < numbers.length; i++)
        {
            if(i == numbers.length-1)
            {
                newString.append(numbers[i]);
            }
            else
            {
                newString.append(numbers[i]);
                newString.append(" ");
            }
        }
        newString.append("]");
        return newString.toString();
    }
}