/*
Make an array A of N strings. Read in each of the names. In this input loop,
sort each name and then add it to A. Keep track of an
array B of minimum letters. B should contain
Strings as well. Similarly make an array C of maximum letters that contains
Strings and is similarly maintained. Also, maintain an array D of objects of type
X and an array E of objects of type Y. Instance data in X should consist of the
minimum letter and the index of the name in A; instance data in Y should consist
of the maximum letter and the index of the name in A. Both classes should contain
compareTo() methods. The compareTo() method for X should basically return
(this.minLetter).compareTo(obj2.minLetter), whereas the other one should have
the obj2.maxLetter first (the opposite). Now sort D and E in their naturally
defined order. Now create array F and array G. Array F should store the minimum
output values, and array G should store the maximum output values. Iterate
through D and E at the same time. When elements at index i and i+1 compare to be
the same, THERES A SIMPLER WAY ... MAYBE!!
*/

/*
Sort the input Strings by ascending letters. Reverse these sorted Strings to get
the reverse order Strings. Make two classes for sorting objects by ascending and
descending order. Add objects to arrays whose types are these two classes; sort
these arrays after the input loop. Loop N times, and at the ith iteration,
replace the ith object in the forward sorted array with the reverse string.
Within this same ith iteration, begin at the location of the ith object (i.e. the
ith index), and traverse forward through the array until the reverse string fits.
This index is 1 less than the latest that the String can be (since indexing for
arrays begins at 0). Use a similar process for the other array. Store the results
for each index of original data.
O(log(N) + N^2) <- NOT GOOD
*/

import java.util.Scanner;
import java.io.*;
import java.util.Arrays;

public class scramble2
{

public int searchY(Y[] yList, int ind)
{
	for (int c = 0; c < yList.length; c++)
	{
		if (yList[c].index == ind)
			return c;
	}
	
	return -1;
}
public static void main(String[] args)
{
	Scanner infile = new Scanner(new File("scramble.in"));
	int N = Integer.parseInt(infile.nextLine());
	String[] sortedA = new String[N];
	String[] sortedD = new String[N];
	PrintWriter outfile = new PrintWriter("scramble.out");
	X[] xArr = new X[N];
	Y[] yArr = new Y[N];
	for (int i = 0; i < N; i++)
	{
		String name = infile.nextLine();
		char[] charName = name.toCharArray();
		Arrays.sort(charName);
		String sortedName = new String(charName);
		sortedA[i] = sortedName;
		xArr[i] = new X();
		xArr[i].index = i;
		xArr[i].s = sortedName;
		yArr[i] = new Y();
		yArr[i].index = i;
		yArr[i].s = sortedName.reverse();
	}
	
	Arrays.sort(xArr);
	Arrays.sort(yArr);
	
	int[] firstResults = new int[N];
	int[] secondResults = new int[N];
	for (int j = 0; j < N; j++)
	{
		int xInd = j;
		String forwardStr = xArr[xInd].s;
		String backwardStr = ((new StringBuilder(forwardStr)).reverse()).toString();
		int flag = 0;
		for (int k1 = j; k1 < N-1; k1++)
		{
			if (k1 == 0)
			{
				if (backwardStr.compareTo(xArr[k1+1]) < 0)
				{
					secondResults[xArr[xInd].index] = k1;
					flag = 1;
					break;
				}
			}
			else
			{
				if ((backwardStr.compareTo(xArr[k1-1]) >= 0) && (backwardStr.compareTo(xArr[k1+1]) < 0))
				{
					secondResults[xArr[xInd].index] = k1;
					flag = 1;
					break;
				}
			}
		}
		
		if (flag == 0)
			secondResults[xArr[xInd].index] = N-1;
		
		flag = 0;		
		for (int k2 = N-1; k2 > 0; k2--)
		{
			if (k2 == N-1)
			{
				if (forwardStr.compareTo(yArr[k2-1]) > 0)
				{
					firstResults[xArr[xInd].index] = k2;
					flag = 1;
					break;
				}
			}
			else
			{
				if ((forwardStr.compareTo(yArr[k2-1]) > 0) (forwardStr.compareTo(yArr[k2+1]) <= 0))
				{
					firstResults[xArr[xInd].index] = k2;
					flag = 1;
					break;
				}
			}
		}
		
		if (flag == 0)
			firstResults[xArr[xInd].index] = 0;
	}
	
	for (int p = 0; p < N; p++)
	{
		outfile.write((new Integer(firstResults[p])).toString() + " " + (new Integer(secondResults[p])).toString() + "\n");
	}
	
	outfile.close();
	infile.close();
}
}

class X implements Comparable<X>
{
	int index;
	String s;
	public int compareTo(X obj2)
	{
		return (this.s).compareTo(obj2.s);
	}
}

class Y implements Comparable<Y>
{
	int index;
	String s;
	public int compareTo(Y obj2)
	{
		return (obj2.s).compareTo(this.s);
	}
}