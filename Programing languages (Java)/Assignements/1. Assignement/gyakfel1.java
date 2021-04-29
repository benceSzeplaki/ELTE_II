//STM3ML Széplaki Bence
//Gyakorló feladat 1. :
class gyakfel1
{
	public static void main(String[] args) 
	{
		int perfectNumber, x = 1, checkNumber = 0;
		perfectNumber = Integer.parseInt(args[0]);
		int[] perfectNumberDiv = new int[perfectNumber];
		for(int i = 1; i <= perfectNumber; i++)
		{
			if(perfectNumber % i == 0)
			{
				perfectNumberDiv[x] = i;
				x++;
			}
		}
		for(int i = 1; i < x; i++)
		{
			if(perfectNumberDiv[i] != perfectNumber)
			{
				checkNumber = checkNumber + perfectNumberDiv[i];
			}
		}
		if(checkNumber == perfectNumber)
		{
			System.out.println(checkNumber + " is a perfect number! :D");
		}
		else
		{
			System.out.println(perfectNumber + " is not a perfect number! Sorry :(");
		}
	}
}