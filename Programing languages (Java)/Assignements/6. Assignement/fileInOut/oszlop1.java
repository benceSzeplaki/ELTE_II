package fileInOut;

import java.io.*;
import fileInOut.utils.line;

class oszlop1
{
    public static void main(String[] args) 
    {
        int i = 0;
        File input = new File("in.txt");
        try
        {
            BufferedReader brcounter = new BufferedReader(new FileReader(input));
            String line;
            while ((line = brcounter.readLine()) != null)
            {
                i++;
            }
            brcounter.close();
            String[] lines = new String[i];
            i = 0;
            BufferedReader br = new BufferedReader(new FileReader(input));
            while ((line = br.readLine()) != null)
            {
                lines[i] = line;
                i++;
            }
            br.close();
            String[] solutions = new String[i];
            for(int j = 0; j < i; j++)
            {
                line x = new line(lines[j]);
                solutions[j] = x.searchForNumbers();
                //System.out.println(solutions[j]); Megoldás kiírása konzoloba
            }
            try 
            {
                File output = new File("out.txt");
                if (output.createNewFile()) 
                {}
                else 
                {
                System.out.println("File already exists.");
                }
            } 
            catch (IOException e) 
            {
                System.out.println("An error occurred.");
                e.printStackTrace();
            }
            try 
            {
                FileWriter writeInOut = new FileWriter("out.txt");
                for(int j = 0; j < solutions.length ; j++)
                {
                    if(j == solutions.length - 1)
                    {
                        writeInOut.write(solutions[j]);
                    }
                    else
                    {
                        writeInOut.write(solutions[j]);
                        writeInOut.write(System.getProperty("line.separator"));
                    }     
                }
                writeInOut.close();
            } 
            catch (IOException e) 
            {
                System.out.println("An error occurred.");
                e.printStackTrace();
            }
         }
        catch (FileNotFoundException exc)
        {
            System.out.println("Unable to open file: " + exc.getMessage());
        }
        catch (IOException exc)
        {
            System.out.println("IOException thrown");
        }
    }
}