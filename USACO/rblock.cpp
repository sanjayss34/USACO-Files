#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAXN 251

typedef struct path
{
	vector <int> p;
}
path;

int N, M;

int adj_mat[MAXN][MAXN] = {0};

int calcMinDist(int start)
{
	int* sDist = (int*) malloc(sizeof(int) * N);
	sDist[start] = 0;
	if (start == N-1)
		return 0;
	vector <int> verts;
	vector <int> :: iterator iter;
	verts.push_back(start);
	int numVert = 1;
	int visited[MAXN] = {0};
	visited[start] = 1;
	while (numVert < N)
	{
		int minDist = 1000001;
		int chosenV = -1;
		int chosenW = -1;
		for (int j = 0; j < numVert; j++)
		{
			for (int j2 = 0; j2 < N; j2++)
			{
				if (verts[j] == j2)
					continue;
				if (visited[j2] == 1)
					continue;
				if (adj_mat[j2][verts[j]] == 0)
					continue;
				if (sDist[verts[j]]+adj_mat[j2][verts[j]] < minDist)
				{
					minDist = sDist[verts[j]]+adj_mat[j2][verts[j]];
					chosenV = verts[j];
					chosenW = j2;
				}
			}
		}
			verts.push_back(chosenW);
			sDist[chosenW] = minDist;
			//cout << chosenW << "c\n";
			//cout << minDist << "\n";
			visited[chosenW] = 1;
			numVert++;
			if (chosenW == N-1)
				break;
	}
	//cout << "done\n";
	return sDist[N-1];
}

int main(void)
{
	ifstream infile ("rblock.in");
	ofstream outfile ("rblock.out");
	
	infile >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int vert1, vert2, length;
		infile >> vert1 >> vert2 >> length;
		vert1--;
		vert2--;
		adj_mat[vert1][vert2] = length;
		adj_mat[vert2][vert1] = length;
	}
	
	path* trails = (path*) malloc(sizeof(path) * N);
	
	//cout << "one\n";
	
	(trails[0].p).push_back(0);
	
	int* sDist = (int*) malloc(sizeof(int) * N);
	sDist[0] = 0;
	vector <int> verts;
	verts.push_back(0);
	int numVert = 1;
	int visited[MAXN] = {0};
	visited[0] = 1;
	while (numVert < N)
	{
		//cout << "inside\n";
		int minDist = 1000001;
		int chosenV = -1;
		int chosenW = -1;
		for (int j = 0; j < numVert; j++)
		{
			for (int j2 = 0; j2 < N; j2++)
			{
				if (verts[j] == j2)
					continue;
				if (visited[j2] == 1)
					continue;
				if (adj_mat[j2][verts[j]] == 0)
					continue;
				if (sDist[verts[j]]+adj_mat[j2][verts[j]] < minDist)
				{
					minDist = sDist[verts[j]]+adj_mat[j2][verts[j]];
					chosenV = verts[j];
					chosenW = j2;
				}
			}
		}
			verts.push_back(chosenW);
			sDist[chosenW] = minDist;
			//cout << minDist << "\n";
			visited[chosenW] = 1;
			numVert++;
			for (int j3 = 0; j3 < trails[chosenV].p.size(); j3++)
				trails[chosenW].p.push_back(trails[chosenV].p[j3]);
			trails[chosenW].p.push_back(chosenW);
			if (chosenW == N-1)
				break;
	}
	
	//cout << "two\n";
	
	int max = 0;
	for (int k = 1; k < trails[N-1].p.size(); k++)
	{
		//cout << trails[N-1].p[k] << " ";
		adj_mat[trails[N-1].p[k]][trails[N-1].p[k-1]] *= 2;
		adj_mat[trails[N-1].p[k-1]][trails[N-1].p[k]] *= 2;
		int dist = calcMinDist(0);
		/*int dist = sDist[trails[N-1].p[k-1]] + adj_mat[trails[N-1].p[k]][trails[N-1].p[k-1]] + calcMinDist(trails[N-1].p[k]);
		cout << sDist[trails[N-1].p[k-1]] << " " << adj_mat[trails[N-1].p[k]][trails[N-1].p[k-1]] << calcMinDist(trails[N-1].p[k]) << "\n";*/
		if (dist > max)
			max = dist;
		adj_mat[trails[N-1].p[k]][trails[N-1].p[k-1]] /= 2;
		adj_mat[trails[N-1].p[k-1]][trails[N-1].p[k]] /= 2;
	}
	
	//cout << "\n" << max << "\n";
	//cout << sDist[N-1] << "\n";
	
	outfile << max-sDist[N-1] << "\n";
	
	return 0;
}