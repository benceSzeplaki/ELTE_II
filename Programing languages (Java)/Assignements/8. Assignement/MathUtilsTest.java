/* 
    Fordítás és futtatás:
    javac -cp .;junit-4.12.jar;hamcrest-core-1.3.jar MathUtilsTest.java
    java -cp .;junit-4.12.jar;hamcrest-core-1.3.jar org.junit.runner.JUnitCore MathUtilsTest
*/

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;
import org.junit.Test;

public class MathUtilsTest
{
    @Test
    public void incGoodNumber()
    {
        assertEquals(2 , MathUtils.Increment(1));
    }

    @Test
    public void incLowestNumberPossible()
    {
        assertEquals(-2147483647 , MathUtils.Increment(-2147483648));
    }

    @Test
    public void incLargestNumberPossible()
    {
        assertEquals(2147483647 , MathUtils.Increment(2147483646));
    }

    @Test(expected = IllegalArgumentException.class)
    public void incTooLargeNumber()
    {
        MathUtils.Increment(2147483647);
    }
}