#include <iostream>
#include <fstream>
using namespace std;

#define MAXVOLUME 100000

int N, B;

int main(void)
{
	ifstream infile ("mooomoo.in");
	ofstream outfile ("mooomoo.out");
	
	infile >> N >> B;
	
	int* vols = (int*) malloc(sizeof(int) * B);
	for (int b = 0; b < B; b++)
		infile >> vols[b];
	
	int* fields = (int*) malloc(sizeof(int) * N);
	for (int f = 0; f < N; f++)
		infile >> fields[f];
	
	int V[MAXVOLUME+1] = {0};
	for (int i = 1; i <= MAXVOLUME; i++)
	{
		int minimum = -1;
		for (int ii = 0; ii < B; ii++)
		{
			if (i - vols[ii] > 0)
			{
				if (V[i-vols[ii]] > 0)
				{
					if ((V[i-vols[ii]] < minimum) || (minimum == -1))
						minimum = V[i-vols[ii]];
				}
			}
			else if (i - vols[ii] == 0)
			{
				minimum = 0;
				break;
			}
		}
		if (minimum != -1)
			V[i] = minimum + 1;
	}
	
	//cout << V[17] << "\n";
	
	int prev = 0;
	int flag = 0;
	int cows = 0;
	for (int j = 0; j < N; j++)
	{
		if ((fields[j] < prev) || ((fields[j] - prev > 0) && (V[fields[j]-prev] == 0)))
		{
			flag = 1;
			break;
		}
		else
		{
			cows += V[fields[j]-prev];
			//cout << j << " " << fields[j]-prev << " " << V[fields[j]-prev] << "\n";
			if (fields[j] > 0)
				prev = fields[j] - 1;
			else
				prev = 0;
		}
	}
	
	if (flag == 1)
		outfile << "-1\n";
	else
		outfile << cows << "\n";
	
	infile.close();
	outfile.close();
	
	return 0;
}