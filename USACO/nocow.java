import java.util.Scanner;
import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;
import java.util.Arrays;

public class nocow
{
	static int ind2 = 0;
public static void generate(String[] list, String current, ArrayList<String>[] kinds, String[] notPresent, int index)
{
	if (index == kinds.length)
	{
		int flag2 = 0;
		for (String str : notPresent)
		{
			if (str.equals(current))
			{
				flag2 = 1;
				break;
			}
		}
		if (flag2 == 0)
		{
			//System.out.println(current);
			list[ind2] = current;
			ind2++;
		}
	}
	else
	{
		for (int c1 = 0; c1 < kinds[index].size(); c1++)
		{
			if (index == 0)
			{
				current = kinds[index].get(c1);
				generate(list, current, kinds, notPresent, index+1);
			}
			else
			{
				generate(list, current + " " + kinds[index].get(c1), kinds, notPresent, index+1);
			}
		}
	}
}
public static void main(String[] args)
{
	try
	{
		Scanner input = new Scanner(new File("nocow.in"));
		FileWriter out = new FileWriter(new File("nocow.out"));
		String line1 = input.nextLine();
		int N = Integer.parseInt(line1.split(" ")[0]);
		int K = Integer.parseInt(line1.split(" ")[1]);
		String line2 = input.nextLine();
		String[] firstInLineAdjs = line2.split(" ");
		ArrayList<String>[] types = new ArrayList[firstInLineAdjs.length-5];
		String[] absentCows = new String[N];
		absentCows[0] = "";
		for (int a = 4; a < firstInLineAdjs.length-1; a++)
		{
			types[a-4] = new ArrayList();
			types[a-4].add(firstInLineAdjs[a]);
			if (a < firstInLineAdjs.length-2)
				absentCows[0] += types[a-4].get(0) + " ";
			else if (a == firstInLineAdjs.length-2)
				absentCows[0] += types[a-4].get(0);
		}
		
		for (int i = 1; i < N; i++)
		{
			String line = input.nextLine();
			String[] lineAdjs = line.split(" ");
			absentCows[i] = "";
			for (int ii = 4; ii < firstInLineAdjs.length-2; ii++)
				absentCows[i] += lineAdjs[ii] + " ";
			absentCows[i] += lineAdjs[firstInLineAdjs.length-2];
			//System.out.println(absentCows[i]);
			for (int aa = 4; aa < firstInLineAdjs.length-1; aa++)
			{
				int flag = 0;
				for (String el : types[aa-4])
				{
					if (el.equals(lineAdjs[aa]))
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
					types[aa-4].add(lineAdjs[aa]);
			}
		}
	
		int totalPoss = 1;
		for (int r = 0; r < types.length; r++)
		{
			totalPoss *= types[r].size();
			//System.out.println(r + " " + types[r].size());
		}
		String[] presentCows = new String[totalPoss-absentCows.length];
		generate(presentCows, "", types, absentCows, 0);
		//for (String sstr : presentCows)
			//System.out.println(sstr);
		Arrays.sort(presentCows);
		out.write(presentCows[K-1] + "\n");
	
		input.close();
		out.close();
	}
	catch (IOException e)
	{
		System.out.println("Error!");
	}
}

}