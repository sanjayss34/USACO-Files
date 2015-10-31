import java.util.Scanner;
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;

public class paint
{
public static void main(String[] args)
{
	try
	{
		Scanner input = new Scanner(new File("paint.in"));
		final int N = Integer.parseInt(input.nextLine());
		ArrayList <Integer> moves = new ArrayList();
		int highest = 0;
		int lowest = 0;
		int place = 0;
		
		for (int i = 0; i < N; i++)
		{
			String line = input.nextLine();
			if (line.split(" ")[1].equals("R"))
			{
				for (int count = 0; count < Integer.parseInt(line.split(" ")[0]); count++)
				{
					moves.add(1);
					place++;
				}
			}
			else
			{
				for (int count3 = 0; count3 < Integer.parseInt(line.split(" ")[0]); count3++)
				{
					moves.add(-1);
					place--;
				}
 			}
 		if (place > highest) highest = place;
		else if (place < lowest) lowest = place;
 		}
 		
 		final int HIGH = highest;
 		final int LOW = Math.abs(lowest);
 		int[][] system = new int[2][LOW+HIGH+2];
 		for (int j = 0; lowest+j <= HIGH; j++)
 		{
 			system[0][j] = lowest+j;
 			system[1][j] = 0;
 		}
 		place = 0;
 		for (int k = 0; k < moves.size(); k++)
 		{
 			//Help on Arrays class from docs.oracle.com
 			system[1][Arrays.binarySearch(system[0], place)]++;
 			place += moves.get(k);
 			if ((k < moves.size() - 2)&&(moves.get(k) * -1 == moves.get(k+1)))
 				system[1][Arrays.binarySearch(system[0], place)]++;
 		}
 			
		int num = 0;
		int sCount = 0;

		for (int count2 = 0; count2 < system[0].length-1; count2++)
		{
			if (system[1][count2] >= 2)
				sCount++;
			else
			{
				if (sCount > 1)
				{
					if (sCount % 2 == 0) num += sCount-1;
					else num += sCount;
				}
				sCount = 0;
			}
			if (count2 == system[0].length-2)
			{
				if (sCount > 1)
				{
					num += sCount-1;
				}
			}
			//System.out.println(system[0][count2] + " " + system[1][count2]);
		}
		try
		{
			BufferedWriter writer = new BufferedWriter(new FileWriter(new File("paint.out")));
			Integer toOut = new Integer(num);
			writer.write(toOut.toString());
			writer.close();
		}
		catch (IOException e2)
		{
			System.out.println("Error!");
		}
	}
	catch (IOException e1)
	{
		System.out.println("Error2!");
	}
}
}