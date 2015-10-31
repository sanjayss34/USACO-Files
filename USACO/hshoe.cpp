//#include <iostream>
#include <fstream>
using namespace std;

int mymax = 0;
char grid[5][5];
int N = 0;


void navigate (int x, int y, int open, int closed, int vis[5][5])
{
	//cout << x << " " << y << " " << grid[x][y] << open << " " << closed << "\n";
	int visited[5][5];
	if (grid[0][0] == ')')
		return;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			visited[i][j] = vis[i][j];
	}
	
	if (grid[x][y] == '(')
		open++;
	else
		closed++;
	if (open == closed)
	{
		if (open+closed > mymax)
			mymax = open + closed;
		return;
	}
	
	visited[x][y] = 1;
	if ((visited[x-1][y] == -1) && (x-1 >= 0))
	{
		if (closed != -1)
		{
			if (grid[x-1][y] == ')')
			{
			
				navigate(x-1, y, open, closed, visited);
			}
		}
		else
		{
			if (grid[x-1][y] == '(')
			{
				navigate(x-1, y, open, closed, visited);
			}
			else
			{
				navigate(x-1, y, open, 0, visited);
			}
		}
	}
	
	if ((visited[x+1][y] == -1) && (x+1 < N))
	{
		if (closed != -1)
		{
			if (grid[x+1][y] == ')')
			{
				navigate(x+1, y, open, closed, visited);
			}
		}
		else
		{
			if (grid[x+1][y] == '(')
			{
				navigate(x+1, y, open, closed, visited);
			}
			else
			{
				navigate(x+1, y, open, 0, visited);
			}
		}
	}
	
	if ((visited[x][y-1] == -1) && (y-1 >= 0))
	{
		if (closed != -1)
		{
			if (grid[x][y-1] == ')')
			{
				navigate(x, y-1, open, closed, visited);
			}
		}
		else
		{
			if (grid[x][y-1] == '(')
			{
				navigate(x, y-1, open, closed, visited);
			}
			else
			{
				navigate(x, y-1, open, 0, visited);
			}
		}
	}
	
	if ((visited[x][y+1] == -1) && (y+1 < N))
	{
		if (closed != -1)
		{
			if (grid[x][y+1] == ')')
			{
				navigate(x, y+1, open, closed, visited);
			}
		}
		else
		{
			if (grid[x][y+1] == '(')
			{
				navigate(x, y+1, open, closed, visited);
			}
			else
			{
				navigate(x, y+1, open, 0, visited);
			}
		}
	}
	
}

int main(void)
{
	ifstream infile;
	infile.open("hshoe.in");
	ofstream outfile ("hshoe.out");
	char instr[7];
	infile.getline(instr, 6);
	N = atoi(instr);
	int v[5][5] = {0};
	for (int k = 0; k < N; k++)
	{
		infile.getline(instr, 6);
		for (int kk = 0; kk < N; kk++)
		{
			grid[kk][k] = instr[kk];
			//cout << grid[kk][k];
			v[kk][k] = -1;
		}
		//cout << "\n";
	}
	
	navigate(0, 0, 0, -1, v);
	
	outfile << mymax << "\n";
	
	return 0;
}