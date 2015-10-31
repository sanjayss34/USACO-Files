#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;


class Xs {
	int xCoord;
	int yCoord;
	public:
	Xs () {
	xCoord = 0;
	yCoord = 0;
};

	Xs (int x, int y) {
		xCoord = x;
		yCoord = y;
}

	void set(int x, int y) {
		xCoord = x;
		yCoord = y;
};
	int distance (Xs obj) {
	int val = abs(xCoord-obj.xCoord) + abs(yCoord - obj.yCoord) -1;

	return val;
};

};


int main() {
	ifstream File1 ("pageant.in");
	ofstream File2 ("pageant.out");
	
	string str;
	
	if (File1.is_open() && File2.is_open()) {
		//File1.seekg(7);
		
		getline(cin, str);
		char* str2 = new char[str.length() + 1];
		strcpy(str2, str.c_str());
		char* dim2 = strtok(str2, " ");
		char* dim1 = strtok(NULL, " ");
		
		int height = atoi(dim2);
		int width = atoi(dim1);
		
		char characters[width][height];
		int l = 0;
		
		int c1 = 0, c2 = 0;
		while (c2 < height) {
		getline(cin, str);
		for(c1 = 0; c1 < width; c1++) {
		characters[c1][c2] = str.at(c1);
		
		if (characters[c1][c2] == 'X') l++;
		}
		
		c2++;
		//cout << str << "\n";
		}
		
		//File2 << characters << "\n";
		
		Xs *group[2500] = new Xs[2500];
		int place = 0;
		
		for (int j = 0; (j < height); j++){
			for (int i = 0; i < width; i++) {
				if (characters[i][j] == 'X') {
					&group[place].set(i, j);// = new Xs(i, j);
					place++;
					};
				}
			//File2 << "\n";
			}
		
		int smallest = width + height;
		for (int k = 0; k < place +1; k++) {
			for (int h = 0; h < place + 1; h++) {
				if (&group[k].distance(&group[h]) < smallest) {
					smallest = &group[k].distance(&group[h]);
					};
				}
			}
		
		cout << smallest;
			
		//cout << len << width << height;
		}
		
	else {
		cout << "IN ELSE";
		}
		
	return 0;
	}
