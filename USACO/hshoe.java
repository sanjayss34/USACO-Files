import java.util.Scanner;
import java.io.*;

public class hshoe {
static int flag = 0;
static int path = 0;
static int countU = 0;
static int countU2 = 0;
static int[] not = new int[4];
static String result = "";
static int[] initials = new int[2];

public static boolean isBalanced (String p) {
	/*int flag1 = 0;
	int score = 0;
	char previous = '1';
	for (int c1 = 0; c1 < p.length(); c1++) {
		if (p.charAt('(')) {
			score++;
			if (flag1 == -1) return false;
			flag1 = 1;
			}
		else if (p.charAt(')')) {
			score--;
			if (previous =*/
	
	if (p.length() % 2 != 0) return false;
	else {
		String p1 = p.substring(0, p.length()/2);
		String p2 = p.substring(p.length()/2);
		for (int c2 = 0; c2 < p.length()/2; c2++) {
			if (p1.charAt(c2) == ')') return false;
			if (p2.charAt(c2) == '(') return false;
			}
		}
	return true;
}

public static boolean inArr(int z, int[] arr) {
	for (int a = 0; a < 4; a++) {
		if (arr[a] == z) return true;
	}
	return false;
	}

public static int go(char[][] array, int nextAvailx, int nextAvaily, int max, int one, int two, int three, int four) {
	//Help on initializing arrays from docs.oracle.com
	not[0] = 0;
	not[1] = 0;
	not[2] = 0;
	not[3] = 0;
	//int[] can = new int[4];
	int countN = 0;
	if (countU == 0) {
		result += array[nextAvailx][nextAvaily];
		initials[0] = nextAvailx;
		initials[1] = nextAvaily;
		}
	if (nextAvailx == 0) {
		countN++;
		not[1] = 1;
		}
	else if (nextAvailx == max) {
		countN++;
		not[3] = 1;
		}
	if (nextAvaily == 0) {
		countN++;
		not[2] = 1;
		}
	else if (nextAvaily == max) {
		countN++;
		not[0] = 1;
		}
	int choice = 6;
	if (!inArr(one, not)) choice = one;
	else if (!inArr(two, not)) choice = two;
	else if (!inArr(three, not)) choice = three;
	else if (!inArr(four, not)) choice = four;
	else if (isBalanced(result)) return path;
	else {
		countU2++;
		not[0] = 0;
		not[1] = 0;
		not[2] = 0;
		not[3] = 0;
		two++;
		three++;
		one++;
		four++;
		if (one == 4) one = 0;
		if (two == 4) two = 0;
		if (three == 4) three = 0;
		if (four == 4) four = 0;
		go(array, initials[0], initials[1], max, one, two, three, four);
		}
	
	switch (choice) {
		case 0:
			if ((array[nextAvailx][nextAvaily] == '(') && (flag == 1)) {
				nextAvaily++;
				not[0] = 1;
				go(array, nextAvailx, nextAvaily, max, one, two, three, four);
				}
			else nextAvaily--;
			break;
		case 1:
			if ((array[nextAvailx][nextAvaily] == '(') && (flag == 1)) {
				nextAvailx++;
				not[1] = 1;
				go(array, nextAvailx, nextAvaily, max, one, two, three, four);
				}
			else nextAvailx--;
			break;
		case 2:
			if ((array[nextAvailx][nextAvaily] == '(') && (flag == 1)) {
				nextAvaily--;
				not[2] = 1;
				go(array, nextAvailx, nextAvaily, max, one, two, three, four);
				}
			else
				nextAvaily++;
			break;
		case 3:
			if ((array[nextAvailx][nextAvaily] == '(') && (flag == 1)) {
				nextAvailx--;
				not[3] = 1;
				go(array, nextAvailx, nextAvaily, max, one, two, three, four);
				}
			else nextAvailx++;
			break;
		}
	if (nextAvailx >= max) nextAvailx--;
	if (nextAvaily >= max) nextAvaily--;
	if (array[nextAvailx][nextAvaily] == ')') flag = 1;
	result += array[nextAvailx][nextAvaily];
	path += result.length();
	countU++;
	go(array, nextAvailx, nextAvaily, max, one, two, three, four);
	return path;
	}

public static void main(String[] args) {
	
	try {
		//Used help on Scanner, etc. from download.oracle.com and from java-forums.com
		Scanner input3 = new Scanner(new File("hshoe.in"));
		int num1 = Integer.parseInt(input3.nextLine());
		char[][] characters = new char[num1][num1];
		for (int i = 0; i < num1; i++) {
			String lin = input3.nextLine();
		//int result = 0;
		}
		
		int largest = go(characters, 0, 0, num1, 0, 3, 2, 1);
		
		Integer res = new Integer(largest);
		
		try {
			//Help on BufferedWriter, etc. from mkyong.com
			BufferedWriter out3 = new BufferedWriter(new FileWriter(new File("hshoe.out")));
			out3.write(res.toString());
			}
		catch (IOException e1) {
			System.out.println("Error!");
			}
		}
		
		catch (IOException e2) {
			System.out.println("Error!");
	}
}
}