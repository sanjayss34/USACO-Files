import java.util.Scanner;
import java.io.*;
import java.util.StringTokenizer;

public class greetings {

public static void main(String[] args) {

try {
	Scanner input = new Scanner(new File("greetings.in"));
	String twoInts = input.nextLine();
	StringTokenizer tzer1 = new StringTokenizer(twoInts, " ");
	final int B = Integer.parseInt(tzer1.nextToken());
	final int E = Integer.parseInt(tzer1.nextToken());
	
	int[] bPos = new int[1000000];
	bPos[0] = 0;
	int bPlace = 1;
	
	for (int i = 0; i < B; i++) {
		String moveB = input.nextLine();
		StringTokenizer tzerB = new StringTokenizer(moveB, " ");
		int amountB = Integer.parseInt(tzerB.nextToken());
		String dirB = tzerB.nextToken();
		if (dirB.equals("L")) {
			for (int p1 = 0; p1 < amountB; p1++) {
				bPos[bPlace] = bPos[bPlace-1] - 1;
				bPlace++;
				}
			//System.out.println("L!");
			}
		else {
			for (int p2 = 0; p2 < amountB; p2++) {
				bPos[bPlace] = bPos[bPlace - 1] + 1;
				bPlace++;
				}
		}
		}
	
	int[] ePos = new int[1000000];
	ePos[0] = 0;
	int ePlace = 1;
	for (int j = 0; j < E; j++) {
		String moveE = input.nextLine();
		StringTokenizer tzerE = new StringTokenizer(moveE, " ");
		int amountE = Integer.parseInt(tzerE.nextToken());
		String dirE = tzerE.nextToken();
		if (dirE.equals("L")) {
			for (int p3 = 0; p3 < amountE; p3++) {
				ePos[ePlace] = ePos[ePlace-1] - 1;
				ePlace++;
				}
		}
		else {
			for (int p4 = 0; p4 < amountE; p4++) {
				ePos[ePlace] = ePos[ePlace - 1] + 1;
				ePlace++;
				}
			}
		}
	int times = 0;
	final int MAX;
	if (bPlace >= ePlace) {
		MAX = bPlace;
		int diff1 = MAX-ePlace;
		int original1 = ePos[ePlace-1];
		for (int rest1 = 0; rest1 < diff1; rest1++, ePlace++) {
			ePos[ePlace] = original1;
			}
	}
	else {
		MAX = ePlace;
		int diff2 = MAX-bPlace;
		int original2 = bPos[bPlace-1];
		for (int rest2 = 0; rest2 < diff2; rest2++, bPlace++) {
			bPos[bPlace] = original2;
			}
	}
	
	int flag = 0;
	for (int k = 1; k < MAX; k++) {
		if (bPos[k] == ePos[k]) {
			if (flag == 0) {
				times++;
				//System.out.println(k);
				flag = 1;
				}
		}
		else flag = 0;
		}
	/*System.out.print("\n");
	for (int thing = 0; thing < MAX; thing++) System.out.println(bPos[thing]);
	System.out.print("\n");
	for (int thing2 = 0; thing2 < MAX; thing2++) System.out.println(ePos[thing2]);*/
	
	Integer timesOut = new Integer(times);
	
	//Help on BufferedWriter, etc. from www.mkyong.com
	BufferedWriter out = new BufferedWriter(new FileWriter(new File("greetings.out")));
	out.write(timesOut.toString());
	out.close();
	}
catch (IOException e) {
	System.out.println("Error!");
	}
}
}