public class MathUtils
{
    static int Increment(int num)
    {
        if(num < 2147483647)
        {
            num++;
        }
        else throw new IllegalArgumentException();
        return num;
    }
}