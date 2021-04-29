import auto.*;
import java.io.*;

class Main
{   
    public static void main(String[] args) 
    {
        File input = new File("input.txt");
        try
        {
            BufferedReader brNumber = new BufferedReader(new FileReader(input));
            int numberOfLines = 0;
            while ((brNumber.readLine()) != null)
            {
                numberOfLines++;
            }
            brNumber.close();
            Auto[] arr = new Auto[numberOfLines];
            int i = 0;
            String line;
            BufferedReader br = new BufferedReader(new FileReader(input));
            while ((line = br.readLine()) != null)
            {
                arr[i] = new Auto();
                arr[i].separator(line);
                i++;
            }
            br.close();
            for(int j = 0; j < i; j++)
            {
                System.out.println(arr[j].toStringAuto());
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