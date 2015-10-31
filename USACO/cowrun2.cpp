#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
typedef struct Edge
{
	int v1;
	int v2;
	int length;
}
Edge;

bool compareL(Edge const& e1, Edge const& e2)
{
	return e1.length < e2.length;
}

int main(void)
{
	ifstream infile ("cowrun.in");
	ofstream outfile ("cowrun.out");
	
	infile >> N;
	int* coords = (int*) malloc(sizeof(int) * (N+1));
	coords[0] = 0;
	
	for (int i = 1; i <= N; i++)
		infile >> coords[i];
	Edge* edges = (Edge*) malloc(sizeof(Edge) * (N+1)*N/2);
	int count = 0;
	for (int j = 0; j <= N; j++)
	{
		for (int j2 = j+1; j2 <= N; j2++)
		{
			edges[count] = Edge();
			edges[count].v1 = j;
			edges[count].v2 = j2;
			edges[count].length = abs(coords[j]-coords[j2]);
			//cout << edges[count].length << "\n";
			count++;
		}
	}
	
	sort(edges, edges+((N+1)*N/2), &compareL);
	
	//cout << edges[0].length <<  " " << edges[((N+1)*N/2) - 1].length << "\n";
	
	vector <int> contained;
	contained.push_back(0);
	int visited[1001] = {0};
	visited[0] = 1;
	int past = 0;
	int cost = 0;
	while (contained.size() < N+1)
	{
		int minInd = -1;
		for (int k = 0; k < (N+1)*N/2; k++)
		{
			int v1 = edges[k].v1;
			int v2 = edges[k].v2;
			if (((visited[v1] == 0) && (v2 == past)) || ((visited[v2] == 0) && (v1 == past)))
			{
				if ((minInd == -1) || (edges[k].length < edges[minInd].length))
					minInd = k;
			}
		}
		if (visited[edges[minInd].v1] == 0)
		{
			visited[edges[minInd].v1] = 1;
			contained.push_back(edges[minInd].v1);
			past = edges[minInd].v1;
		}
		else
		{
			visited[edges[minInd].v2] = 1;
			contained.push_back(edges[minInd].v2);
			past = edges[minInd].v2;
		}
		//cost += edges[minInd].length;
		//cout << edges[minInd].length << "\n";
	}
	
	for (int k2 = 1; k2 < contained.size(); k2++)
		cost += (N-k2+1)*abs(coords[contained[k2]]-coords[contained[k2-1]]);
	
	outfile << cost << "\n";
	
	infile.close();
	outfile.close();
	
	return 0;
}