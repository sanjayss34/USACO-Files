import java.util.Scanner;
import java.io.*;

public class scramble {

public static void(String[] args) {

try {
	Scanner sIn = new Scanner(new File("scramble.in"));
	int nCows = Integer.parseInt(sIn.nextLine());
	String[] names = new String[nCows-1];
	int[][] nums = new int[nCows-1][20];
	
	for(int count1 = 0; count1 < nCows-1; count1++) {
		names[count1] = sIn.nextLine();
		for (int chInt = 0; chInt < names[count1].length()-1; chInt++) {
			nums[count1][chInt] = (int) names[count1].charAt(chInt);
			}
		}
	int[][] lowest = new int[nCows-1][20];
	for (int count4 = 0; count4 < nCows - 1; count4++) {
		int place1 = 0;
		int place2 = 0;
		int lowest = 130;
		while (place1 < names[count4].length()) {
			if (nums[count4][place1] <= lowest) {
				lowest[count4][place2] = nums[count4][place1];
				place2++;
				}
			place1++;
			}
		}
	for (int count5 = 0; count 5 < nCows - 1; count5++) {
		int place3 = 0;
		int place4 = 0;
		int highest = 96;
		while (place3 < names[count5].length()) {
			if (nums[count5][place3] >= highest) {
				highest[count5][place4] = nums[count5][place3];
				place4++;
				}
			place3++;
			}
		}
	for (int count2 = 0; count2 < nCows - 1; count2++) {
		int[] compsL = new int[nCows-2];
		int[] compsB = new int[nCows-2];
		for (int count3 = 0; count3<nCows - 1; count3++) {
			if (count2 == count3) continue;
			else {
				int diffL = 0;
				int diffB = 0;
				int point = 0;
				while (((diffL == 0) || (diffB == 0) && (point < names[count2].length()) && (point < names[count3].length())) {
					if (nums[count2][point] > nums[count3][point]) diffB = 1;
					else if (nums[count2][point] 