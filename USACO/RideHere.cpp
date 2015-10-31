/*
ID: sanjay_4
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () {
	ifstream fin ("ride.in");
	ofstream fout ("ride.out");
	string str1;
	fin >> str1;
	string str2;
	fin >> str2;
	int value1 = 1;
	int value2 = 1;
	
	for (int i = 0; i < str1.length(); i++) {
		value1 = value1 * (int(str1[i]) - 64);
	}
	for (int j = 0; j < str2.length(); j++) {
		value2 = value2 * (int(str2[j]) - 64);
	}
	
	if((value1 % 47) == (value2 % 47)) fout << "GO" << endl;
	else {
		fout << "STAY" << endl;
	}
	
	return 0;
}
