import java.io.*;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.ArrayList;

public class ThreeLines
{

public static void main(String[] args)
{
	try
	{
		Scanner input = new Scanner(new File("3lines.in"));
		int N = Integer.parseInt(input.nextLine());
		//System.out.println(N);
		int[][] xs = new int[N][2];
		int[][] ys = new int[N][2];
		ArrayList <Integer> xUsed = new ArrayList();
		//ArrayList <ArrayList <Integer>> xEl = new ArrayList();
		ArrayList <Integer> yUsed = new ArrayList();
		ArrayList <Integer> oneX = new ArrayList();
		ArrayList <Integer> oxinds = new ArrayList();
		ArrayList <Integer> oneY = new ArrayList();
		ArrayList <Integer> oyinds = new ArrayList();
		//ArrayList <ArrayList <Integer>> yEl = new ArrayList();
		for (int i = 0; i < N; i++)
		{
			String line = input.nextLine();
			//System.out.println(line);
			StringTokenizer tokenizer = new StringTokenizer(line);
			xs[i][0] = Integer.parseInt(tokenizer.nextToken());
			ys[i][0] = Integer.parseInt(tokenizer.nextToken());
			int indX = xUsed.indexOf(xs[i][0]);
			if (indX == -1)
			{
				int indY = yUsed.indexOf(ys[i]);
				if (indY == -1)
				{
					indX = oneX.indexOf(xs[i][0]);
					if (indX == -1)
					{
						indY = oneY.indexOf(ys[i][0]);
						if (indY == -1)
						{
							oneX.add(xs[i][0]);
							oxinds.add(i);
							//System.out.println("1 " + ys[i][0]);
							oneY.add(ys[i][0]);
							//System.out.println("2 " + i);
							oyinds.add(i);
						}
						else
						{
							yUsed.add(oneY.get(indY));
							oneY.remove(indY);
							indX = oxinds.indexOf(indY);
							if (indX != -1)
							{
								oneX.remove(indX);
								oxinds.remove(indX);
							}
							//System.out.println(i + " " + indY);
							oyinds.remove(indY);
							
						}
					}
					else
					{
						xUsed.add(oneX.get(indX));
						oneX.remove(indX);
						indY = oyinds.indexOf(indX);
						if (indY != -1)
						{
							oneY.remove(indY);
							oyinds.remove(indY);
						}
						oxinds.remove(indX);
					}
				}
				else
					ys[i][1] = indY;
			}
			else
				xs[i][1] = indX;
		}
		for (int j = 0; j < xUsed.size(); j++)
			System.out.println("x=" + xUsed.get(j));
		for (int k = 0; k < yUsed.size(); k++)
			System.out.println("y=" + yUsed.get(k));
		for (int z = 0; z < oneX.size(); z++)
			System.out.println("x=" + xUsed.get(z));
		for (int y = 0; y < oneY.size(); y++)
			System.out.println("y=" + yUsed.get(y));
		/*int flag = 0;
		if (xUsed.size() + yUsed.size() <= 3)
		{
			flag = 1;
		}
		else
		{
			for (int j = 0; j < xUsed.size(); j++)
			{
				for (int k = 0; k < (xEl.get(j)).size(); k++)
				{
					for (int z = 0; z < yUsed.size(); z++)
					{
						int found = (yEl.get(z)).indexOf((xEl.get(j)).get(k));
						if (found != -1)
						{
							System.out.println(xUsed.get(j));
							if ((xEl.get(j)).size() == 1)
							{
								xUsed.remove(j);
							}
							else if ((yEl.get(z)).size() == 1)
							{
								yUsed.remove(z);
							}
						}
					
						if (xUsed.size() + yUsed.size() <= 3)
						{
							flag = 1;
							break;
						}
					}
					if (flag == 1)
						break;
				}
				if (flag == 1)
					break;
			}
		}*/
		
		try
		{
			BufferedWriter output = new BufferedWriter(new FileWriter(new File("3lines.out")));
			if (xUsed.size() + yUsed.size() <= 3)
				output.write("1\n");
			else
				output.write("0\n");
			output.close();
		}
		catch (IOException e)
		{
			System.out.println("Error!");
		}
		input.close();
	}
	catch (IOException exc)
	{
		System.out.println("Error!");
	}
	
}
}