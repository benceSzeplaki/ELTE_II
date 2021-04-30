package doublevector.utils;

public class DoubleVector
{
    private double[] vector;
    private int length;

    public DoubleVector(int size)
    {
        this.length = size;
        this.vector = new double[size];
        this.clear();
    }

    public DoubleVector(double[] arr)
    {
        this.length = arr.length;
        this.vector = new double[this.length];
        for(int i = 0; i < this.length; i++)
        {
            this.vector[i] = arr[i];
        }
    }

    public DoubleVector add(DoubleVector newDV)
    {
        if(this.length != newDV.length) throw new IllegalArgumentException();
        DoubleVector ret = new DoubleVector(this.length);
        for(int i = 0; i < this.length; i++)
        {
            ret.vector[i] = this.vector[i] + newDV.vector[i]; 
        }
        return ret;
    }

    public DoubleVector subtarct(DoubleVector newDV)
    {
        if(this.length != newDV.length) throw new IllegalArgumentException();
        DoubleVector ret = new DoubleVector(this.length);
        for(int i = 0; i < this.length; i++)
        {
            ret.vector[i] = this.vector[i] - newDV.vector[i]; 
        }
        return ret;
    }

    public double scalarProduct(DoubleVector newDV)
    {
        if(this.length != newDV.length) throw new IllegalArgumentException();
        double ret = 0.0;
        for(int i = 0; i < this.length; i++)
        {
            ret = ret + this.vector[i] * newDV.vector[i]; 
        }
        return ret;
    }

    public String toString()
    {
        StringBuilder ret = new StringBuilder();
        ret.append("[");
        for(int i = 0; i < this.length; i++)
        {
            if(i + 1 == this.length)
            {
                ret.append(this.vector[i] + "]");
            }
            else
            {
                ret.append(this.vector[i] + ",");
            }
        }
        return ret.toString();
    }

    public int getVectorLength()
    {
        return this.vector.length;
    }

    public double getVectorAtIndex(int i)
    {
        return this.vector[i];
    }

    public void clear()
    {
        for(int i = 0; i < this.length; i++)
        {
            this.vector[i] = 0.0;
        }
    }
}