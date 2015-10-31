#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int Count;

int generate(int index, int* state, int* x, int* y, int num)
{
	//cout << "in\n";
	if (index >= num)
	{
		//cout << "CHECK\n";
		int* done = (int*) malloc(sizeof(int) * num);
		for (int k = 0; k < num; k++)
			done[k] = 0;
		int flag = 0;
		for (int k2 = 0; k2 < num; k2++)
		{
			//cout << "point\n";
			if (done[k2] == 1)
				continue;
			done[k2] = 1;
			done[state[k2]] = 1;
			//cout << x[k2] << " " << y[k2] << " " << x[state[k2]] << " " << y[state[k2]] << "\n";
			if (y[k2] == y[state[k2]])
			{
				flag = 0;
				break;
			}
			int flag2 = 1;
			for (int a = 0; a < num; a++)
			{
				if (a == k2)
					continue;
				if ((y[k2] == y[a]) && (x[a] > x[k2]))
				{
					//cout << "w" << x[a] << y[a] << x[k2] << y[k2] << "\n";
					flag2 = 0;
					break;
				}
			}
			if (flag2 == 1)
			{
				//cout << "yes\n";
				for (int b = 0; b < num; b++)
				{
					if (b == state[k2])
						continue;
					if ((y[state[k2]] == y[b]) && (x[b] > x[state[k2]]))
					{
						//cout << "w" << x[b] << y[b] << x[state[k2]] << y[state[k2]] << "\n";
						flag2 = 0;
						break;
					}
				}
			}
			if (flag2 == 1)
				flag = 1;
		}
		if (flag == 0)
		{
			Count++;
			//cout << "start\n";
			for (int q = 0; q < num; q++)
			{
				if (state[q] < q)
					continue;
				//cout << x[q] << " " << y[q] << " " << x[state[q]] << " " << y[state[q]] << "\n";
			}
		}
	}
	else if (state[index] != -1)
		generate(index+1, state, x, y, num);
	else
	{
		//cout << index << "\n";
		for (int j = 0; j < num; j++)
		{
			if ((j == index) || (state[j] != -1))
				continue;
			int* newState = (int*) malloc(sizeof(int) * num);
			for (int j2 = 0; j2 < num; j2++)
			{
				if(j2 == j)
					newState[j2] = index;
				else if (j2 == index)
					newState[j2] = j;
				else
					newState[j2] = state[j2];
			}
			generate(index+1, newState, x, y, num);
		}
	}
}
		
int main(void)
{
	ifstream infile("wormhole.in");
	ofstream outfile("wormhole.out");
	int N = 0;
	Count = 0;
	infile >> N;
	int* vertX = (int*) malloc(sizeof(int) * N);
	int* vertY = (int*) malloc(sizeof(int) * N);
	for (int i2 = 0; i2 < N; i2++)
	{
		infile >> vertX[i2] >> vertY[i2];
	}
	
	int* s = (int*) malloc(sizeof(int) * N);
	for (int t = 0; t < N; t++)
		s[t] = -1;
	generate(0, s, vertX, vertY, N);
	
	outfile << Count << "\n";
	
	return 0;
}