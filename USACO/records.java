import java.util.Scanner;
import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Arrays;

public class records
{
public static void main(String[] args)
{
	try
	{
		Scanner input = new Scanner(new File("records.in"));
		FileWriter out = new FileWriter(new File("records.out"));
		int hours = Integer.parseInt(input.nextLine());
		ArrayList <String[]> groups = new ArrayList();
		int[] counts = new int[hours+1];
		int maxCount = 0;
		for (int i = 0; i < hours; i++)
		{
			String line = input.nextLine();
			StringTokenizer tokenizer = new StringTokenizer(line);
			String[] gr = new String[3];
			gr[0] = tokenizer.nextToken();
			gr[1] = tokenizer.nextToken();
			gr[2] = tokenizer.nextToken();
			Arrays.sort(gr);
			int flag = 0;
			for (int j = 0; j < groups.size(); j++)
			{
				if (gr[0].equals(groups.get(j)[0]) && gr[1].equals(groups.get(j)[1]) && gr[2].equals(groups.get(j)[2]))
				{
					counts[j]++;
					flag = 1;
					if (counts[j] > maxCount)
						maxCount = counts[j];
					break;
				}
			}
			if (flag == 0)
			{
				groups.add(gr);
				counts[groups.size()-1] = 1;
			}
		}
		/*for (int k = 0; k < groups.size(); k++)
		{
			System.out.println(groups.get(k)[0] + " " + groups.get(k)[1] + " " + groups.get(k)[2]);
		}*/
		out.write(maxCount + "\n");
		
		input.close();
		out.close();
	}
	
	catch (IOException e)
	{
		System.out.println("Error!");
	}

}
}