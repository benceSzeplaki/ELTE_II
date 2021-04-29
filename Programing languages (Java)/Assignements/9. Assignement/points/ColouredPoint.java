package points;

public class ColouredPoint extends Point
{
    public enum Colour {RED,GREEN,BLUE};
    private Colour colour;

    public ColouredPoint(double init_x, double init_y, Colour color)
    {
        super(init_x, init_y);
        this.colour = color;
    }

    public void setColour(Colour color)
    {
        this.colour = color;
    }

    public Colour getColour()
    {
        return this.colour;
    }
}