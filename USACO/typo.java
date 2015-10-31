import java.util.Scanner;
import java.io.*;

public class typo {
public static boolean isBalanced(String paren) {
	int score = 0;
	int count1 = 0;
	int count2 = 0;
	for (int c1 = 0; c1 < paren.length(); c1++) {
		if (paren.charAt(c1) == '(') {
			score++;
			count1++;
			}
		else if (paren.charAt(c1) == ')') {
			score--;
			count2++;
			}
		if (count1 < count2) return false;
	}
	if (score != 0) return false;
	else return true;
	}

public static String insertRemove(String str, int index) {
	String result = "";
	for (int j = 0; j < str.length(); j++) {
		if (j != index) result+= str.charAt(j);
		else if (str.charAt(index) == '(') result += ')';
		else if (str.charAt(index) == ')') result += '(';
		}
	return result;
	}

public static void main(String[] args) {
	try {
		//Help with Scanner from download.oracle.com and java-forums.org
		Scanner input = new Scanner(new File("typo.in"));
		String theLin = input.nextLine();
		
		int resultC = 0;
		
		String temp = "";
		for (int i = 0; i < theLin.length(); i++) {
			if (theLin.charAt(i) == '(') temp = insertRemove(theLin, i);
			else if (theLin.charAt(i) == ')') temp = insertRemove(theLin, i);
			
			if (isBalanced(temp)) resultC++;
			}
		
		Integer toOut = new Integer(resultC);
		try {
			//Help with BufferedWriter, etc. from mkyong.com
			BufferedWriter out = new BufferedWriter(new FileWriter(new File("typo.out")));
			out.write(toOut.toString());
			out.close();
			}
		catch (IOException one) {
			System.out.println("Error!");
			}
		}
	
	catch (IOException two) {
		System.out.println("Error!");
		}
	}
	}