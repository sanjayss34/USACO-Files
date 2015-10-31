/*
PROB: gift1
LANG: C++
*/
//#include <iostream>
#include <fstream>
#include <cstring>
//#include <cmath>
using namespace std;

/*inline int hashGen(char* name, int len)
{
	int result = 1;
	for (int j = 1; j < strlen(name)+1; j++)
	{
		//result *= 37;
		result += (int) name[j] * (int) pow(10.0, (double) j);
	}
	
	//cout << name << " " << (result % len) << "\n";
	return abs(result) % (len*2);
}*/

int main(void)
{
	ifstream infile;
	infile.open("gift1.in");
	ofstream outfile ("gift1.out");
	char inputN[20];
	infile.getline(inputN, 19);
	const int N = atoi(inputN);
	int amounts[N+1];
	char names[N+1][20];
	int final[11] = {0};
	//cout << "hi " << N << "\n";
	for (int i = 0; i < N; i++)
	{
		infile.getline(inputN, 19);
		strcpy(names[i], inputN);
	}
	
	//cout << "hello again\n";
	
	for (int k = 0; k < N; k++)
	{
		infile.getline(inputN, 19);
		int ind = 0;
		for (int j = 0; j < N; j++)
		{
			if (strcmp(inputN, names[j]) == 0)
			{
				ind = j;
				break;
			}
		}
		//cout << inputN << " ";
		//cout << "hi\n";
		infile.getline(inputN, 19);
		//cout << inputN << "\n";
		/*if (k == 4)
			cout << inputN << "\n";*/
		amounts[ind] = atoi(strtok(inputN, " "));
		//cout << "hi2\n";
		int lim = atoi(strtok(NULL, " "));
		if (lim != 0)
		{
			final[ind] += amounts[ind]%lim;
			for (int kk = 0; kk < lim; kk++)
			{
				infile.getline(inputN, 19);
				for (int kkk = 0; kkk < N; kkk++)
				{
					if (strcmp(names[kkk], inputN) == 0)
					{
						final[kkk] += amounts[ind]/lim;
						//cout << names[kkk] << " " << final[kkk] << "\n";
						break;
					}
				}
			}
		}
		else
			final[ind] += amounts[ind];
		//cout << names[ind] << "1 " << final[ind] << "\n";
	}
	//cout << hashGen(names[7], N*(N-1)) << " " << hashGen(names[9], N*(N-1)) << "\n";
	for (int z = 0; z < N; z++)
	{
		outfile << names[z] << " " << (final[z]-amounts[z]) << "\n";
		//outfile << names[z] << " " << amounts[zInd] << " " << final[zInd] << " " << (final[zInd] - amounts[zInd]) << "\n";
	}
	
	infile.close();
	outfile.close();
	
	return 0;
}