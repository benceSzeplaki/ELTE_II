package auto;

import auto.utils.Color;

public class Auto 
{
    String licensePlate;
    Color color;
    int maxSpeed;
    int counter  = 0;

    public static Color stringToColor(String color)
    {
        if(color == "RED")
        {
            return Color.RED;
        }
        else if(color == "GREEN")
        {
            return Color.GREEN;
        }
        else 
        {
            return Color.BLUE;
        }
    }

    public Auto(String lp, Color c, int maxS)
    {
        this.licensePlate = lp;
        this.maxSpeed = maxS;
        this.color = c;
        counter++;
    }

    public void separator(String line)
    {
        String[] parts = line.split(",");
        this.licensePlate = parts[0];
        this.color = stringToColor(parts[1]);
        this.maxSpeed = Integer.parseInt(parts[2]);
    }

    public Auto()
    {
        this.licensePlate = "AAA - 000";
        this.color = Color.BLUE;
        this.maxSpeed  = 120;
        counter++;
    }

    boolean isXFasterThanY(Auto X, Auto Y)
    {
        if(X.maxSpeed > Y.maxSpeed)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    public String toStringAuto()
    {
        StringBuilder auto = new StringBuilder();
        auto.append(this.licensePlate);
        auto.append(", ");
        auto.append(this.color);
        auto.append(", ");
        auto.append(this.maxSpeed);
        return auto.toString();
    }
}
