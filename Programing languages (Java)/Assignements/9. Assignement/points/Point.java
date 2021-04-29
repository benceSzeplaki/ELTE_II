package points;

public class Point
{
    private double x, y;

    public Point(double init_x, double init_y)
    {
        this.x = init_x;
        this.y= init_y;
    }

    public double getX() { return x; }
    public double getY() { return y; }
}