import java.util.Scanner;
import java.io.*;

public class scode
{

public static int total;

public static int cut(String s)
{
	if (s.length() < 3)
		return 0;
	int sum = 0;
	for (int i = 1; i <= s.length()-1; i++)
	{
		String sA = s.substring(0, i);
		String sB = s.substring(i);
		if (Math.abs(sA.length()-sB.length()) == 1)
			sum += count(sA, sB);
	}
	return sum;
}

public static int count(String s1, String s2)
{
	int flag = 0;
	if (s1.length() >= s2.length())
	{
		if ((s1.substring(0, s2.length())).equals(s2) || (s1.substring(s1.length()-s2.length())).equals(s2))
			flag = 1;
	}
	else
	{
		if ((s2.substring(0, s1.length())).equals(s1) || (s2.substring(s2.length()-s1.length())).equals(s1))
			flag = 1;
	}

	if (flag == 1)
	{
		System.out.println(s1 + " "  + s2);
		//return (1+cut(s1)) * (1+cut(s2));
		if (s1.length() >= s2.length())
			return 1 + cut(s1);
		return 1 + cut(s2);
	}
	return 0;
}
public static void main(String[] args)
{
	try
	{
		Scanner input = new Scanner(new File("scode.in"));
		FileWriter out = new FileWriter(new File("scode.out"));
		String str = input.nextLine();
		Integer Total = new Integer(cut(str));
		//System.out.println(Total);
		out.write(Total.toString() + "\n");
		input.close();
		out.close();
	}
	
	catch(IOException e)
	{
		System.out.println("Error!");
	}
		/*String a = "abcd";
		System.out.println(a.substring(2));*/
}
}