#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

#define MAXN 2000

typedef struct Field
{
	vector <int> adj;
}
Field;

int N, C;
//int connected[MAXN][MAXN];

//Referenced Wikipedia pages on Prim's algorithm, adjacency matrix; also: http://www.cs.arizona.edu/classes/cs445/spring05/Lecture-16.pdf
//Referenced http://www.cse.ust.hk/~dekai/271/notes/L07/L07.pdf and cplusplus.com pages on vector, vector::erase, pair, sort
//Referenced my solution to rblock from February 2014 USACO Silver contest and the problem information for that problem

bool compareD(pair<int, int> const& p1, pair<int, int> const& p2)
{
	return p1.second < p2.second;
}

int main(void)
{
	ifstream infile ("irrigation.in");
	ofstream outfile ("irrigation.out");
	
	infile >> N >> C;
	int* xCoords = (int*) malloc(sizeof(int) * N);
	int* yCoords = (int*) malloc(sizeof(int) * N);
	
	//vector <int> added;
	//vector <int> left;
	
	for (int i = 0; i < N; i++)
	{
		infile >> xCoords[i] >> yCoords[i];
		//left.push_back(i);
	}
	Field fields[N];
	for (int j = 0; j < N; j++)
	{
		for (int j2 = j+1; j2 < N; j2++)
		{
			/*if(j == j2)
			{
				connected[j][j2] = 0;
				connected[j2][j] = 0;
			}*/
			if (((xCoords[j]-xCoords[j2])*(xCoords[j]-xCoords[j2]))+((yCoords[j]-yCoords[j2])*(yCoords[j]-yCoords[j2])) >= C)
			{
				/*connected[j][j2] = ((xCoords[j]-xCoords[j2])*(xCoords[j]-xCoords[j2]))+((yCoords[j]-yCoords[j2])*(yCoords[j]-yCoords[j2]));
				connected[j2][j] = connected[j][j2];*/
				fields[j].adj.push_back(j2);
				fields[j2].adj.push_back(j);
			}
			/*else
			{
				connected[j][j2] = 0;
				connected[j2][j] = 0;
			}*/
		}
	}
	
	/*added.push_back(0);
	int cost = 0;
	int visited[MAXN] = {0};
	visited[0] = 1;
	while (added.size() < N)
	{
		int minInd1 = -1;
		int minInd2 = -1;
		int minDist = 0;
		for (int k = 0; k < added.size(); k++)
		{
			for (int k2 = 0; k2 < N; k2++)
			{
				if ((visited[k2] == 1) || (connected[added[k]][k2] == 0))
					continue;
				else if ((minInd1 == -1) || (connected[added[k]][k2] < minDist))
				{
					minInd1 = k;
					minInd2 = k2;
					minDist = connected[added[k]][k2];
				}
			}
		}
		
		if (minInd1 == -1)
			break;
		else
		{
			added.push_back(minInd2);
			visited[minInd2] = 1;
			cost += minDist;
			//cout << minInd1 << " " << minInd2 << " " << minDist << "\n";
		}
	}*/
	
	vector < pair<int, int> > verts;
	verts.push_back(make_pair(0, 0));
	for (int a = 1; a < N; a++)
	{
		verts.push_back(make_pair(a, 1000000000));
	}
	
	int* distances = (int*) malloc(sizeof(int) * N);
	distances[0] = 0;
	for (int d = 1; d < N; d++)
		distances[d] = 1000000000;
	int count = 0;
	int visited[MAXN] = {0};
	visited[0] = 1;
	int flag = 0;
	int cost = 0;
	while (count < N)
	{
		int ind = verts[0].first;
		if (verts[0].second == 1000000000)
			break;
		else
			cost += verts[0].second;
		verts.erase(verts.begin());
		count++;
		for (int c1 = 0; c1 < fields[ind].adj.size(); c1++)
		{
			int ind2 = fields[ind].adj[c1];
			if (visited[ind2] == 0)
			{
				if (((xCoords[ind]-xCoords[ind2])*(xCoords[ind]-xCoords[ind2])) + ((yCoords[ind]-yCoords[ind2])*(yCoords[ind]-yCoords[ind2])) < distances[ind2])
					distances[ind2] = ((xCoords[ind]-xCoords[ind2])*(xCoords[ind]-xCoords[ind2])) + ((yCoords[ind]-yCoords[ind2])*(yCoords[ind]-yCoords[ind2]));
			}
		}
		for (int b = 0; b < verts.size(); b++)
			verts[b].second = distances[verts[b].first];
		sort(verts.begin(), verts.end(), &compareD);
	}
	
	/*int c = 0;
	for (int i = 0; i < 360000000; i++)
		c++;*/
	
	if (count < N)
		outfile << "-1\n";
	else
		outfile << cost << "\n";
	
	infile.close();
	outfile.close();
	
	return 0;
}