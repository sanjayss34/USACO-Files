import java.util.Scanner;
import java.io.*;

public class cowfind {
public static void main(String[] args) {
	//Help on Scanner from java-forums.org, download.oracle.com
	try {
		Scanner input = new Scanner(new File("cowfind.in"));
		String line = input.nextLine();
		//System.out.println(line);
		int hind = 0;
		int front = 0;
		String theHind = "((";
		String theFront = "))";
		for (int i = 0; i < line.length()-1; i++) {
			if (line.substring(i, i+2).compareTo(theHind) == 0) hind++;
			else if (line.substring(i, i+2).compareTo(theFront) == 0) front++;
			}
		
		//Help on BufferedWriter, etc. from www.mkyong.com
		try {
			BufferedWriter out = new BufferedWriter(new FileWriter(new File("cowfind.out")));
			/*Integer hind2 = new Integer(hind);
			Integer front2 = new Integer(front);*/
			Integer result = new Integer(hind*front);
			out.write(result.toString());
			//out.write(hind2.toString() + " " + front2.toString());
			out.close();
			}
		catch (IOException exc) {
			System.out.println("Error!");
			}
			}
	catch (IOException exc2) {
		System.out.println("Error!");
		}
	}
	}
	