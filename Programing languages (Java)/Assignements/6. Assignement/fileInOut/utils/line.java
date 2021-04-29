package fileInOut.utils;

public class line 
{
    int sum;
    int[] numbers;

    public line(String line) 
    {
        String[] parts = line.split(" ");
        this.sum = Integer.parseInt(parts[0]);
        String[] numbersString = parts[1].split(",");
        this.numbers = new int[numbersString.length];
        for(int i = 0; i < numbersString.length; i++)
        {
            this.numbers[i] = Integer.parseInt(numbersString[i]);
        }
    }

    public String toStringSolution(int i, int j)
    {
        StringBuilder solution = new StringBuilder();
        if(i >= 0 && j >= 0)
        {
            solution.append(this.sum);
            solution.append(" ");
            solution.append(this.numbers[i]);
            solution.append(" ");
            solution.append(this.numbers[j]);
            return solution.toString();
        }
        else
        {
            solution.append(this.sum);
            solution.append(" none");
            return solution.toString();
        }
    }

    public String searchForNumbers()
    {
        int counter = 0;
        String solution = null;
        for(int i = 0; i < this.numbers.length; i++)
        {
            for(int j = 0; j < this.numbers.length; j++)
            {
                if(this.sum == (this.numbers[i] + this.numbers[j]) && i != j)
                {
                    solution = this.toStringSolution(i, j);
                    counter++;
                }
            }
        }
        if(counter == 0)
        {
            solution = this.toStringSolution(-1, -1);
        }
        return solution;
    }
}
