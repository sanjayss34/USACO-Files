#include <fstream>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;

int count (int** w, int* s, int start, int len, int limit)
{
	for (int k = 0; k < len; k++)
	{
		s[k] += w[start][k+1];
		if (s[k] >= 10)
		{
			s[k] -= w[start][k+1];
			return 0;
		}
	}
	
	int result = 1;
	/*for (int p = 1; p <= len; p++)
		cout << w[start][p];
	cout << "\n";*/
	for (int z = 0; z < limit; z++)
	{
		if (w[z][0] != -1)
		{
			int newLen = w[z][0];
			w[z][0] = -1;
			result += count(w, s, z, newLen, limit);
			//w[z][0] = newLen;
		}
	}
	
	return result;
}

int main(void)
{
	ifstream infile;
	infile.open("I.6");
	ofstream outfile ("escape.out");
	char instr[18];
	int N = 0;
	infile.getline(instr, 15);
	N = atoi(instr);
	int weights[N][11];
	//cout << "y\n";
	for (int i = 0; i < N; i++)
	{
		//cout << "yy\n";
		infile.getline(instr, 15);
		//cout << instr << "\n";
		weights[i][0] = strlen(instr);
		//cout << "u\n";
		for (int ii = weights[i][0] - 1; ii >= 0; ii--)
		{
			weights[i][weights[i][0]-ii] = (int) instr[ii] - 48;
			//cout << weights[i][weights[i][0]-ii];
		}
		//cout << "\n";
	}
	//cout << "x\n";
	
	int largest = 0;
	for (int j = 0; j < N; j++)
	{
		int sum[10] = {0};
		int** pW = new int *[N];
		weights[j][0] = -1;
		for (int jj = 0; jj < N; jj++)
		{
			pW[jj] = weights[jj];
			/*for (int jjj = 1; jjj <= weights[jj][0]; jjj++)
				cout << weights[jj][jjj];
			cout << "\n";*/
		}
		int length = weights[j][0];
		int total = count(pW, sum, j, length, N);
		weights[j][0] = length;
		if (total > largest)
			largest = total;
		free(pW);
		//cout << "\n\n";
	}
	
	outfile << largest << "\n";
	infile.close();
	outfile.close();
	
	return 0;
}