import java.util.Scanner;
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;

public class baseball
{
public static void main(String[] args)
{
	try
	{
		Scanner input = new Scanner(new File("baseball.in"));
		FileWriter out = new FileWriter(new File("baseball.out"));
		int N = Integer.parseInt(input.nextLine());
		int[] cows = new int[N];
		int maxPos = 0;
		int minPos = 100000001;
		for (int i = 0; i < N; i++)
		{
			cows[i] = Integer.parseInt(input.nextLine());
			if (cows[i] < minPos)
				minPos = cows[i];
			if (cows[i] > maxPos)
				maxPos = cows[i];
		}
		Arrays.sort(cows);
		ArrayList <ArrayList <int[]>> distances = new ArrayList();
		for (int j = 0; j < maxPos-minPos+1; j++)
		{
			distances.add(new ArrayList());
		}
		for (int a = 0; a < N; a++)
		{
			for (int b = a+1; b < N; b++)
			{
				int[] pair = new int[2];
				pair[0] = cows[a];
				pair[1] = cows[b];
				(distances.get(cows[b]-cows[a])).add(pair);
			}
		}
		
		int count = 0;
		
		for (int k = 0; k < distances.size(); k++)
		{
			for (int kk = 0; kk < (distances.get(k)).size(); kk++)
			{
				int dist = (distances.get(k)).get(kk)[1] - (distances.get(k)).get(kk)[0];
				for (int k3 = dist; (k3 <= dist*2) && (k3 < distances.size()); k3++)
				{
					for (int k4 = 0; k4 < (distances.get(k3)).size(); k4++)
					{
						if ((distances.get(k3)).get(k4)[0] == (distances.get(k)).get(kk)[1])
						{
							count++;
							//System.out.println((distances.get(k)).get(kk)[0] + " " + (distances.get(k)).get(kk)[1] + " " + (distances.get(k3)).get(k4)[1]);
						}
					}
				}
			}
		}
		
		out.write(count + "\n");
		
		input.close();
		out.close();
	}
	
	catch (IOException e)
	{
		System.out.println("Error!");
	}

}
}