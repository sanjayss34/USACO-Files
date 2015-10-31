#include <iostream>
#include <fstream>
using namespace std;

int maximum;

inline void traverse(int f[1000][1000], int N, int M, int a, int b, int dir)
{
	int num = 0;
	int as[4];
	int bs[4];
	int d = 0;
	while ((a >= 0) && (a < N) && (b >= 0) && (b < M))
	{
		num++;
		as[d] = a;
		bs[d] = b;
		d++;
		//f[a][b][dir] = 1;
		switch(dir)
		{
			case 0:
				if (f[a][b] == 1)
				{
					a--;
					dir = 1;
				}
				else
				{
					a++;
					dir = 3;
				}
				break;
			case 1:
				if (f[a][b] == 1)
				{
					b++;
					dir = 0;
				}
				else
				{
					b--;
					dir = 2;
				}
				break;
			case 2:
				if (f[a][b] == 1)
				{
					a++;
					dir = 3;
				}
				else
				{
					a--;
					dir = 1;
				}
				break;
			case 3:
				if (f[a][b] == 1)
				{
					b--;
					dir = 2;
				}
				else
				{
					b++;
					dir = 0;
				}
				break;
		}
	}
	if (num > maximum)
	{
		maximum = num;
		cout << "A\n";
		for (int dd = 0; dd < num; dd++)
			cout << as[dd] << bs[dd] << "\n";
	}
}
				

int main(void)
{
	ifstream infile;
	infile.open("mirror.in");
	ofstream outfile;
	outfile.open("mirror.out");
	int N = 0;
	int M = 0;
	infile >> N >> M;
	int field[1000][1000];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char c;
			infile >> c;
			if (c == '/')
				field[i][j] = 1;
			else
				field[i][j] = -1;
		}
	}
	
	maximum = 0;
	
	for (int i2 = 0; i2 < N; i2++)
	{
		traverse(field, N, M, i2, 0, 0);
		traverse(field, N, M, i2, M-1, 2);
	}
	for (int j2 = 0; j2 < M; j2++)
	{
		traverse(field, N, M, 0, j2, 3);
		traverse(field, N, M, N-1, j2, 1);
	}
	
	outfile << maximum << "\n";
	
	infile.close();
	outfile.close();
	
	return 0;
}