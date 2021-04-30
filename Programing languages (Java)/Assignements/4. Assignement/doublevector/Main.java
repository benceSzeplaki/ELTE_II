package doublevector;

import doublevector.utils.*;

public class Main 
{
    public static void main(String[] args) 
    {
        double[] a = {1.0,2.0,3.0};
        double[] b = {4.0,5.0,6.0};

        DoubleVector A = new DoubleVector(a);
        DoubleVector B = new DoubleVector(b);
        
        System.out.println(A.toString());
        System.out.println(B.toString());
        
        //add method:
        DoubleVector solution = new DoubleVector(a.length);
        solution = A.add(B);
        boolean isWorking = false;
        if(solution.getVectorAtIndex(0) == 5.0 && solution.getVectorAtIndex(1) == 7.0 && solution.getVectorAtIndex(2) == 9.0)
        {
            isWorking = true;
        }
        if(isWorking)
        {
            System.out.println("OK");
        }
        else
        {
            System.out.println("WRONG");
        }

        //subtract method:
        isWorking = false;
        solution.clear();
        solution = B.subtarct(A);

        if(solution.getVectorAtIndex(0) == 3.0 && solution.getVectorAtIndex(1) == 3.0 && solution.getVectorAtIndex(2) == 3.0)
        {
            isWorking = true;
        }
        if(isWorking)
        {
            System.out.println("OK");
        }
        else
        {
            System.out.println("WRONG");
        }

        //scalarProduct method
        double dotProduct = 0;
        dotProduct = A.scalarProduct(B);
        if(dotProduct == 32.0)
        {
            System.out.println("OK");
        }
        else
        {
            System.out.println("WRONG");
        }
    }
}