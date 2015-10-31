#include <iostream>
#include <fstream>
using namespace std;

int pathMinD;
int maxD;
int heights[500][500];

void traverse(int x, int y, int vis[500][500], int xf, int yf, int M, int N, int pmd)
{
	if (x == xf && y == yf)
	{
		pathMinD = min(pmd, pathMinD);
		return;
	}
	vis[x][y] = 1;
	if (x+1 < M)
	{
		if (vis[x+1][y] == 0)
		{
			if (abs(heights[x+1][y]-heights[x][y]) < pathMinD)
				traverse(x+1, y, vis, xf, yf, M, N, max(pmd, abs(heights[x+1][y]-heights[x][y])));
		}
	}
	if (x-1 >= 0)
	{
		if (vis[x-1][y] == 0)
		{
			if (abs(heights[x-1][y]-heights[x][y]) < pathMinD)
				traverse(x-1, y, vis, xf, yf, M, N, max(pmd, abs(heights[x-1][y]-heights[x][y])));
		}
	}
	if (y+1 < N)
	{
		if (vis[x][y+1] == 0)
		{
			if (abs(heights[x][y+1]-heights[x][y]) < pathMinD)
				traverse(x, y+1, vis, xf, yf, M, N, max(pmd, abs(heights[x][y+1]-heights[x][y])));
		}
	}
	if (y-1 >= 0)
	{
		if (vis[x][y-1] == 0)
		{
			if (abs(heights[x][y-1]-heights[x][y]) < pathMinD)
				traverse(x, y-1, vis, xf, yf, M, N, max(pmd, abs(heights[x][y-1]-heights[x][y])));
		}
	}
	vis[x][y] = 0;
}

int main(void)
{
	ifstream infile ("ccski.in");
	ofstream outfile;
	outfile.open("ccski.out");
	
	int M = 0;
	int N = 0;
	infile >> M >> N;
	
	//int heights[M][N];
	int waypoints[M*N][2];
	int numWP = 0;
	
	
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			infile >> heights[i][j];
		}
	}
	
	for (int i2 = 0; i2 < M; i2++)
	{
		for (int j2 = 0; j2 < N; j2++)
		{
			int mark = 0;
			infile >> mark;
			if (mark == 1)
			{
				waypoints[numWP][0] = i2;
				waypoints[numWP][1] = j2;
				numWP++;
			}
		}
	}
	
	pathMinD = 1000000000;
	maxD = 0;
	int vis[500][500] = {0};
	for (int k = 0; k < numWP; k++)
	{
		for (int k2 = k+1; k2 < numWP; k2++)
		{
			traverse(waypoints[k][0], waypoints[k][1], vis, waypoints[k2][0], waypoints[k2][1], M, N, 0);
			if (pathMinD > maxD)
				maxD = pathMinD;
			pathMinD = 1000000000;
		}
	}
	
	outfile << maxD << "\n";
	
	return 0;
}