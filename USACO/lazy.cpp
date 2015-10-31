#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define MAXN 400
int N, K;
int G[MAXN][MAXN];

/*int calcMax(int x, int y, int steps)
{
	if (steps == K)
		return G[x][y];
	int one = 0, two = 0, three = 0, four = 0;
	if (x + 1 < N)
		one = calcMax(x+1, y, steps+1);
	if (x - 1 >= 0)
		two = calcMax(x-1, y, steps+1);
	if (y+1 < N)
		three = calcMax(x, y+1, steps+1);
	if (y - 1 >= 0)
		four = calcMax(x, y-1, steps+1);
	return G[x][y] + max(one, max(two, max(three, four)));
}*/

//Referenced http://en.wikipedia.org/wiki/Depth-first_search

int main(void)
{
	ifstream infile ("lazy.in");
	ofstream outfile ("lazy.out");
	
	infile >> N >> K;
	
	for (int i = 0; i < N; i++)
	{
		for (int ii = 0; ii < N; ii++)
		{
			infile >> G[ii][i];
		}
	}
	
	int maxAmount = 0;
	
	for (int j = 0; j < N; j++)
	{
		for (int k = 0; k < N; k++)
		{
			//maxAmount = max(maxAmount, calcMax(j, k, 0));
			int amount = 0;
			for (int a = max(0, j-K); a < min(N, j+K+1); a++)
			{
				for (int b = max(0, k-K); b < min(N, k+K+1); b++)
				{
					if (abs(j-a) + abs(b-k) <= K)
					{
						//if (j == 2 && k == 2)
							//cout << G[a][b] << "\n";
						amount += G[a][b];
					}
				}
			}
			/*if (amount == 224)
			{
				cout << j << " " << k << "\n";
			}
			if (j == 2 && k == 2)
				cout << amount << "\n";*/
			maxAmount = max(maxAmount, amount);
		}
	}
	/*int count = 0;
	for (int k = 0; k < 64000000; k++)
	{
		if (count + 2*count + 3-(count*count) > 0)
			count++;
	}*/
	
	outfile << maxAmount << "\n";
	
	infile.close();
	outfile.close();
	
	return 0;
}