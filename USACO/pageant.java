//Pageant
import java.io.*;
import java.util.Scanner;
import java.util.StringTokenizer;

public class pageant {

public static void main(String[] args) {


			//File1.seekg(7);
			try {
			Scanner keyboard = new Scanner(System.in);
			Scanner File1 = new Scanner(new File("pageant.in"));

			String str = File1.nextLine();

			String strW = str.substring(str.indexOf(" ") + 1);
			String strH = str.substring(0, str.indexOf(" "));


			int width = Integer.parseInt(strW);
			int height = Integer.parseInt(strH);

			char[][] characters = new char[width][height];
			int l = 0;

			int c1 = 0, c2 = 0;

			String[] spot1 = new String[width*height];
			String[] spot2 = new String[width*height];
			
			int count1 = 0;
			int count2 = 0;
			
			while (c2 < height) {
			str = File1.nextLine();
			
			for(c1 = 0; c1 < width; c1++) {
			characters[c1][c2] = str.charAt(c1);

			if (characters[c1][c2] == 'X') {
			Integer forToStr = new Integer(0);
			if (l == 0) {
				forToStr = c1;
				spot1[0] = forToStr.toString() + " ";
				forToStr = c2;
				spot1[0] += forToStr.toString();
				count1++;
				}
			
			else {
				int flag = 0;
				for (int z = 0; z < count1; z++) {
						StringTokenizer tokenizer = new StringTokenizer(spot1[z]);
						int elX = Integer.parseInt(tokenizer.nextToken());
						int elY = Integer.parseInt(tokenizer.nextToken());
						if (((elX == c1) && (Math.abs(elY-c2) == 1)) || ((elY == c2) && (Math.abs(elX-c1) == 1))) {
							flag = 1;
							break;
							}
						}
				if (flag == 1) {
					forToStr = c1;
					spot1[count1] = forToStr.toString() + " ";
					forToStr = c2;
					spot1[count1] += forToStr.toString();
					count1++;
					}
				else {
					forToStr = c1;
					spot2[count2] = forToStr.toString() + " ";
					forToStr = c2;
					spot2[count2] += forToStr.toString();
					count2++;
					}
				}
			
			l++;
			
			}
			}

			c2++;
			//cout << str << "\n";
			}

			//File2 << characters << "\n";

			Xs[] group = new Xs[l];
			int place = 0;
			

			for (int j = 0; (j < height); j++){
				for (int i = 0; i < width; i++) {
					if (characters[i][j] == 'X') {
						Xs obj = new Xs(i, j);
						group[place] = obj;
						int flag2 = 0;
						for (int ind = 0; ind < count1; ind++) {
							if ((Integer.parseInt(spot1[ind].split(" ")[0]) == i) && (Integer.parseInt(spot1[ind].split(" ")[1]) == j)) {
								group[place].spot = 1;
								flag2 = 1;
								break;
								}
								}
						if (flag2 == 0) group[place].spot = 2;
						place++;
						};
					}
				//File2 << "\n";
				}
			
			for (int ind = 0; ind < place; ind++) {
				if (group[ind].spot == 2) {
				int flag3 = 0;
				for (int ind2 = 0; ind2 < place; ind2++) {
					if ((group[ind2].xCoord == group[ind].xCoord) && ((group[ind2].yCoord == group[ind].yCoord + 1) || (group[ind2].yCoord == group[ind].yCoord -1)) && (group[ind2].spot == group[ind].spot)) {
						flag3 = 1;
						}
					}
				if ((flag3 == 0) && (group[ind].spot == 1)) group[ind].spot = 2;
				else if ((flag3 == 0) && (group[ind].spot == 2)) group[ind].spot = 1;
				}
				}
				
			for (int ind4 = 0; ind4 < place; ind4++) {
				if (group[ind4].spot == 1) {
				int flag4 = 0;
				for (int ind3 = 0; ind3 < place; ind3++) {
					if ((group[ind3].yCoord == group[ind4].yCoord) && ((group[ind3].xCoord == group[ind4].xCoord + 1) || (group[ind3].xCoord == group[ind4].xCoord -1)) && (group[ind3].spot == group[ind4].spot)) {
						flag4 = 1;
						}
					}
				if ((flag4 == 0) && (group[ind4].spot == 1)) group[ind4].spot = 2;
				else if ((flag4 == 0) && (group[ind4].spot == 2)) group[ind4].spot = 1;
				}
				}
			
				

			int smallest = width + height;
			//System.out.println(smallest);
			for (int k = 0; k < place; k++) {
				for (int h = 0; h < place; h++) {
					if ((group[k].distance(group[h]) < smallest) && !group[k].adjac(group[h]) && (k != h) && (group[k].spot != group[h].spot)) {//(group[k].distance(group[h]) != 1)
						smallest = group[k].distance(group[h]);
						//System.out.println(place + " " + l + " " + k + " " + h);
						/*System.out.println(group[k].xCoord + " " + group[k].yCoord + " " + group[k].spot);
						System.out.println(group[h].xCoord + " " + group[h].yCoord + " " + group[h].spot);*/
						};
					/*System.out.println("onceww");
					System.out.println(place + " " + l + " " + k + " " + h);*/
					}
			}

			/*System.out.println(smallest);
			System.out.println(count1 + " " + count2);*/
			
			try {
				Integer num = new Integer(smallest);
				BufferedWriter out = new BufferedWriter(new FileWriter(new File("pageant.out")));
				out.write(num.toString());
				out.close();
				}
			catch (IOException e2) {
				System.out.println("Error!");
				}
			
			/*for (int in1 = 0; in1 < count1; in1++) {
				System.out.println(spot1[in1]);
				}
			for (int in2 = 0; in2 <count2; in2++) {
				System.out.println(spot2[in2]);
				}*/

		}
		catch(IOException e) {
			System.out.println("Error!");
		}
		}
		}

		class Xs {
			int xCoord;
			int yCoord;
			int spot;

			public Xs (int x, int y) {
				xCoord = x;
				yCoord = y;
			}

			public int distance(Xs obj) {
				return Math.abs(xCoord-obj.xCoord) + Math.abs(yCoord - obj.yCoord) -1;
			}

			public boolean adjac(Xs obj2) {
				return (((xCoord==obj2.xCoord) && (Math.abs(yCoord-obj2.yCoord) == 1)) || ((yCoord == obj2.yCoord) && (Math.abs(xCoord-obj2.xCoord) == 1)));
			}

	}