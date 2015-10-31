import java.util.Scanner;
import java.io.*;
import java.util.StringTokenizer;
import java.util.Arrays;
import java.util.ArrayList;

//Referenced http://docs.oracle.com/javase/7/docs/api/java/util/Arrays.html

public class code
{
	static ArrayList <int[]> lists;
	static int count;
static void fill(int[] sequence, int pos, int[] par, String str, int ind)
{
	sequence[pos] = Integer.parseInt(str.substring(ind, ind+1)) + 1;
	if (ind < 4)
		fill(sequence, par[pos], par, str, ind+1);
}

static void generate(int[] list, int[] fixed, int ind)
{
	if (fixed[ind] != 0)
	{
		list[ind] = fixed[ind];
		if (ind == list.length-1)
		{
			System.out.println(++count);
			int flag = 1;
			for (int k = 0; k < lists.size(); k++)
			{
				/*if (Arrays.equals(list, lists.get(k)))
					{
						flag = 1;
						break;
					}*/
					flag = 0;
					for(int k2 = 0; k2 < list.length; k2++)
					{
						if (list[k2] != lists.get(k)[k2])
						{
							flag = 1;
							break;
						}
					}
					if (flag == 0)
						break;
			}
			if (flag == 1)
				lists.add(list);
		}
		else
			generate(list, fixed, ind+1);
	}
	else
	{
		for (int a = 1; a <= 10; a++)
		{
			list[ind] = a;
			if (ind == list.length - 1)
			{
				System.out.println(++count);
				int flag = 1;
				for (int k = 0; k < lists.size(); k++)
				{
					/*if (Arrays.equals(list, lists.get(k)))
					{
						flag = 1;
						break;
					}*/
					flag = 0;
					for(int k2 = 0; k2 < list.length; k2++)
					{
						if (list[k2] != lists.get(k)[k2])
						{
							flag = 1;
							break;
						}
					}
					if (flag == 0)
						break;
				}
				if (flag == 1)
					lists.add(list);
			}
			else
				generate(list, fixed, ind+1);
		}
	}
}
public static void main(String[] args)
{
	try
	{
		Scanner input = new Scanner(new File("code.in"));
		FileWriter out = new FileWriter(new File("code.out"));
		String firstLine = input.nextLine();
		StringTokenizer tokenizer = new StringTokenizer(firstLine);
		int N = Integer.parseInt(tokenizer.nextToken());
		int M = Integer.parseInt(tokenizer.nextToken());
		int[] parents = new int[N];
		parents[0] = -1;
		for (int i = 1; i < N; i++)
			parents[i] = Integer.parseInt(input.nextLine());
		lists = new ArrayList();
		count = 0;
		for (int j = 0; j < M; j++)
		{
			String line = input.nextLine();
			StringTokenizer tokenizer2 = new StringTokenizer(line);
			int start = Integer.parseInt(tokenizer2.nextToken());
			String digits = tokenizer2.nextToken();
			int[] s = new int[N];
			//System.out.println(s[0]);
			fill(s, start, parents, digits, 0);
			int[] newList = new int[N];
			generate(newList, s, 0);
		}
		Integer answer = new Integer(lists.size());
		for (int ii = 0; ii < N; ii++)
			System.out.print(lists.get(1)[ii] + " ");
		System.out.print("\n");
		out.write(answer.toString() + "\n");
		/*String name = "name";
		System.out.println(name.substring(0, 1));*/
		
		input.close();
		out.close();
	}
	catch(IOException e)
	{
		System.out.println("Error!");
	}
}
}