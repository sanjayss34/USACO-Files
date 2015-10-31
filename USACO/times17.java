import java.util.Scanner;
import java.io.*;

public class times17
{

public static int multiply(String num1, String num2)
{
	String first1 = num1.substring(0, num1.length()/2);
	String second1 = num1.substring((num1.length()/2));
	String first2 = num2.substring(0, num2.length()/2);
	String second2 = num2.substring((num2.length()/2));
	//System.out.println(first1 + " " + second1 + "\n" + first2 + " " +  second2);
	int len1 = first1.length();
	int len2 = second1.length();
	int len3 = first2.length();
	int len4 = second2.length();
	int prod1 = 0;
	int prod3 = 0;
	if (len1 > 0)
		prod1 = Integer.parseInt(first1, 2);
	if (len3 > 0)
		prod1 += Integer.parseInt(first2, 2);
	if (len2 > 0)
		prod3 = Integer.parseInt(second1, 2);
	if (len4 > 0)
		prod3 += Integer.parseInt(second2, 2);
	int prod2 = prod1 + prod3;
	if ((len1 > 1) || (len3 > 1))
		prod1 = multiply(first1, first2);
	if (len1 + len2 + len3 + len4 > 5)
		prod2 = multiply(Integer.toBinaryString(Integer.parseInt(first1, 2) + Integer.parseInt(second1, 2)), Integer.toBinaryString(Integer.parseInt(first2, 2) + Integer.parseInt(second2, 2)));
	if ((len2 > 1) || (len4 > 1))
		prod3 = multiply(second1, second2);
	int max = 0;
	if ((len1+len2) > (len3+len4))
		max = len1+len2;
	else
		max = len3+len4;
	System.out.println("returning " + prod1 + " " + prod2 + " " + prod3);
	return ((int) Math.pow(2, max)*prod1) + ((int) Math.pow(2, max*0.5) * (prod2-prod1-prod3)) + prod3;
}

public static void main(String[] args)
{
try
{
	Scanner input = new Scanner(new File("9.in"));
	BufferedWriter output = new BufferedWriter(new FileWriter(new File("times17.out")));
	output.write(Integer.toBinaryString(multiply(input.nextLine(), "10001")) + "\n");
	input.close();
	output.close();
}
catch (IOException e)
{
	System.out.println("Error!");
}
}
}