#include <fstream>
//#include <iostream>
#include <cmath>
using namespace std;

int place(int p, int* arr, int plus, int lim)
//int place(int p, int* r, int* arr)
{
	if ((p >= 0) && (p < lim) && (arr[p] == -1))
	{
		//arr[p] = 1;
		return p;
	}
// 	else if (plus < 0)
// 	{
// 		return place(p+plus, arr, (-1*plus)+1);
// 	}
	return place(p+plus, arr, -1*(plus+1), lim);
	
	/*if (r[p] == -1)
		return p;
	int flag = 0;
	int original = p;
	int temp = arr[p-1];
	while (flag == 0)
	{
		temp = arr[p-1];
		arr[p-1] = arr[p];
		if (r[temp] == -1)
			flag = 1;
		p--;
	}
	
	return original;*/
}

int main(void)
{
	ifstream infile;
	infile.open("haywire.in");
	ofstream outfile ("haywire.out");
	int N = 0;
	infile >> N;
	int weights[N];
	int placement[N];
	int range[N];
	int friends[N][3];
	int cost = 0;
	for (int j = 0; j < N; j++)
	{
		range[j] = -1;
		weights[j] = ((N-1)/2);
	}
	//cout << "a\n";
	for (int i = 0; i < N; i++)
	{
		//cout << "b\n";
		placement[i] = place(weights[i], range, 1, N);
		//placement[i] = place(weights[i], range, placement);
		range[placement[i]] = i;
		infile >> friends[i][0] >> friends[i][1] >> friends[i][2];
		//cout << "bb\n";
		friends[i][0]--;
		friends[i][1]--;
		friends[i][2]--;
		if (i > friends[i][0])
			friends[i][0] = -1;
		if (i > friends[i][1])
			friends[i][1] = -1;
		if (i > friends[i][2])
			friends[i][2] = -1;
		for (int ii = 0; ii < 3; ii++)
		{
			if (friends[i][ii] >= 0)
			{
				weights[friends[i][ii]] += placement[i] - ((N-1)/2);
				if (weights[friends[i][ii]] < 0)
					weights[friends[i][ii]] = 0;
				else if (weights[friends[i][ii]] >= N)
					weights[friends[i][ii]] = N-1;
			}
		}
	}
	//cout << "c\n";
	//cout << weights[3] << "\n";
	
	for (int k = 0; k < N; k++)
	{
		//cout << range[k]+1 << " ";
		for (int kk = 0; kk < 3; kk++)
		{
			if (friends[k][kk] >= 0)
			{
				/*if ((placement[k] > N) || (placement[friends[k][kk]] < (-1*N)))
					cout << k << "\n\n";*/
				cost += abs(placement[k]-placement[friends[k][kk]]);
			}
		}
	}
	
	outfile << cost << "\n";
	
	infile.close();
	outfile.close();
	
	return 0;
}