/*
0 0 0 0 0 0 0 0 0 0 0 0 - 0 0 0 0 0
0 0 0 0 0 0 * 0 0 0 0 0 - 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 - - - 0 0 0 0 0
0 0 0 * 0 0 0 0 0 0 - 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 - 0 0 0 0 0 0 *
0 0 0 0 0 0 0 0 0 0 - 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 - 0 0 0 0 0 0 0
- - - - - - - - - - - 0 0 0 0 0 0 0
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(void)
{
	ifstream infile;
	infile.open("crazy.in");
	ofstream outfile;
	outfile.open("crazy.out");
	int N = 0;
	int C = 0;
	infile >> N >> C;
	//int fences[N][4];
	//int cows[C][2];
	vector <vector <int>> fences;
	vector <vector <int>> cows;
	int* indices = (int*) malloc(sizeof(int) * C);
	for (int i = 0; i < N; i++)
	{
		int startX = 0;
		int startY = 0;
		int endX = 0;
		int endY = 0;
		infile >> startX >> startY >> endX >> endY;
		fences.push_back(vector <int> (startX, startY, endX, endY));
	}
	
	for (int ii = 0; ii < C; ii++)
	{
		int cowX = 0;
		int cowY = 0;
		infile >> cowX >> cowY;
		cows.push_back(vector <int> (cowX, cowY));
		indices[ii] = 0;
	}
	
	int index = 0;
	while (index < C)
	{
		if (indices[index] == 1)
			continue;
		indices[index] = 1;
		for (int j = 0; j < C; j++)
		{
			