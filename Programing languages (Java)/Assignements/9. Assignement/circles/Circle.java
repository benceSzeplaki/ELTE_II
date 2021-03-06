package circles;

import java.io.*;
import points.*;

public class Circle
{
    private double x;
    private double y;
    private double radius;

    public static Circle readFromFile(String filename)
    {
        try
        {
            BufferedReader br = new BufferedReader(new FileReader(filename));
            double x = Double.parseDouble(br.readLine());
            double y = Double.parseDouble(br.readLine());
            double r = Double.parseDouble(br.readLine());
            Circle ret = new Circle(x,y,r);
            br.close();
            return ret;
        }
        catch (FileNotFoundException exc)
        {
            return new Circle(0, 0, 1);
        }
        catch (IOException exc)
        {
            return new Circle(0, 0, 1);
        }
    }

    public void saveToFile(String filename) throws FileNotFoundException
    {
        File output = new File(filename);
        try(PrintWriter pw = new PrintWriter(output))
        {
            pw.println(this.x);
            pw.println(this.y);
            pw.println(this.radius);
        }
    }

    public Circle(double init_x, double init_y, double init_radius)
    {
        x = init_x;
        y = init_y;
        radius = init_radius;
    }

    public Circle(ColouredPoint p, double init_radius)
    {
        this.x = p.getX();
        this.y = p.getY();
        this.radius = init_radius;
    }

    public String toString()
    {
        return x + ", " + y + " r= " + radius;
    }

    public double getX()
    {
        return x;
    }

    public double getY()
    {
        return y;
    }

    public double getRadius()
    {
        return radius;
    }

    public double getArea()
    {
        return Math.pow(radius, 2) * Math.PI;
    }

    public Point getCenter()
    {
        Point center = new Point(x, y);
        return center;
    }
}