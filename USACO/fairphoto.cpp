#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

#define MAXN 100000

int main(void)
{
	ifstream infile("fairphoto.in");
	ofstream outfile("fairphoto.out");
	int N, K;
	infile >> N >> K;
	
	pair<int, int> cows[N];
	for (int i = 0; i < N; i++)
	{
		int loc, b;
		infile >> loc >> b;
		loc--;
		b--;
		cows[i] = make_pair(loc, b);
	}
	
	sort(cows, cows+N);
	
	int balance[N][N][8];
	
	/*balance[0][0][cows[0].second] = 1;
	for (int a = 1; a < 8; a++)
		balance[0][0][a] = 0;*/
	
	int maxDiff = 0;
	
	for (int j = 0; j < N; j++)
	{
		for (int a3 = 0; a3 < 8; a3++)
			balance[j][j][a3] = 0;
		balance[j][j][cows[j].second] = 1;
		for (int k = j+1; k < N; k++)
		{
			int numInc = 0;
			int numBreeds = 0;
			for (int a2 = 0; a2 < 8; a2++)
			{
				balance[j][k][a2] = balance[j][k-1][a2];
				if (a2 == cows[k].second)
					balance[j][k][a2]++;
				if (balance[j][k][a2] > 0)
				{
					if (numInc == 0)
						numInc = balance[j][k][a2];
					else if (balance[j][k][a2] != numInc)
						numInc = -1;
					numBreeds++;
				}
				/*if (cows[j].first == 1 && cows[k].first == 7)
					cout << balance[j][k][a2] << "\n";*/
			}
			if (numInc != -1 && numBreeds >= K)
				maxDiff = max(cows[k].first - cows[j].first, maxDiff);
			/*else
			{
				cout << cows[j].first << " " << cows[k].first << " " << numBreeds << "\n";
			}*/
		}
	}
	
	if (maxDiff == 0)
		outfile << "-1\n";
	else
		outfile << maxDiff << "\n";
	
	infile.close();
	outfile.close();
	
	return 0;
}