package circles;

import points.ColouredPoint;
import points.ColouredPoint.Colour;

public class ColouredCircle extends Circle 
{
    private ColouredPoint.Colour colour;
    
    public ColouredCircle(ColouredPoint cp, double init_radius)
    {
        super(cp , init_radius);
        this.colour = cp.getColour();
    }

    public void setCircleColour(Colour color)
    {
        this.colour = color;
    }

    public Colour getCircelColour()
    {
        return this.colour;
    }
}
