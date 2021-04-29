/* 
    Fordítás és futtatás:
    javac -cp .;junit-4.12.jar;hamcrest-core-1.3.jar CircleAndPointTest.java
    java -cp .;junit-4.12.jar;hamcrest-core-1.3.jar org.junit.runner.JUnitCore CircleAndPointTest
*/

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;
import org.junit.Test;

import points.*;
import points.ColouredPoint.Colour;
import circles.*;

public class CircleAndPointTest
{
    @Test
    public void isCPointWorking()
    {
        ColouredPoint cp = new ColouredPoint(0, 1, Colour.BLUE);
        
        //Konstruktor check:
        
        assertEquals(0 ,cp.getX(), 0.001);
        assertEquals(1, cp.getY(), 0.001);
        assertEquals(Colour.BLUE, cp.getColour());
        
        //Színváltás check:
        
        cp.setColour(Colour.RED);
        assertEquals(Colour.RED, cp.getColour());
    }

    @Test
    public void isCCircleWorking()
    {
        ColouredPoint cp = new ColouredPoint(3, 4, Colour.BLUE);
        ColouredCircle cc = new ColouredCircle(cp , 5);
        
        //Konstruktor check:
        
        assertEquals(3, cc.getX(), 0.001);
        assertEquals(4, cc.getY(), 0.001);
        assertEquals(5, cc.getRadius(), 0.001);
        assertEquals(Colour.BLUE, cc.getCircelColour());
        
        //Színváltás check:
        
        cc.setCircleColour(Colour.RED);
        assertEquals(Colour.RED, cc.getCircelColour());
    }
}