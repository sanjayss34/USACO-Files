import java.util.Scanner;
import java.io.*;
import java.util.StringTokenizer;
import java.util.Arrays;

public class auto
{

public static int searchLower(String p, DictWord[] d)
{
	int lower = 0;
	int upper = d.length-1;
	int mid = (lower+upper)/2;
	while (upper-lower > 1)
	{
		if (p.compareTo(d[mid].word) > 0)
		{
			lower = mid;
			mid = (lower+upper)/2;
		}
		else
		{
			upper = mid;
			mid = (lower+upper)/2;
		}
	}
	if ((d[lower].word).compareTo(p) >= 0)
	{
		//System.out.println(p + " " + d[lower].word);
		return lower;
	}
	//System.out.println(p + " " + d[upper].word);
	return upper;
	//System.out.println(p + " " + d[lower].word);
	/*for (int k = lower; k < d.length; k++)
	{
		if ((d[k].word).substring(0, p.length()).equals(p))
			return k;
	}
	return 0;*/
}

/*public static int searchUpper(String p, DictWord[] d)
{
	int lower = 0;
	int upper = d.length-1;
	int mid = (lower+upper)/2;
	while (upper-lower > 1)
	{
		if (p.compareTo(d[mid].word) < 0)
		{
			upper = mid;
			mid = (lower+upper)/2;
		}
		else
		{
			lower = mid;
			mid = (lower+upper)/2;
		}
	}
	/*if ((d[upper].word).compareTo(p) <= 0)
	{
		System.out.println(p + " " + d[upper].word);
		return upper;
	}
	System.out.println(p + " " + d[lower].word);
	return lower;
	System.out.println(p + " " + d[upper].word);
	for (int k = upper; k >= 0; k--)
	{
		if ((d[k].word).substring(0, p.length()).equals(p))
			return k;
	}
	
	return d.length;
}*/

public static void main(String[] args)
{
	try
	{
		Scanner input = new Scanner(new File("auto.in"));
		FileWriter out = new FileWriter(new File("auto.out"));
		StringTokenizer tokenizer = new StringTokenizer(input.nextLine());
		int W = Integer.parseInt(tokenizer.nextToken());
		int N = Integer.parseInt(tokenizer.nextToken());
		DictWord[] dict = new DictWord[W];
		for (int i = 0; i < W; i++)
		{
			dict[i] = new DictWord();
			dict[i].word = input.nextLine();
			dict[i].index = i;
		}
		Arrays.sort(dict);
		//System.out.println(dict[0].word + " " + dict[W-1].word);
		
		for (int j = 0; j < N; j++)
		{
			StringTokenizer tokenizer2 = new StringTokenizer(input.nextLine());
			int ind = Integer.parseInt(tokenizer2.nextToken());
			String partial = tokenizer2.nextToken();
			int a = searchLower(partial, dict);
			//int b = searchUpper(partial, dict);
			if (a+ind-1 >= dict.length)
			{
				out.write("-1\n");
				continue;
			}
			String check = dict[a+ind-1].word;
			//System.out.println(partial + " " + check.substring(0, partial.length()));
			if (check.substring(0, partial.length()).equals(partial))
			{
				int value = dict[a+ind-1].index+1;
				Integer val = new Integer(value);
				out.write(val.toString() + "\n");
			}
			else
				out.write("-1\n");
		}
		
		input.close();
		out.close();
	}
	
	catch (IOException e)
	{
		System.out.println("Error!");
	}
}
}

class DictWord implements Comparable
{
	String word;
	int index;
	public int compareTo(Object dw)
	{
		DictWord dw2 = (DictWord) dw;
		return word.compareTo(dw2.word);
	}
}